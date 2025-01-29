/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madelvin <madelvin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 16:00:48 by madelvin          #+#    #+#             */
/*   Updated: 2025/01/29 14:53:35 by madelvin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <mlx.h>

int	close_window(t_scene *scene)
{
	mlx_loop_end(scene->mlx);
	return (0);
}

int	render_frame(t_scene *scene)
{
	t_img	img;

	img = calcule_frame(scene);
	render_hud(scene);
	mlx_destroy_image(scene->mlx, img.img_ptr);
	return (0);
}
