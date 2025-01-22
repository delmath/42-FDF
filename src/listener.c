/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listener.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madelvin <madelvin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 16:00:48 by madelvin          #+#    #+#             */
/*   Updated: 2025/01/22 17:16:26 by madelvin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <X11/keysym.h>
#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>

//mouvement

//mouvement

int	mouse_hook(int keycode, t_scene *scene)
{
	(void)keycode;
	(void)scene;
	printf("mouse\n");
	return (0);
}

int	key_hook(int keycode, t_scene *scene)
{
	if (keycode == XK_Escape)
		close_window(scene);
	// if (keycode == XK_W || keycode == XK_w)
	// 	fdf->camera->y = fdf->camera->y + 0.1;
	// if (keycode == XK_S || keycode == XK_s)
	// 	fdf->camera->y = fdf->camera->y - 0.1;
	// if (keycode == XK_D || keycode == XK_d)
	// 	fdf->camera->x = fdf->camera->x + 0.1;
	// if (keycode == XK_A || keycode == XK_a)
	// 	fdf->camera->x = fdf->camera->x - 0.1;
	// if (keycode == XK_Q || keycode == XK_q)
	// 	fdf->camera->z = fdf->camera->z + 0.1;
	// if (keycode == XK_E || keycode == XK_e)
	// 	fdf->camera->z = fdf->camera->z - 0.1;
	// if (keycode == XK_i)
	// 	fdf->camera->pitch = fdf->camera->pitch + 0.01;
	// if (keycode == XK_k)
	// 	fdf->camera->pitch = fdf->camera->pitch - 0.01;
	// if (keycode == XK_j)
	// 	fdf->camera->yaw = fdf->camera->yaw + 0.01;
	// if (keycode == XK_l)
	// 	fdf->camera->yaw = fdf->camera->yaw - 0.01;
	// if (keycode == XK_u)
	// 	fdf->camera->roll = fdf->camera->roll + 0.01;
	// if (keycode == XK_o)
	// 	fdf->camera->roll = fdf->camera->roll - 0.01;
	// if (keycode == XK_y)
	// 	fdf->param->z_ratio = fdf->param->z_ratio + 0.01;
	// if (keycode == XK_h)
	// 	fdf->param->z_ratio = fdf->param->z_ratio - 0.01;
	// if (keycode == XK_t)
	// 	fdf->param->size = fdf->param->size + 0.1;
	// if (keycode == XK_g)
	// 	fdf->param->size = fdf->param->size - 0.1;
	else
		printf("keyboard :%d\n", keycode);
	return (0);
}

int	close_window(t_scene *scene)
{
	mlx_loop_end(scene->mlx);
	return (0);
}

int	render_frame(t_scene *scene)
{
	if (scene->render == 0)
	{
		init_map(scene);
		scene->render = 1;
	}
	// t_img img;

	// img = calcule_frame(fdf);
	// printf("Cam : %f;%f:%f | %f;%f;%f\n", scene->camera->x, fdf->camera->y, fdf->camera->z, fdf->camera->pitch, fdf->camera->yaw, fdf->camera->roll);
	// mlx_destroy_image(scene->mlx, img.img_ptr);
	return (0);
}
