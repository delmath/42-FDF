/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madelvin <madelvin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 16:08:48 by madelvin          #+#    #+#             */
/*   Updated: 2025/01/29 14:59:52 by madelvin         ###   ########.fr       */
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
		cam->coord.x -= 20;
		cam->coord.y -= 30;
		cam->distance = sqrt(map_width + map_height) + 50;
	}
	if (map_size >= 50 && map_size < 300)
	{
		cam->coord.x -= 10;
		cam->coord.y -= 20;
		cam->distance = sqrt(map_width + map_height) + 20;
	}
	if (map_size >= 300)
		cam->distance = sqrt(map_width + map_height);
}

void	init_cam(t_scene *scene, int map_height, int map_width)
{
	t_camera	*cam;

	cam = &scene->camera;
	cam->fov = 60;
	cam->pitch = atan(sqrt(2.0));
	cam->yaw = -PI / 4.0;
	cam->roll = 0;
	cam->coord.x = map_width / 2;
	cam->coord.y = map_height / 2;
	cam->coord.z = 0;
	cam->clipping_planes.znear = 1;
	cam->clipping_planes.zfar = 100000;
	cam->clipping_planes.near = 0;
	cam->clipping_planes.far = 0;
	cam->focal = 1 / (tan(cam->fov * (PI / 180) / 2));
	init_cam_location(cam, map_height, map_height);
	cam->min_zoom = 120;
	cam->max_zoom = log(map_width * map_height) / 2;
	calc_axis_value(cam);
	calc_proj_coord(scene);
}

void	init_mouse(t_mouse *mouse)
{
	mouse->mouse_sensibility = 0.001;
	mouse->mouse_last_x = 0;
	mouse->mouse_last_y = 0;
	mouse->mouse_click_rotation = 0;
	mouse->mouse_click_translation = 0;
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
	init_cam(scene, scene->map.map_height, scene->map.map_width);
	init_proj(&scene->proj, scene->map.map_width);
	init_mouse(&scene->mouse);
	scene->param.z_ratio = 0;
	scene->param.persp = 0;
	scene->param.iso = 1;
	scene->param.transform = DEFAULT;
	scene->param.scale = (W_WIDTH / (scene->camera.distance / 10)
			/ sqrt(scene->map.map_height * scene->map.map_width));
	calc_ortho_matrix(scene);
	calc_persp_matrix(scene);
	scene->map.point_list = malloc(sizeof(t_coord)
			* scene->map.map_width * scene->map.map_height);
	if (!scene->map.point_list || !scene->map.map)
		exit_handler(1, NULL, scene);
}
