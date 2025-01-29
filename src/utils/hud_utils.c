/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hud_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madelvin <madelvin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 20:53:57 by madelvin          #+#    #+#             */
/*   Updated: 2025/01/28 20:55:27 by madelvin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char	*get_iso(char iso)
{
	if (iso == 1)
		return ("true");
	return ("false");
}

char	*get_projection(char projection)
{
	if (projection == 1)
		return ("perspective");
	return ("orthographic");
}

char	*get_transform(t_transform transorm)
{
	if (transorm == DEFAULT)
		return ("none");
	if (transorm == TORUS)
		return ("torus");
	if (transorm == SPHERE)
		return ("sphere");
	return ("none");
}
