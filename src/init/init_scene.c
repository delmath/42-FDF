/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madelvin <madelvin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 16:08:48 by madelvin          #+#    #+#             */
/*   Updated: 2025/01/30 19:12:40 by madelvin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>
#include <stdlib.h>

void	init_cam_location(t_camera *cam, int map_height, int map_width)
{
	int	map_size;

	map_size = sqrt(map_height * map_width);
	if (map_size < 50)
	{
		cam->coord.x -= 35;
		cam->coord.y += 40;
		cam->distance = sqrt(map_width + map_height) + 50;
	}
	if (map_size >= 50 && map_size < 300)
		cam->distance = sqrt(map_width + map_height) + 20;
	if (map_size >= 300)
		cam->distance = sqrt(map_width + map_height);
}

void	init_cam(t_scene *scene, int map_height, int map_width)
{
	t_camera	*cam;

	cam = &scene->camera;
	cam->fov = 60;
	cam->pitch = -PI_F / 4;
	cam->yaw = PI_F / 4;
	cam->roll = 0;
	cam->coord.x = map_width / 2;
	cam->coord.y = map_height / 2;
	cam->coord.z = 0;
	cam->clipping_planes.znear = 1;
	cam->clipping_planes.zfar = 1000;
	cam->clipping_planes.near = 0;
	cam->clipping_planes.far = 0;
	cam->focal = 1 / (tan(cam->fov * (PI_F / 180) / 2));
	init_cam_location(cam, map_height, map_height);
	cam->min_zoom = 120;
	cam->max_zoom = log(map_width * map_height) / 2;
}

void	init_mouse(t_mouse *mouse)
{
	mouse->mouse_sensi = 0.001;
	mouse->mouse_last_x = 0;
	mouse->mouse_last_y = 0;
	mouse->mouse_click_rotation = 0;
	mouse->mouse_click_translation = 0;
	mouse->mouse_click_wheel = 0;
}

void	init_proj(t_proj *proj, int map_width)
{
	proj->left = 0;
	proj->right = map_width;
	proj->bottom = 0;
	proj->top = 100;
}

void	init_scene(t_scene *scene, char *file)
{
	scene->file = file;
	init_map(scene);
	if (scene->map.map_height == 0 || scene->map.map_width == 0)
		exit_handler(1, file, scene);
	init_cam(scene, scene->map.map_height, scene->map.map_width);
	init_proj(&scene->proj, scene->map.map_width);
	init_mouse(&scene->mouse);
	scene->param.z_ratio = 0.5;
	scene->param.persp = 0;
	scene->param.iso = 1;
	scene->param.z_order = 0;
	scene->param.selected = 0;
	scene->param.transform = DEFAULT;
	scene->param.color_preset = 4;
	scene->param.scale = (W_WIDTH / (scene->camera.distance / 10)
			/ sqrt(scene->map.map_height * scene->map.map_width));
	calc_ortho_matrix(scene);
	calc_persp_matrix(scene);
	scene->map.point_list = malloc(sizeof(t_coord)
			* scene->map.map_width * scene->map.map_height);
	if (!scene->map.point_list || !scene->map.map)
		exit_handler(1, NULL, scene);
	calc_axis_value(&scene->camera);
	calc_proj_coord(scene);
}
