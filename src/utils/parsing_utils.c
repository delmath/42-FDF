/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madelvin <madelvin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 13:48:26 by madelvin          #+#    #+#             */
/*   Updated: 2025/01/30 18:26:31 by madelvin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fdf.h"

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

int	get_point_color(const char *line)
{
	int	result;
	int	value;

	result = 0;
	while (*line && *line != ' ' && *line != '\n')
	{
		if (*line >= '0' && *line <= '9')
			value = *line - '0';
		else if (*line >= 'a' && *line <= 'f')
			value = *line - 'a' + 10;
		else if (*line >= 'A' && *line <= 'F')
			value = *line - 'A' + 10;
		else
			return (COLOR_DEFAULT);
		result = result * 16 + value;
		line++;
	}
	return (result);
}

int	get_color(char *line)
{
	while (*line && *line != ',' && *line != ' ')
		line++;
	if ((ft_strncmp(line, ",0x", 3) == 0) || (ft_strncmp(line, ",0X", 3) == 0))
		return (get_point_color(line + 3));
	return (COLOR_ERROR);
}

int	is_valid_value(char *line, int i)
{
	if ((ft_isdigit(line[i]) || line[i] == '-')
		&& (i == 0 || line[i - 1] == ' '))
		return (1);
	return (0);
}
