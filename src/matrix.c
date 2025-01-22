/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madelvin <madelvin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 22:07:02 by madelvin          #+#    #+#             */
/*   Updated: 2025/01/22 15:28:50 by madelvin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void init_perspective_matrix(float matrix[4][4], t_fdf *fdf)
{
	float zfar_plus_znear;
	float znear_minus_zfar;
	float focal_ratio;

	zfar_plus_znear = fdf->param->zfar + fdf->param->znear;
	znear_minus_zfar = fdf->param->znear - fdf->param->zfar;
	focal_ratio = fdf->camera->focal / fdf->param->ratio;
	matrix[0][0] = focal_ratio;
	matrix[0][1] = 0;
	matrix[0][2] = 0;
	matrix[0][3] = 0;
	matrix[1][0] = 0;
	matrix[1][1] = fdf->camera->focal;
	matrix[1][2] = 0;
	matrix[1][3] = 0;
	matrix[2][0] = zfar_plus_znear / znear_minus_zfar;
	matrix[2][1] = 2 * zfar_plus_znear / znear_minus_zfar;
	matrix[2][2] = 0;
	matrix[2][3] = 0;
	matrix[3][0] = 0;
	matrix[3][1] = 0;
	matrix[3][2] = -1;
	matrix[3][3] = 0;
}

void	init_orthogonal_matrix(float matrix[4][4], t_fdf *fdf)
{
	float right_left;
	float top_bottom;
	float far_near;

	right_left = fdf->param->right - fdf->param->left;
	top_bottom = fdf->param->top - fdf->param->bottom;
	far_near = fdf->param->far - fdf->param->near;
	matrix[0][0] = 2 / right_left;
	matrix[0][1] = 0;
	matrix[0][2] = 0;
	matrix[0][3] = (-fdf->param->right + fdf->param->left) / right_left;
	matrix[1][0] = 0;
	matrix[1][1] = 2 / top_bottom;
	matrix[1][2] = 0;
	matrix[1][3] = (-fdf->param->top + fdf->param->bottom) / top_bottom;
	matrix[2][0] = 0;
	matrix[2][1] = 0;
	matrix[2][2] = -2 / far_near;
	matrix[2][3] = (-fdf->param->far + fdf->param->near) / far_near;
	matrix[3][0] = 0;
	matrix[3][1] = 0;
	matrix[3][2] = 0;
	matrix[3][3] = 1;
}

void	init_yaw_matrix(float matrix[3][3], float yaw)
{
	float cos_yaw;
	float sin_yaw;

	yaw = yaw + PI_10D / 2;
	cos_yaw = cos(yaw);
	sin_yaw = sin(yaw);
	matrix[0][0] = cos_yaw;
	matrix[0][1] = -sin_yaw;
	matrix[0][2] = 0;
	matrix[1][0] = sin_yaw;
	matrix[1][1] = cos_yaw;
	matrix[1][2] = 0;
	matrix[2][0] = 0;
	matrix[2][1] = 0;
	matrix[2][2] = 1;
}

void	init_roll_matrix(float matrix[3][3], float roll)
{
	float cos_roll;
	float sin_roll;
	
	cos_roll = cos(roll);
	sin_roll = sin(roll);
	matrix[0][0] = cos_roll;
	matrix[0][1] = 0;
	matrix[0][2] = sin_roll;
	matrix[1][0] = 0;
	matrix[1][1] = 1;
	matrix[1][2] = 0;
	matrix[2][0] = -sin_roll;
	matrix[2][1] = 0;
	matrix[2][2] = cos_roll;
}

void	init_pitch_matrix(float matrix[3][3], float pitch)
{
	float cos_pitch;
	float sin_pitch;
	
	pitch = pitch - PI_10D / 2;
	cos_pitch = cos(pitch);
	sin_pitch = sin(pitch);
	matrix[0][0] = 1;
	matrix[0][1] = 0;
	matrix[0][2] = 0;
	matrix[1][0] = 0;
	matrix[1][1] = cos_pitch;
	matrix[1][2] = -sin_pitch;
	matrix[2][0] = 0;
	matrix[2][1] = sin_pitch;
	matrix[2][2] = cos_pitch;
}
