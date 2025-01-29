/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_calc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madelvin <madelvin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 15:33:54 by madelvin          #+#    #+#             */
/*   Updated: 2025/01/28 20:22:23 by madelvin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>

void	calc_axis_matrix(t_camera *cam)
{
	float	sin_roll_sin_pitch_90;
	float	cos_roll_sin_pitch_90;
	float	cos_pitch_90_cos_yaw_90;

	sin_roll_sin_pitch_90 = cam->axe_roll.sin_axe * cam->axe_pitch.sin_90;
	cos_roll_sin_pitch_90 = cam->axe_roll.cos_axe * cam->axe_pitch.sin_90;
	cos_pitch_90_cos_yaw_90 = cam->axe_pitch.cos_90 * cam->axe_yaw.cos_90;
	cam->axe_pitch.sin_90 = cam->axe_pitch.sin_90;
	cam->axe_pitch.cos_90 = cam->axe_pitch.cos_90;
	cam->axe_yaw.sin_90 = cam->axe_yaw.sin_90;
	cam->axe_yaw.cos_90 = cam->axe_yaw.cos_90;
	cam->axes_matrix[0][0] = sin_roll_sin_pitch_90
		* cam->axe_yaw.sin_90 + cam->axe_roll.cos_axe * cam->axe_yaw.cos_90;
	cam->axes_matrix[0][1] = sin_roll_sin_pitch_90
		* cam->axe_yaw.cos_90 - cam->axe_roll.cos_axe * cam->axe_yaw.sin_90;
	cam->axes_matrix[0][2] = cam->axe_roll.sin_axe * cam->axe_pitch.cos_90;
	cam->axes_matrix[1][0] = cos_pitch_90_cos_yaw_90;
	cam->axes_matrix[1][1] = cos_pitch_90_cos_yaw_90;
	cam->axes_matrix[1][2] = -cam->axe_pitch.sin_90;
	cam->axes_matrix[2][0] = cos_roll_sin_pitch_90 * cam->axe_yaw.cos_90
		+ cam->axe_roll.sin_axe * cam->axe_yaw.sin_90;
	cam->axes_matrix[2][1] = cos_roll_sin_pitch_90 * cam->axe_yaw.sin_90
		- cam->axe_yaw.cos_90 * cam->axe_roll.sin_axe;
	cam->axes_matrix[2][2] = cam->axe_roll.cos_axe * cam->axe_pitch.cos_90;
}

void	calc_axis_value(t_camera *cam)
{
	float	yaw_angle;
	float	yaw_angle_90;
	float	pitch_angle;
	float	pitch_angle_90;
	float	roll_angle;

	yaw_angle = cam->yaw;
	yaw_angle_90 = yaw_angle + PI / 2;
	pitch_angle = cam->pitch;
	pitch_angle_90 = pitch_angle - PI / 2;
	roll_angle = cam->roll;
	cam->axe_yaw.cos_90 = cos(yaw_angle_90);
	cam->axe_yaw.sin_90 = sin(yaw_angle_90);
	cam->axe_yaw.cos_axe = cos(yaw_angle);
	cam->axe_yaw.sin_axe = sin(yaw_angle);
	cam->axe_pitch.cos_90 = cos(pitch_angle_90);
	cam->axe_pitch.sin_90 = sin(pitch_angle_90);
	cam->axe_pitch.cos_axe = cos(pitch_angle);
	cam->axe_pitch.sin_axe = sin(pitch_angle);
	cam->axe_roll.cos_axe = cos(roll_angle);
	cam->axe_roll.sin_axe = sin(roll_angle);
	calc_axis_matrix(cam);
}

void	calc_proj_coord(t_scene *scene)
{
	t_camera	*cam;

	cam = &scene->camera;
	if (scene->param.iso == 1)
	{
		cam->proj_coord.x = cam->coord.x + cam->distance
			* cam->axe_yaw.cos_axe * cam->axe_pitch.cos_axe;
		cam->proj_coord.y = cam->coord.y + cam->distance
			* cam->axe_yaw.cos_axe * cam->axe_pitch.sin_axe;
		cam->proj_coord.z = cam->coord.z + cam->distance * cam->axe_yaw.sin_axe;
	}
	else
		cam->proj_coord = cam->coord;
}
