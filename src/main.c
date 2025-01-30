/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madelvin <madelvin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 12:05:38 by madelvin          #+#    #+#             */
/*   Updated: 2025/01/30 18:36:19 by madelvin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"

int	main(int argc, char **argv)
{
	t_scene	scene;

	if (check_entry(argc, argv[1]))
	{
		ft_putendl_fd("FDF ERROR: usage: ./fdf <map.fdf>", 2);
		return (1);
	}
	init_scene(&scene, argv[1]);
	return (init_mlx(&scene));
}
