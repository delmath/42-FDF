/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madelvin <madelvin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 22:12:26 by madelvin          #+#    #+#             */
/*   Updated: 2025/01/29 18:04:58 by madelvin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fdf.h"
#include <fcntl.h>
#include <stdlib.h>
#include <mlx.h>

static int	get_next_point(char *line)
{
	int	i;

	i = 0;
	if (!line)
		return (0);
	while (line[i] && line[i] != ' ')
		i++;
	while (line[i] && line[i] == ' ')
		i++;
	return (i);
}

static int	init_line(char *line, t_coord *map, t_coord *coord, int max)
{
	while (coord->x < max)
	{
		map[(int)coord->x + (int)(coord->y * max)].x = coord->x;
		map[(int)coord->x + (int)(coord->y * max)].y = coord->y;
		map[(int)coord->x + (int)(coord->y * max)].z = ft_atoi(line);
		map[(int)coord->x + (int)(coord->y * max)].colors = get_color(line);
		line += get_next_point(line);
		coord->x++;
	}
	coord->x = 0;
	return (0);
}

static void	get_all_point(int fd, t_scene *scene)
{
	t_coord	actual_coord;
	char	*line;

	actual_coord.x = 0;
	actual_coord.y = 0;
	actual_coord.z = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			return ;
		if (init_line(line, scene->map.map,
				&actual_coord, scene->map.map_width))
			return ;
		free(line);
		actual_coord.y++;
	}
	return ;
}

void	get_map_size(int *map_width, int *map_height, char *file)
{
	int		fd;
	int		i;
	char	*line;

	fd = open(file, O_RDONLY);
	i = -1;
	if (fd < 0)
		return ;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		if (i == -1)
		{
			while (line[++i])
			{
				if (is_valid_value(line, i))
					(*map_width)++;
			}
		}
		(*map_height)++;
		free(line);
	}
	close(fd);
}

void	init_map(t_scene *scene)
{
	int		fd;

	scene->map.map_height = 0;
	scene->map.map_width = 0;
	get_map_size(&scene->map.map_width, &scene->map.map_height, scene->file);
	scene->map.map_ratio = scene->map.map_width / scene->map.map_height;
	fd = open(scene->file, O_RDONLY);
	if (fd < 0)
		return ;
	scene->map.map = malloc(sizeof(t_coord)
			* (scene->map.map_width * scene->map.map_height));
	if (!scene->map.map)
		return ;
	get_all_point(fd, scene);
	close(fd);
}
