/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_manager.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madelvin <madelvin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 16:01:00 by madelvin          #+#    #+#             */
/*   Updated: 2025/03/19 17:51:20 by madelvin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"
#include <mlx.h>
#include <stdlib.h>

void	stop_mlx(t_scene *scene)
{
	mlx_destroy_window(scene->mlx, scene->win);
	mlx_destroy_display(scene->mlx);
	free(scene->win_data.name);
	free(scene->mlx);
	free(scene->map.map);
	free(scene->map.point_list);
}

void	init_hook(t_scene *scene)
{
	mlx_key_hook(scene->win, key_hook, scene);
	mlx_hook(scene->win, 17, 0, close_window, scene);
	mlx_hook(scene->win, 4, 1L << 2, mouse_down, scene);
	mlx_hook(scene->win, 5, 1L << 3, mouse_up, scene);
	mlx_hook(scene->win, 6, 1L << 6, mouse_move, scene);
	mlx_loop_hook(scene->mlx, render_frame, scene);
	mlx_loop(scene->mlx);
}

int	init_mlx(t_scene *scene)
{
	char	*name;

	scene->win_data.width = W_WIDTH;
	scene->win_data.height = W_HEIGHT;
	name = ft_strjoin("fdf - ", ft_strrchr(scene->file, '/') + 1);
	if (!name)
		exit_handler(1, NULL, scene);
	scene->win_data.name = name;
	scene->mlx = mlx_init();
	if (!scene->mlx)
	{
		free(name);
		exit_handler(1, NULL, scene);
	}
	scene->win = mlx_new_window(scene->mlx, scene->win_data.width,
			scene->win_data.height, scene->win_data.name);
	scene->img.img_ptr = mlx_new_image(scene->mlx, scene->win_data.width, scene->win_data.height);
	scene->img.px_ptr = mlx_get_data_addr(scene->img.img_ptr, &scene->img.bpp, &scene->img.line_len, &scene->img.endian);
	scene->img.bpp /= 8;
	init_hook(scene);
	stop_mlx(scene);
	return (0);
}
