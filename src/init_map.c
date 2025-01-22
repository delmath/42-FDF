/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madelvin <madelvin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 22:12:26 by madelvin          #+#    #+#             */
/*   Updated: 2025/01/22 20:09:42 by madelvin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <mlx.h>
#include "libft.h"
#include "fdf.h"

static int get_next_point(char *line)
{
	int i;

	i = 0;
	if (!line)
		return (0);
	while (line[i] && (line[i] == '-' || ft_isdigit(line[i])))
		i++;
	while (line[i] && line[i] == ' ')
		i++;
	return i;
}

static int init_line(char *line_a, int *map, t_coord *coord)
{
	map = malloc(1);

	while (line_a && *line_a != '\n')
	{
		map[coord->x] = 0;
		line_a += get_next_point(line_a);
		coord->x++;
	}
	coord->x = 0;
	return (0);
}

static char	*update_loading(t_scene *scene, int actual, int end, char *prev)
{
	char	*message;
	char	*value;
	char	*temp;

	(void)end;
	value = ft_strjoin(ft_itoa(actual), "/");
	temp = ft_strjoin("Get map point : ", value);
	message = ft_strjoin(temp, ft_itoa(end));
	free(temp);
	free(value);
	if (prev)
		mlx_string_put(scene->mlx, scene->win, 10, 10, 0, prev);
	mlx_string_put(scene->mlx, scene->win, 10, 10, 0xEAEAEA, message);
	return (message);
}

static void get_all_point(int fd, t_scene *scene)
{
	t_coord actual_coord;
	char *line;
	char *prev;
	int	i;

	actual_coord.x = 0;
	actual_coord.y = 0;
	actual_coord.z = 0;
	prev = NULL;
	i = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			return ;
		if (init_line(line, scene->map.map[actual_coord.y], &actual_coord))
			return ;
		free(line);
		actual_coord.y++;
		prev = update_loading(scene, i, 10, prev);
		i++;
	}
	return ;
}

// static char	*aff_message(t_scene *scene, char *message, char *prev)
// {
// 	if (prev)
// 		mlx_string_put(scene->mlx, scene->win, 10, 10, 0, prev);
// 	mlx_string_put(scene->mlx, scene->win, 10, 10, 0xEAEAEA, message);
// 	return (message);
// }
// static char	*update_loading(t_scene *scene, int actual, int end, char *prev)
// {
// 	char	*message;
// 	char	*value;
// 	char	*temp;

// 	(void)end;
// 	value = ft_strjoin(ft_itoa(actual), "/");
// 	temp = ft_strjoin("Allocate memory : ", value);
// 	message = ft_strjoin(temp, ft_itoa(end));
// 	free(temp);
// 	free(value);
// 	if (prev)
// 		mlx_string_put(scene->mlx, scene->win, 10, 10, 0, prev);
// 	mlx_string_put(scene->mlx, scene->win, 10, 10, 0xEAEAEA, message);
// 	return (message);
// }

void	get_map_size(int *map_width, int *map_height, char *file)
{
	int		fd;
	int		i;
	char	*line;

	i = -1;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return ;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		if ((*map_width) == 0)
		{
			while (line[++i])
				if (line[i] == ' ')
					(*map_width)++;
		}
		(*map_height)++;
		free(line);
	}
	close(fd);
}

void	init_map(t_scene *scene)
{
	int		fd;
	int		i;

	scene->map.map_height = 0;
	scene->map.map_width = 0;
	get_map_size(&scene->map.map_width, &scene->map.map_height, scene->file);
	fd = open(scene->file, O_RDONLY);
	if (fd < 0)
		return ;
	scene->map.map = malloc(sizeof(int*) * scene->map.map_height);
	if (!scene->map.map)
		return ;
	i = -1;
	while (++i < scene->map.map_height)
	{
		scene->map.map[i] = malloc(sizeof(int) * scene->map.map_width);
		// if (!scene->map.map[i])
			// free le talbeaux
	}
	get_all_point(fd, scene);
	close(fd);
}
