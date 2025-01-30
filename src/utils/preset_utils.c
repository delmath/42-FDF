/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preset_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madelvin <madelvin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 16:53:30 by madelvin          #+#    #+#             */
/*   Updated: 2025/01/30 18:19:09 by madelvin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	set_lvl_color(int *c_start, int *c_end, int normal_z, int c_preset)
{
	t_color_preset	preset;

	init_color_preset(&preset, c_preset);
	*c_start = preset.vhigh;
	*c_end = preset.vhigh;
	if (normal_z < 0.1)
	{
		*c_start = preset.vlow;
		*c_end = preset.low;
	}
	else if (normal_z < 0.3)
	{
		*c_start = preset.low;
		*c_end = preset.medium;
	}
	else if (normal_z < 0.5)
	{
		*c_start = preset.medium;
		*c_end = preset.high;
	}
	else if (normal_z < 0.7)
	{
		*c_start = preset.high;
		*c_end = preset.vhigh;
	}
}

void	set_color(t_coord *p1, t_scene scene)
{
	float		normalized_z;
	int			c_start;
	int			c_end;
	t_gradian	gradian;

	normalized_z = (p1->default_z - scene.map.map_min_z)
		/ (scene.map.map_max_z - scene.map.map_min_z);
	set_lvl_color(&c_start, &c_end, normalized_z, scene.param.color_preset);
	init_gradiant(c_start, c_end, &gradian, 100);
	gradian.t = normalized_z;
	p1->colors = make_color(gradian);
}
