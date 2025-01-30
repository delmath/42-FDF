/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_preset.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madelvin <madelvin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 17:19:39 by madelvin          #+#    #+#             */
/*   Updated: 2025/01/30 17:43:16 by madelvin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	set_preset_earth(t_color_preset *preset)
{
	preset->vlow = 0x0A1F44;
	preset->low = 0x4CAF50;
	preset->medium = 0x1B5E20;
	preset->high = 0x795548;
	preset->vhigh = 0xFFFFFF;
}

void	set_preset_volcanic(t_color_preset *preset)
{
	preset->vlow = 0x000000;
	preset->low = 0x8B0000;
	preset->medium = 0xFF4500;
	preset->high = 0xFFA500;
	preset->vhigh = 0xFFFF00;
}

void	set_preset_arctic(t_color_preset *preset)
{
	preset->vlow = 0x001F3F;
	preset->low = 0x0074D9;
	preset->medium = 0x7FDBFF;
	preset->high = 0xF0F8FF;
	preset->vhigh = 0xFFFFFF;
}

void	set_preset_martian(t_color_preset *preset)
{
	preset->vlow = 0x4E342E;
	preset->low = 0xD84315;
	preset->medium = 0xFF9800;
	preset->high = 0xFFCC80;
	preset->vhigh = 0xFAEBD7;
}

void	init_color_preset(t_color_preset *preset, int c_preset)
{
	if (c_preset == 0)
		set_preset_earth(preset);
	else if (c_preset == 1)
		set_preset_volcanic(preset);
	else if (c_preset == 2)
		set_preset_arctic(preset);
	else if (c_preset == 3)
		set_preset_martian(preset);
}
