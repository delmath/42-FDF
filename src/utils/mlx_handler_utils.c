/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_handler_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madelvin <madelvin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 21:00:26 by madelvin          #+#    #+#             */
/*   Updated: 2025/01/28 21:04:28 by madelvin         ###   ########.fr       */
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

void	select_movement(int keycode, t_scene *scene) // add le near far / znear zfar
{
	if (keycode == XK_w && scene->param.iso == 0)
		scene->camera.coord.x += 1;
	if (keycode == XK_s && scene->param.iso == 0)
		scene->camera.coord.x -= 1;
	if (keycode == XK_a && scene->param.iso == 0)
		scene->camera.coord.y += 1;
	if (keycode == XK_d && scene->param.iso == 0)
		scene->camera.coord.y -= 1;
	if (keycode == XK_q && scene->param.iso == 0)
		scene->camera.coord.z += 1;
	if (keycode == XK_e && scene->param.iso == 0)
		scene->camera.coord.z -= 1;
	if (keycode == XK_t)
		scene->param.transform = change_transform(scene->param.transform);
	if (keycode == XK_y)
	{
		scene->param.z_ratio += 0.1;
		scene->camera.coord.x += 3;
		scene->camera.coord.y += 3;
	}
	if (keycode == XK_h)
	{
		scene->param.z_ratio -= 0.1;
		scene->camera.coord.x -= 3;
		scene->camera.coord.y -= 3;
	}
	if (keycode == XK_p && scene->param.persp == 1)
		scene->param.persp = 0;
	else if (keycode == XK_p && scene->param.persp == 0)
		scene->param.persp = 1;
	if (keycode == XK_i && scene->param.iso == 1)
		scene->param.iso = 0;
	else if (keycode == XK_i && scene->param.iso == 0)
		scene->param.iso = 1;
	calc_proj_coord(scene);
	calc_axis_value(&scene->camera);
}
