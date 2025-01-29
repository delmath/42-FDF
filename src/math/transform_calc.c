/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform_calc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madelvin <madelvin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 20:55:00 by madelvin          #+#    #+#             */
/*   Updated: 2025/01/29 14:53:47 by madelvin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>

void	transform_to_spherical(float vector[4], t_scene *scene, int i)
{
	float	z;
	float	radius;
	float	longitude;
	float	latitude;

	z = scene->map.map[i].z * scene->param.z_ratio;
	radius = scene->map.map_width / (2.0 * PI);
	if (radius == 0)
		radius = 1.0;
	longitude = -PI + (2.0 * PI)
		* scene->map.map[i].x / (scene->map.map_width - 1);
	latitude = -PI / 2.0 + PI
		* scene->map.map[i].y / (scene->map.map_height - 1);
	radius += z * scene->param.z_ratio * 0.1;
	vector[0] = radius * cos(latitude) * sin(longitude);
	vector[1] = radius * cos(latitude) * cos(longitude);
	vector[2] = radius * sin(latitude);
}

void	transform_to_torus(float vector[4], t_scene *scene, int i)
{
	float	r_o;
	float	r_i;
	float	u;
	float	v;
	float	z;

	z = scene->map.map[i].z * scene->param.z_ratio;
	r_o = scene->map.map_width / (2.0 * PI);
	if (r_o == 0)
		r_o = 1.0;
	r_i = scene->map.map_height / (4.0 * PI);
	if (r_i == 0)
		r_i = 1.0;
	u = PI + (2.0 * PI) * scene->map.map[i].x / (scene->map.map_width - 1);
	v = 2 * PI * scene->map.map[i].y / (scene->map.map_height - 1);
	r_o += z * scene->param.z_ratio * 0.1;
	vector[0] = (r_o + r_i * cos(v)) * cos(u);
	vector[1] = (r_o + r_i * cos(v)) * sin(u);
	vector[2] = r_i * sin(v) + z * scene->param.z_ratio * 0.1;
}
