/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madelvin <madelvin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 22:18:55 by madelvin          #+#    #+#             */
/*   Updated: 2025/01/28 19:58:58 by madelvin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libft.h"
#include "fdf.h"

void	exit_handler(int return_value, char	*value, t_scene *scene)
{
	if (scene->map.point_list)
		free(scene->map.point_list);
	if (scene->map.map)
		free(scene->map.map);
	if (return_value > 0 && !value)
		perror("FDF ERROR: ");
	else if (return_value > 0)
	{
		ft_putstr_fd("FDF ERROR: ", 2);
		perror(value);
	}
	exit (return_value);
}
