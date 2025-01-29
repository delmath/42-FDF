/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hud_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madelvin <madelvin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 20:53:57 by madelvin          #+#    #+#             */
/*   Updated: 2025/01/29 22:43:45 by madelvin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdlib.h>

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

char	*get_hud_value(char **actual_value, char *new_value)
{
	if (*actual_value)
		free(*actual_value);
	*actual_value = new_value;
	return (*actual_value);
}
