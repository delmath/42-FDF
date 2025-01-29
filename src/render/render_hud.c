/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_hud.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madelvin <madelvin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 20:45:38 by madelvin          #+#    #+#             */
/*   Updated: 2025/01/29 22:38:41 by madelvin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"
#include <mlx.h>
#include <stdlib.h>

static void	put_selection_arrow(void *mlx, void *win, t_scene *scene)
{
	if (scene->param.selected == 0)
		mlx_string_put(mlx, win, 250, 350, COLOR_JAFFA, "<-");
	if (scene->param.selected == 1)
		mlx_string_put(mlx, win, 250, 370, COLOR_JAFFA, "<-");
	if (scene->param.selected == 2)
		mlx_string_put(mlx, win, 250, 390, COLOR_JAFFA, "<-");
	if (scene->param.selected == 3)
		mlx_string_put(mlx, win, 250, 410, COLOR_JAFFA, "<-");
	if (scene->param.selected == 4)
		mlx_string_put(mlx, win, 250, 430, COLOR_JAFFA, "<-");
	if (scene->param.selected == 5)
		mlx_string_put(mlx, win, 250, 450, COLOR_JAFFA, "<-");
	if (scene->param.selected == 6)
		mlx_string_put(mlx, win, 250, 470, COLOR_JAFFA, "<-");
}

static void	put_modifier_info(void *mlx, void *win, t_scene *scene)
{
	mlx_string_put(mlx, win, 25, 50, TEXT_COLOR, "selected modifier:");
	mlx_string_put(mlx, win, 30, 70, TEXT_COLOR, "- selected transform: ");
	mlx_string_put(mlx, win, 165, 70, INFO_COLOR,
		get_transform(scene->param.transform));
	mlx_string_put(mlx, win, 30, 90, TEXT_COLOR, "- selected projection: ");
	mlx_string_put(mlx, win, 165, 90, INFO_COLOR,
		get_projection(scene->param.persp));
	mlx_string_put(mlx, win, 30, 110, TEXT_COLOR, "- iso enable: ");
	mlx_string_put(mlx, win, 165, 110, INFO_COLOR,
		get_iso(scene->param.iso));
}

static void	put_cam_info(void *mlx, void *win, t_scene *scene, char **temp)
{
	mlx_string_put(mlx, win, 25, 160, TEXT_COLOR, "camera info:");
	mlx_string_put(mlx, win, 30, 180, TEXT_COLOR, "- camera x: ");
	mlx_string_put(mlx, win, 165, 180, INFO_COLOR,
		get_hud_value(temp, ft_itoa(scene->camera.coord.x)));
	mlx_string_put(mlx, win, 30, 200, TEXT_COLOR, "- camera y: ");
	mlx_string_put(mlx, win, 165, 200, INFO_COLOR,
		get_hud_value(temp, ft_itoa(scene->camera.coord.y)));
	mlx_string_put(mlx, win, 30, 220, TEXT_COLOR, "- camera z: ");
	mlx_string_put(mlx, win, 165, 220, INFO_COLOR,
		get_hud_value(temp, ft_itoa(scene->camera.coord.z)));
	mlx_string_put(mlx, win, 30, 240, TEXT_COLOR, "- camera pitch: ");
	mlx_string_put(mlx, win, 165, 240, INFO_COLOR,
		get_hud_value(temp, ft_itoa(scene->camera.pitch * 1000)));
	mlx_string_put(mlx, win, 30, 260, TEXT_COLOR, "- camera yaw: ");
	mlx_string_put(mlx, win, 165, 260, INFO_COLOR,
		get_hud_value(temp, ft_itoa(scene->camera.yaw * 1000)));
	mlx_string_put(mlx, win, 30, 280, TEXT_COLOR, "- camera roll: ");
	mlx_string_put(mlx, win, 165, 280, INFO_COLOR,
		get_hud_value(temp, ft_itoa(scene->camera.roll * 1000)));
	mlx_string_put(mlx, win, 30, 300, TEXT_COLOR, "- camera zoom: ");
	mlx_string_put(mlx, win, 165, 300, INFO_COLOR,
		get_hud_value(temp, ft_itoa(scene->camera.distance)));
}

static void	put_param_info(void *mlx, void *win, t_scene *scene, char **temp)
{
	mlx_string_put(mlx, win, 25, 330, TEXT_COLOR, "fdf info:");
	mlx_string_put(mlx, win, 30, 350, TEXT_COLOR, "- z_order:");
	mlx_string_put(mlx, win, 165, 350, INFO_COLOR,
		get_hud_value(temp, ft_itoa(scene->param.z_order)));
	mlx_string_put(mlx, win, 30, 370, TEXT_COLOR, "- z_ratio:");
	mlx_string_put(mlx, win, 165, 370, INFO_COLOR,
		get_hud_value(temp, ft_itoa(scene->param.z_ratio * 10)));
	mlx_string_put(mlx, win, 30, 390, TEXT_COLOR, "- near:");
	mlx_string_put(mlx, win, 165, 390, INFO_COLOR,
		get_hud_value(temp, ft_itoa(scene->camera.clipping_planes.near)));
	mlx_string_put(mlx, win, 30, 410, TEXT_COLOR, "- far:");
	mlx_string_put(mlx, win, 165, 410, INFO_COLOR,
		get_hud_value(temp, ft_itoa(scene->camera.clipping_planes.far)));
	mlx_string_put(mlx, win, 30, 430, TEXT_COLOR, "- z_near:");
	mlx_string_put(mlx, win, 165, 430, INFO_COLOR,
		get_hud_value(temp, ft_itoa(scene->camera.clipping_planes.znear)));
	mlx_string_put(mlx, win, 30, 450, TEXT_COLOR, "- z_far:");
	mlx_string_put(mlx, win, 165, 450, INFO_COLOR,
		get_hud_value(temp, ft_itoa(scene->camera.clipping_planes.zfar)));
	mlx_string_put(mlx, win, 30, 470, TEXT_COLOR, "- mouse sensi:");
	mlx_string_put(mlx, win, 165, 470, INFO_COLOR,
		get_hud_value(temp, ft_itoa(scene->mouse.mouse_sensi * 1000)));
}

void	render_hud(t_scene *scene)
{
	void	*mlx;
	void	*win;
	char	*temp;

	temp = NULL;
	mlx = scene->mlx;
	win = scene->win;
	mlx_string_put(mlx, win, 20, 20, TEXT_COLOR, scene->win_data.name);
	put_modifier_info(mlx, win, scene);
	put_cam_info(mlx, win, scene, &temp);
	put_param_info(mlx, win, scene, &temp);
	if (temp)
		free(temp);
	mlx_string_put(mlx, win, 136, 511, TEXT_COLOR, "reset");
	put_selection_arrow(mlx, win, scene);
}
