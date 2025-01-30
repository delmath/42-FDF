/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_handler_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madelvin <madelvin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 21:00:26 by madelvin          #+#    #+#             */
/*   Updated: 2025/01/30 18:58:46 by madelvin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <X11/keysym.h>

static int	change_transform(int actual)
{
	if (actual == SPHERE)
		return (1);
	else
		return (actual + 1);
}

static void	projection_change(int keycode, t_scene *scene)
{
	if (keycode == XK_p && scene->param.persp == 1 && scene->param.iso == 0)
		scene->param.persp = 0;
	else if (keycode == XK_p && scene->param.persp == 0
		&& scene->param.iso == 0)
		scene->param.persp = 1;
	if (keycode == XK_t && scene->param.iso == 1)
		scene->param.transform = change_transform(scene->param.transform);
	if (keycode == XK_i && scene->param.iso == 1
		&& scene->param.transform == DEFAULT)
	{
		scene->param.iso = 0;
		scene->camera.yaw = 0;
		scene->camera.pitch = 0;
		scene->camera.roll = 0;
	}
	else if (keycode == XK_i && scene->param.iso == 0
		&& scene->param.persp == 0)
	{
		scene->param.iso = 1;
		init_cam(scene, scene->map.map_height, scene->map.map_width);
	}
}

static void	param_modifier(int keycode, t_scene *scene)
{
	if (keycode == XK_KP_Add && scene->param.selected == 0)
		scene->param.z_ratio += 0.1;
	if (keycode == XK_KP_Subtract && scene->param.selected == 0)
		scene->param.z_ratio -= 0.1;
	if (keycode == XK_KP_Add && scene->param.selected == 1)
		scene->camera.clipping_planes.near += 10;
	if (keycode == XK_KP_Subtract && scene->param.selected == 1)
		scene->camera.clipping_planes.near -= 10;
	if (keycode == XK_KP_Add && scene->param.selected == 2)
		scene->camera.clipping_planes.far += 10;
	if (keycode == XK_KP_Subtract && scene->param.selected == 2)
		scene->camera.clipping_planes.far -= 10;
	if (keycode == XK_KP_Add && scene->param.selected == 3)
		scene->camera.clipping_planes.znear += 10;
	if (keycode == XK_KP_Subtract && scene->param.selected == 3)
		scene->camera.clipping_planes.znear -= 10;
	if (keycode == XK_KP_Add && scene->param.selected == 4)
		scene->camera.clipping_planes.zfar += 10;
	if (keycode == XK_KP_Subtract && scene->param.selected == 4)
		scene->camera.clipping_planes.zfar -= 10;
}

static void	param_reset(int keycode, t_scene *scene)
{
	if (keycode == XK_r && scene->param.selected == 0)
		scene->param.z_ratio = 0.5f;
	if (keycode == XK_r && scene->param.selected == 1)
		scene->camera.clipping_planes.near = 0;
	if (keycode == XK_r && scene->param.selected == 2)
		scene->camera.clipping_planes.far = 0;
	if (keycode == XK_r && scene->param.selected == 3)
		scene->camera.clipping_planes.znear = 1;
	if (keycode == XK_r && scene->param.selected == 4)
		scene->camera.clipping_planes.zfar = 1000;
	if (keycode == XK_r && scene->param.selected == 5)
		scene->mouse.mouse_sensi = 0.001;
}

void	select_movement(int keycode, t_scene *scene)
{
	param_modifier(keycode, scene);
	projection_change(keycode, scene);
	param_reset(keycode, scene);
	if ((keycode == XK_KP_Add || keycode == XK_KP_Subtract)
		&& (scene->param.selected == 5 || scene->param.selected == 4))
		calc_persp_matrix(scene);
	if ((keycode == XK_KP_Add || keycode == XK_KP_Subtract)
		&& (scene->param.selected == 3 || scene->param.selected == 2))
		calc_ortho_matrix(scene);
	if (keycode == XK_KP_Add && scene->param.selected == 5)
		scene->mouse.mouse_sensi += 0.001;
	if (keycode == XK_KP_Subtract && scene->param.selected == 5
		&& scene->mouse.mouse_sensi > 0.001)
		scene->mouse.mouse_sensi -= 0.001;
	if (keycode == XK_Up && scene->param.selected > 0)
		scene->param.selected -= 1;
	if (keycode == XK_Down && scene->param.selected < 5)
		scene->param.selected += 1;
	if (keycode == XK_c && scene->param.color_preset < 4)
		scene->param.color_preset += 1;
	else if (keycode == XK_c && scene->param.color_preset == 4)
		scene->param.color_preset = 0;
	calc_axis_value(&scene->camera);
	calc_proj_coord(scene);
}
