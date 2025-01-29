/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_img.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madelvin <madelvin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 14:16:57 by madelvin          #+#    #+#             */
/*   Updated: 2025/01/28 20:26:53 by madelvin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_reset_button(t_img img)
{
	int	i;
	int	j;
	int	px_x;
	int	px_y;

	i = -1;
	while (++i < 15)
	{
		j = -1;
		while (++j < 80)
		{
			if (i == 0 || i == 15 - 1 || j == 0 || j == 80 - 1)
			{
				px_x = 110 + j;
				px_y = 500 + i;
				if (px_x < W_WIDTH && px_y < W_HEIGHT)
					*((unsigned int *)(((img.line_len * (int)px_y)
									+ ((int)px_x * img.bpp)) + img.px_ptr))
						= blend_colors(TEXT_COLOR, MENU_BACKGROUND, 0.2);
			}
		}
	}
}

static int	is_in_screen(int x1, int y1, int x2, int y2)
{
	if (x1 > W_WIDTH + 5000 || x2 > W_WIDTH + 5000 || y1 > W_HEIGHT + 5000
		|| y2 > W_HEIGHT + 5000 || x1 < 0 || x2 < 0 || y1 < -5000 || y2 < -5000)
		return (1);
	return (0);
}

static void	init_line_params(t_coord p1, t_coord p2, t_line_param *param)
{
	param->dx = get_abs(p1.x - p2.x);
	param->dy = get_abs(p1.y - p2.y);
	param->sx = select_value_sign(p1.x < p2.x, 1);
	param->sy = select_value_sign(p1.y < p2.y, 1);
	param->err = param->dx - param->dy;
}

static void	draw_pixel(t_img img, t_coord p1, t_gradian *gradian)
{
	if (p1.x >= 0 && p1.x < W_WIDTH && p1.y >= 0 && p1.y < W_HEIGHT)
	{
		if (p1.x < 300)
			*((unsigned int *)(((img.line_len * (int)p1.y)
							+ ((int)p1.x * img.bpp)) + img.px_ptr))
				= blend_colors(make_color(*gradian), MENU_BACKGROUND, 0.2);
		else
			*((unsigned int *)(((img.line_len * (int)p1.y)
							+ ((int)p1.x * img.bpp)) + img.px_ptr))
				= make_color(*gradian);
	}
}

void	draw_line(t_img img, t_coord p1, t_coord p2)
{
	t_line_param	param;
	t_gradian		gradian;

	if (is_in_screen(p1.x, p1.y, p2.x, p2.y) || p1.z < 0 || p2.z < 0)
		return ;
	init_line_params(p1, p2, &param);
	init_gradiant(p1.colors, p2.colors, &gradian, param.dx + param.dy);
	while (1)
	{
		draw_pixel(img, p1, &gradian);
		if (p1.x == p2.x && p1.y == p2.y)
			break ;
		param.e2 = param.err * 2;
		if (param.e2 > -param.dy)
		{
			param.err -= param.dy;
			p1.x += param.sx;
		}
		if (param.e2 < param.dx)
		{
			param.err += param.dx;
			p1.y += param.sy;
		}
		gradian.t += gradian.t_inc;
	}
}
