/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madelvin <madelvin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 12:05:38 by madelvin          #+#    #+#             */
/*   Updated: 2025/01/22 16:41:47 by madelvin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
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
	return (init_mlx(&scene, argv[1]));
}
