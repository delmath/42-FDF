/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madelvin <madelvin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 20:45:03 by madelvin          #+#    #+#             */
/*   Updated: 2025/01/30 19:03:23 by madelvin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>

void	zoom(t_scene *scene, int direction)
{
	if (direction == 0)
		scene->camera.distance += 0;
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
	int		dx;
	int		dy;
	float	move_speed;

	dx = x - scene->mouse.mouse_last_x;
	dy = y - scene->mouse.mouse_last_y;
	if (scene->camera.pitch > 0)
		dy = -dy;
	if (scene->camera.yaw < 0)
		dx = -dx;
	move_speed = scene->mouse.mouse_sensi
		* sqrt(scene->map.map_height * scene->map.map_width);
	scene->camera.coord.x -= dy * move_speed * cos(scene->camera.yaw);
	scene->camera.coord.y -= dy * move_speed * sin(scene->camera.yaw);
	scene->camera.coord.x += dx * move_speed
		* cos(scene->camera.yaw + PI_F / 2);
	scene->camera.coord.y += dx * move_speed
		* sin(scene->camera.yaw + PI_F / 2);
	calc_axis_value(&scene->camera);
	calc_proj_coord(scene);
}

void	rotate(int x, int y, t_scene *scene)
{
	int	dx;
	int	dy;

	dx = x - scene->mouse.mouse_last_x;
	dy = y - scene->mouse.mouse_last_y;
	scene->camera.pitch -= (dx * scene->mouse.mouse_sensi);
	scene->camera.yaw += (dy * scene->mouse.mouse_sensi);
	calc_axis_value(&scene->camera);
	calc_proj_coord(scene);
}
