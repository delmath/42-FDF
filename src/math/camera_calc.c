/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_calc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madelvin <madelvin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 15:33:54 by madelvin          #+#    #+#             */
/*   Updated: 2025/01/30 19:37:08 by madelvin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>

void	calc_axis_matrix(t_camera *cam)
{
	cam->axes_matrix[0][0] = -cam->axe_pitch.cos_axe * cam->axe_roll.cos_axe
		- cam->axe_pitch.sin_axe * cam->axe_yaw.sin_axe * cam->axe_roll.sin_axe;
	cam->axes_matrix[0][1] = cam->axe_pitch.sin_axe * cam->axe_roll.cos_axe
		- cam->axe_pitch.cos_axe * cam->axe_yaw.sin_axe * cam->axe_roll.sin_axe;
	cam->axes_matrix[0][2] = 0;
	cam->axes_matrix[1][0] = cam->axe_pitch.sin_axe * cam->axe_yaw.cos_axe;
	cam->axes_matrix[1][1] = cam->axe_pitch.cos_axe * cam->axe_yaw.cos_axe;
	cam->axes_matrix[1][2] = cam->axe_yaw.sin_axe;
	cam->axes_matrix[2][0] = -cam->axe_pitch.cos_axe * cam->axe_roll.sin_axe
		+ cam->axe_pitch.sin_axe * cam->axe_yaw.sin_axe * cam->axe_roll.cos_axe;
	cam->axes_matrix[2][1] = -cam->axe_pitch.sin_axe * cam->axe_roll.sin_axe
		+ cam->axe_pitch.cos_axe * cam->axe_yaw.sin_axe * cam->axe_roll.cos_axe;
	cam->axes_matrix[2][2] = -cam->axe_yaw.cos_axe * cam->axe_roll.cos_axe;
}

void	calc_axis_value(t_camera *cam)
{
	float	corrected_yaw;
	float	corrected_pitch;

	corrected_yaw = cam->yaw + PI_F / 2;
	corrected_pitch = cam->pitch - PI_F / 2;
	cam->axe_yaw.cos_axe = cos(corrected_yaw);
	cam->axe_yaw.sin_axe = sin(corrected_yaw);
	cam->axe_pitch.cos_axe = cos(corrected_pitch);
	cam->axe_pitch.sin_axe = sin(corrected_pitch);
	cam->axe_roll.cos_axe = cos(cam->roll);
	cam->axe_roll.sin_axe = sin(cam->roll);
	calc_axis_matrix(cam);
}

void	calc_proj_coord(t_scene *scene)
{
	t_camera	*cam;

	cam = &scene->camera;
	if (scene->param.iso == 1)
	{
		cam->proj_coord.x = cam->coord.x + cam->distance
			* cam->axes_matrix[0][0];
		cam->proj_coord.y = cam->coord.y + cam->distance
			* cam->axes_matrix[0][1];
		cam->proj_coord.z = cam->coord.z + cam->distance
			* cam->axes_matrix[0][2];
	}
	else
	{
		cam->proj_coord = cam->coord;
	}
}
