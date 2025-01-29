/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_handler_movement.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madelvin <madelvin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 21:08:51 by madelvin          #+#    #+#             */
/*   Updated: 2025/01/29 14:38:43 by madelvin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <X11/keysym.h>

int	mouse_down(int keycode, int x, int y, t_scene *scene)
{
	scene->mouse.mouse_last_x = x;
	scene->mouse.mouse_last_y = y;
	if (keycode == 4 || keycode == 5)
		zoom(scene, keycode);
	else if (keycode == 1)
	{
		if (x >= 110 && x <= 190 && y >= 500 && y <= 515)
			init_cam(scene, scene->map.map_height, scene->map.map_width);
		else
			scene->mouse.mouse_click_rotation = 1;
	}
	else if (keycode == 3)
		scene->mouse.mouse_click_translation = 1;
	return (0);
}

int	mouse_up(int keycode, int x, int y, t_scene *scene)
{
	scene->mouse.mouse_last_x = x;
	scene->mouse.mouse_last_y = y;
	if (keycode == 1)
		scene->mouse.mouse_click_rotation = 0;
	else if (keycode == 3)
		scene->mouse.mouse_click_translation = 0;
	return (0);
}

int	mouse_move(int x, int y, t_scene *scene)
{
	if (scene->mouse.mouse_click_rotation)
		rotate(x, y, scene);
	if (scene->mouse.mouse_click_translation)
		translate(x, y, scene);
	scene->mouse.mouse_last_x = x;
	scene->mouse.mouse_last_y = y;
	return (0);
}

int	key_hook(int keycode, t_scene *scene)
{
	if (keycode == XK_Escape)
		close_window(scene);
	else
		select_movement(keycode, scene);
	return (0);
}