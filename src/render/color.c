/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madelvin <madelvin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 14:16:37 by madelvin          #+#    #+#             */
/*   Updated: 2025/01/30 19:36:42 by madelvin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

int	blend_colors(int color_x, int gray_color, float factor)
{
	int	r;
	int	g;
	int	b;

	r = (color_x >> 16) & 0xFF;
	g = (color_x >> 8) & 0xFF;
	b = color_x & 0xFF;
	r = (int)(r * factor + ((gray_color >> 16) & 0xFF) * (1.0f - factor));
	g = (int)(g * factor + ((gray_color >> 8) & 0xFF) * (1.0f - factor));
	b = (int)(b * factor + (gray_color & 0xFF) * (1.0f - factor));
	return ((r << 16) | (g << 8) | b);
}

void	init_gradiant(int color_s, int color_e, t_gradian *gradian, int d)
{
	int	start_color;
	int	end_color;

	start_color = color_s;
	end_color = color_e;
	gradian->b = start_color & 0xFF;
	gradian->g = (start_color >> 8) & 0xFF;
	gradian->r = (start_color >> 16) & 0xFF;
	gradian->temp_r = ((end_color >> 16) & 0xFF) - gradian->r;
	gradian->temp_g = ((end_color >> 8) & 0xFF) - gradian->g;
	gradian->temp_b = (end_color & 0xFF) - gradian->b;
	gradian->distance = d;
	gradian->t_inc = 1.0f / d;
	gradian->t = 0;
}

int	make_color(t_gradian gradian)
{
	return (((gradian.r + (int)(gradian.t * gradian.temp_r)) << 16) |
		((gradian.g + (int)(gradian.t * gradian.temp_g)) << 8) |
		(gradian.b + (int)(gradian.t * gradian.temp_b)));
}
