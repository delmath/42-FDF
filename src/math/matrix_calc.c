/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_calc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madelvin <madelvin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 20:20:13 by madelvin          #+#    #+#             */
/*   Updated: 2025/01/29 22:14:16 by madelvin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	calc_persp_matrix(t_scene *scene)
{
	scene->proj.persp_matrix[0][0] = scene->camera.focal / (W_WIDTH / W_HEIGHT);
	scene->proj.persp_matrix[0][1] = 0;
	scene->proj.persp_matrix[0][2] = 0;
	scene->proj.persp_matrix[0][3] = 0;
	scene->proj.persp_matrix[1][0] = 0;
	scene->proj.persp_matrix[1][1] = scene->camera.focal;
	scene->proj.persp_matrix[1][2] = 0;
	scene->proj.persp_matrix[1][3] = 0;
	scene->proj.persp_matrix[2][0] = 0;
	scene->proj.persp_matrix[2][1] = 0;
	scene->proj.persp_matrix[2][2] = -((scene->camera.clipping_planes.zfar
				+ scene->camera.clipping_planes.znear)
			/ (scene->camera.clipping_planes.zfar
				- scene->camera.clipping_planes.znear));
	scene->proj.persp_matrix[2][3] = -((2 * scene->camera.clipping_planes.zfar
				* scene->camera.clipping_planes.znear)
			/ (scene->camera.clipping_planes.zfar
				- scene->camera.clipping_planes.znear));
	scene->proj.persp_matrix[3][0] = 0;
	scene->proj.persp_matrix[3][1] = 0;
	scene->proj.persp_matrix[3][2] = -1;
	scene->proj.persp_matrix[3][3] = 0;
}

void	calc_ortho_matrix(t_scene *scene)
{
	scene->proj.ortho_matrix[0][0] = 2 / (scene->proj.right - scene->proj.left);
	scene->proj.ortho_matrix[0][1] = 0;
	scene->proj.ortho_matrix[0][2] = 0;
	scene->proj.ortho_matrix[0][3] = (-scene->proj.right + scene->proj.left)
		/ (scene->proj.right - scene->proj.left);
	scene->proj.ortho_matrix[1][0] = 0;
	scene->proj.ortho_matrix[1][1] = 2 / (scene->proj.top - scene->proj.bottom);
	scene->proj.ortho_matrix[1][2] = 0;
	scene->proj.ortho_matrix[1][3] = (-scene->proj.top + scene->proj.bottom)
		/ (scene->proj.top - scene->proj.bottom);
	scene->proj.ortho_matrix[2][0] = 0;
	scene->proj.ortho_matrix[2][1] = 0;
	scene->proj.ortho_matrix[2][2] = -2 / (scene->camera.clipping_planes.far
			- scene->camera.clipping_planes.near);
	scene->proj.ortho_matrix[2][3] = (-scene->camera.clipping_planes.far
			+ scene->camera.clipping_planes.near)
		/ (scene->camera.clipping_planes.far
			- scene->camera.clipping_planes.near);
	scene->proj.ortho_matrix[3][0] = 0;
	scene->proj.ortho_matrix[3][1] = 0;
	scene->proj.ortho_matrix[3][2] = 0;
	scene->proj.ortho_matrix[3][3] = 1;
}

void	multiply_matrix_vector_4d(float matrix[4][4], float p[4])
{
	float	result[4];

	result[0] = matrix[0][0] * p[0] + matrix[0][1] * p[1] + matrix[0][2]
		* p[2] + matrix[0][3] * p[3];
	result[1] = matrix[1][0] * p[0] + matrix[1][1] * p[1] + matrix[1][2]
		* p[2] + matrix[1][3] * p[3];
	result[2] = matrix[2][0] * p[0] + matrix[2][1] * p[1] + matrix[2][2]
		* p[2] + matrix[2][3] * p[3];
	result[3] = matrix[3][0] * p[0] + matrix[3][1] * p[1] + matrix[3][2]
		* p[2] + matrix[3][3] * p[3];
	p[0] = result[0];
	p[1] = result[1];
	p[2] = result[2];
	p[3] = result[3];
}

void	multiply_matrix_vector_3d(float matrix[3][3], float p[4])
{
	float	result[4];

	result[0] = matrix[0][0] * p[0] + matrix[0][1] * p[1] + matrix[0][2] * p[2];
	result[1] = matrix[1][0] * p[0] + matrix[1][1] * p[1] + matrix[1][2] * p[2];
	result[2] = matrix[2][0] * p[0] + matrix[2][1] * p[1] + matrix[2][2] * p[2];
	p[0] = result[0];
	p[1] = result[1];
	p[2] = result[2];
}
