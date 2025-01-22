/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madelvin <madelvin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 13:48:26 by madelvin          #+#    #+#             */
/*   Updated: 2025/01/16 22:09:13 by madelvin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	check_entry(int argc, char *map)
{
	int	map_name_size;

	if (argc != 2)
		return (1);
	map_name_size = ft_strlen(map);
	if ((map_name_size < 4))
		return (1);
	if (ft_strncmp(".fdf", (map + (map_name_size - 4)), 4) != 0)
		return (1);
	return (0);
}
