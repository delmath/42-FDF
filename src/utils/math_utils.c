/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madelvin <madelvin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 14:28:23 by madelvin          #+#    #+#             */
/*   Updated: 2025/01/30 17:53:36 by madelvin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	get_abs(int x)
{
	if (x < 0)
		return (-x);
	return (x);
}

int	select_value_sign(int x, int value)
{
	if (x > 0)
		return (value);
	return (-value);
}

void	bresenham_algo(t_img img, t_line_param param, t_coord p1, t_coord p2)
{
	while (1)
	{
		draw_pixel(img, p1, &param.gradian);
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
		param.gradian.t += param.gradian.t_inc;
	}
}
