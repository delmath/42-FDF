/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madelvin <madelvin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 16:00:48 by madelvin          #+#    #+#             */
/*   Updated: 2025/03/19 17:51:43 by madelvin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <mlx.h>
#include <stdlib.h>

int	close_window(t_scene *scene)
{
	mlx_loop_end(scene->mlx);
	return (0);
}

int	render_frame(t_scene *scene)
{
	calcule_frame(scene);
	render_hud(scene);
	return (0);
}
