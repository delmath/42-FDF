/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_hud.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madelvin <madelvin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 17:52:01 by madelvin          #+#    #+#             */
/*   Updated: 2025/01/22 12:43:08 by madelvin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"
#include <X11/keysym.h>
#include <stdio.h>
#include <stdlib.h>

// a refaire (refaire un font et un put_str)
void	write_hud(t_fdf *fdf)
{
	mlx_string_put(fdf->mlx, fdf->win, 10, 10, TEXT_COLOR, "FDF");
}
