/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madelvin <madelvin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 14:16:37 by madelvin          #+#    #+#             */
/*   Updated: 2025/01/28 16:58:26 by madelvin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	blend_colors(int color_x, int gray_color, float factor)
{
	t_gradian	gradian;

	gradian.r = (color_x >> 16) & 0xFF;
	gradian.g = (color_x >> 8) & 0xFF;
	gradian.b = color_x & 0xFF;
	gradian.temp_r = (int)(gradian.r * factor + ((gray_color >> 16) & 0xFF)
			* (1.0f - factor));
	gradian.temp_g = (int)(gradian.g * factor + ((gray_color >> 8) & 0xFF)
			* (1.0f - factor));
	gradian.temp_b = (int)(gradian.b * factor + (gray_color & 0xFF)
			* (1.0f - factor));
	return ((gradian.temp_r << 16) | (gradian.temp_g << 8) | gradian.temp_b);
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
	int	r;
	int	g;
	int	b;

	r = gradian.r + (int)(gradian.t * gradian.temp_r);
	g = gradian.g + (int)(gradian.t * gradian.temp_g);
	b = gradian.b + (int)(gradian.t * gradian.temp_b);
	return ((r << 16) | (g << 8) | b);
}
