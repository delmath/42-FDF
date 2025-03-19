/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_calc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madelvin <madelvin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 22:00:01 by madelvin          #+#    #+#             */
/*   Updated: 2025/03/19 17:48:34 by madelvin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"
#include <mlx.h>

void	add_transform(float point[4], t_scene *scene, int i)
{
	if (scene->param.transform == DEFAULT)
		return ;
	if (scene->param.transform == SPHERE)
		transform_to_spherical(point, scene, i);
	if (scene->param.transform == TORUS)
		transform_to_torus(point, scene, i);
}

void	apply_cam_and_transform(float point[4], t_scene *scene, int i)
{
	point[0] = scene->map.map[i].x;
	point[1] = scene->map.map[i].y;
	point[2] = scene->map.map[i].z;
	point[0] -= scene->camera.proj_coord.x;
	point[1] -= scene->camera.proj_coord.y;
	point[2] = (-point[2] - scene->camera.proj_coord.z) * scene->param.z_ratio;
	point[3] = 1;
	add_transform(point, scene, i);
	multiply_matrix_vector_3d(scene->camera.axes_matrix, point);
	scene->map.point_list[i].colors = scene->map.map[i].colors;
	scene->map.point_list[i].default_z = scene->map.map[i].z
		* scene->param.z_ratio;
	if ((scene->map.map[i].z * scene->param.z_ratio) > scene->map.map_max_z)
		scene->map.map_max_z = (scene->map.map[i].z * scene->param.z_ratio);
	if ((scene->map.map[i].z * scene->param.z_ratio) < scene->map.map_min_z)
		scene->map.map_min_z = (scene->map.map[i].z * scene->param.z_ratio);
}

void	calc_point(t_scene *scene, int i)
{
	float	point[4];

	apply_cam_and_transform(point, scene, i);
	if (scene->param.iso)
	{
		scene->map.point_list[i].x = (int)((point[0] * scene->param.scale
					+ W_WIDTH / 2) + 170);
		scene->map.point_list[i].y = (int)(point[1] * scene->param.scale
				+ W_HEIGHT / 2);
		scene->map.point_list[i].z = 1;
		return ;
	}
	if (scene->param.persp == 1)
		multiply_matrix_vector_4d(scene->proj.persp_matrix, point);
	else
		multiply_matrix_vector_4d(scene->proj.ortho_matrix, point);
	point[0] = point[0] / point[3];
	point[1] = point[1] / point[3];
	if (point[2] < 0 && point[3] < 0)
		point[2] = -(point[2] / point[3]);
	else
		point[2] = point[2] / point[3];
	scene->map.point_list[i].x = (int)(((point[0] + 1) / 2) * W_WIDTH);
	scene->map.point_list[i].y = (int)(((1 - point[1]) / 2) * W_HEIGHT);
	scene->map.point_list[i].z = point[2];
}

void	calc_all_point_projection(t_scene *scene, t_img img)
{
	int		i;
	int		line_len;
	int		map_len;

	line_len = scene->map.map_width;
	map_len = line_len * scene->map.map_height;
	scene->map.map_max_z = -2147483648;
	scene->map.map_min_z = 2147483647;
	i = -1;
	while (++i < W_HEIGHT * 300)
		*((unsigned int *)(((img.line_len * (i / 300)) + ((i % 300) * img.bpp))
			+ img.px_ptr)) = MENU_BACKGROUND;
	i = -1;
	while (++i < map_len)
		calc_point(scene, i);
	i = -1;
	while (++i < map_len)
	{
		if (i % line_len < line_len - 1)
			draw_line(img, scene->map.point_list[i],
				scene->map.point_list[i + 1], *scene);
		if (i + line_len < map_len)
			draw_line(img, scene->map.point_list[i],
				scene->map.point_list[i + line_len], *scene);
	}
}

t_img	calcule_frame(t_scene *scene)
{
	ft_bzero(scene->img.px_ptr, scene->win_data.width *  scene->win_data.height * (scene->img.bpp));
	calc_all_point_projection(scene, scene->img);
	draw_reset_button(scene->img);
	mlx_put_image_to_window(scene->mlx, scene->win, scene->img.img_ptr, 0, 0);
	return (scene->img);
}
