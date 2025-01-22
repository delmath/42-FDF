/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_manager.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madelvin <madelvin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 16:01:00 by madelvin          #+#    #+#             */
/*   Updated: 2025/01/22 16:31:42 by madelvin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "fdf.h"
#include "libft.h"

void	stop_mlx(t_scene *scene)
{
	mlx_destroy_window(scene->mlx, scene->win);
	mlx_destroy_display(scene->mlx);
	free(scene->win_data.name);
	free(scene->mlx);
}

int	init_mlx(t_scene *scene, char *map_path)
{
	char	*name;

	scene->win_data.width = W_WIDTH;
	scene->win_data.height = W_HEIGHT;
	name = ft_strjoin("fdf - ", ft_strrchr(map_path, '/') + 1);
	if (!name)
		return (1);
	scene->win_data.name = name;
	scene->mlx = mlx_init();
	if (!scene->mlx)
	{
		free(name);
		return (1);
	}
	scene->render = 0;
	scene->file = map_path;
	scene->win = mlx_new_window(scene->mlx, scene->win_data.width, scene->win_data.height, scene->win_data.name);
	mlx_key_hook(scene->win, key_hook, scene);
	mlx_mouse_hook(scene->win, mouse_hook, scene);
	mlx_hook(scene->win, 17, 0, close_window, scene);
	// mlx_hook(env->mlx_win, 4, 1L << 2, mouse_down, env);
	// mlx_hook(env->mlx_win, 5, 1L << 3, mouse_up, env);
	// mlx_hook(env->mlx_win, 6, 1L << 6, mouse_move, env);
	mlx_loop_hook(scene->mlx, render_frame, scene);
	mlx_loop(scene->mlx);
	stop_mlx(scene);
	return (0);
}
