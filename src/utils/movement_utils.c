/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madelvin <madelvin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 20:45:03 by madelvin          #+#    #+#             */
/*   Updated: 2025/01/29 14:50:56 by madelvin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>

void	zoom(t_scene *scene, int direction)
{
	if (direction == 4 && scene->camera.distance > scene->camera.max_zoom)
		scene->camera.distance -= 1;
	else if (direction == 5 && scene->camera.distance < scene->camera.min_zoom)
		scene->camera.distance += 1;
	scene->param.scale = (W_WIDTH / (scene->camera.distance / 10)
			/ sqrt(scene->map.map_height * scene->map.map_width));
	calc_proj_coord(scene);
}

void	translate(int x, int y, t_scene *scene)
{
	int	dx;
	int	dy;

	dx = x - scene->mouse.mouse_last_x;
	dy = y - scene->mouse.mouse_last_y;
	if (scene->camera.pitch < 0)
		dy = -dy;
	if (scene->camera.roll < 0)
		dx = -dx;
	scene->camera.coord.x -= dy * (scene->mouse.mouse_sensibility
			* sqrt(scene->map.map_height * scene->map.map_width));
	scene->camera.coord.y -= dy * (scene->mouse.mouse_sensibility
			* sqrt(scene->map.map_height * scene->map.map_width));
	scene->camera.coord.x -= dx * (scene->mouse.mouse_sensibility
			* sqrt(scene->map.map_height * scene->map.map_width));
	scene->camera.coord.y += dx * (scene->mouse.mouse_sensibility
			* sqrt(scene->map.map_height * scene->map.map_width));
	scene->camera.coord.z -= dx * (scene->mouse.mouse_sensibility
			* sqrt(scene->map.map_height * scene->map.map_width));
	scene->camera.coord.z -= dy * (scene->mouse.mouse_sensibility
			* sqrt(scene->map.map_height * scene->map.map_width));
	calc_axis_value(&scene->camera);
	calc_proj_coord(scene);
}

void	rotate(int x, int y, t_scene *scene)
{
	int	dx;
	int	dy;

	dx = x - scene->mouse.mouse_last_x;
	dy = y - scene->mouse.mouse_last_y;
	scene->camera.pitch += dy * scene->mouse.mouse_sensibility;
	scene->camera.roll += dx * scene->mouse.mouse_sensibility;
	calc_axis_value(&scene->camera);
	calc_proj_coord(scene);
}
