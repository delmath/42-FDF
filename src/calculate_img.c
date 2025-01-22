/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_img.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madelvin <madelvin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 22:00:01 by madelvin          #+#    #+#             */
/*   Updated: 2025/01/22 19:12:38 by madelvin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <mlx.h>
#include <unistd.h>
#include <math.h>
#include <stdio.h>

typedef struct {
    float x, y, z, w;
} Point4D;

Point4D multiplyMatrixVector(float matrix[4][4], Point4D p)
{
    Point4D result;
    result.x = matrix[0][0] * p.x + matrix[0][1] * p.y + matrix[0][2] * p.z + matrix[0][3] * p.w;
    result.y = matrix[1][0] * p.x + matrix[1][1] * p.y + matrix[1][2] * p.z + matrix[1][3] * p.w;
    result.z = matrix[2][0] * p.x + matrix[2][1] * p.y + matrix[2][2] * p.z + matrix[2][3] * p.w;
    result.w = matrix[3][0] * p.x + matrix[3][1] * p.y + matrix[3][2] * p.z + matrix[3][3] * p.w;
    return result;
}



Point4D orthoProjection(float left, float right, float bottom, float top, float near, float far, Point4D p)
{
    float matrix[4][4] = {
        {2.0f / (right - left), 0, 0, -(right + left) / (right - left)},
        {0, 2.0f / (top - bottom), 0, -(top + bottom) / (top - bottom)},
        {0, 0, -2.0f / (far - near), -(far + near) / (far - near)},
        {0, 0, 0, 1}
    };

    return multiplyMatrixVector(matrix, p);
}

// Pitch
void rotationX(float angle, float matrix[4][4]) {
    matrix[0][0] = 1;
    matrix[0][1] = 0;
    matrix[0][2] = 0;
    matrix[0][3] = 0;
    matrix[1][0] = 0;
    matrix[1][1] = cos(angle);
    matrix[1][2] = -sin(angle);
    matrix[1][3] = 0;
    matrix[2][0] = 0;
    matrix[2][1] = sin(angle);
    matrix[2][2] = cos(angle);
    matrix[2][3] = 0;
    matrix[3][0] = 0;
    matrix[3][1] = 0;
    matrix[3][2] = 0;
    matrix[3][3] = 1;
}

// Roll
void rotationY(float angle, float matrix[4][4]) {
    matrix[0][0] = cos(angle);
    matrix[0][1] = 0;
    matrix[0][2] = sin(angle);
    matrix[0][3] = 0;
    matrix[1][0] = 0;
    matrix[1][1] = 1;
    matrix[1][2] = 0;
    matrix[1][3] = 0;
    matrix[2][0] = -sin(angle);
    matrix[2][1] = 0;
    matrix[2][2] = cos(angle);
    matrix[2][3] = 0;
    matrix[3][0] = 0;
    matrix[3][1] = 0;
    matrix[3][2] = 0;
    matrix[3][3] = 1;
}

// Yaw
void rotationZ(float angle, float matrix[4][4]) {
    matrix[0][0] = cos(angle);
    matrix[0][1] = -sin(angle);
    matrix[0][2] = 0;
    matrix[0][3] = 0;
    matrix[1][0] = sin(angle);
    matrix[1][1] = cos(angle);
    matrix[1][2] = 0;
    matrix[1][3] = 0;
    matrix[2][0] = 0;
    matrix[2][1] = 0;
    matrix[2][2] = 1;
    matrix[2][3] = 0;
    matrix[3][0] = 0;
    matrix[3][1] = 0;
    matrix[3][2] = 0;
    matrix[3][3] = 1;
}

Point4D applyCameraRotation(t_camera c, Point4D p)
{
    p.x -= c.x;
    p.y -= c.y;
    p.z -= c.z;

    float matrixZ[4][4], matrixX[4][4], matrixY[4][4];
    rotationZ(c.yaw, matrixZ);
    rotationX(c.pitch, matrixX);
    rotationY(c.roll, matrixY);

    Point4D p1 = multiplyMatrixVector(matrixZ, p);
    Point4D p2 = multiplyMatrixVector(matrixX, p1);
    Point4D p3 = multiplyMatrixVector(matrixY, p2);

    return p3;
}

Point4D perspectivProjection(float f, float ratio, float far, float near, Point4D p)
{
    float matrix[4][4] = {
        {f / ratio, 0, 0, 0},
        {0, f, 0, 0},
        {0, 0, (far + near)/(near - far), 2*((far + near)/(near - far))},
        {0, 0, -1, 0}
    };

    return multiplyMatrixVector(matrix, p);
}
float zOrdering(float z, float near, float far)
{
    return (2.0f * near) / (far + near - z * (far - near));
}

void plotPixel(t_img img, int x, int y)
{
	int	offset;

	offset = (img.line_len * y) + (x * (img.bpp / 8));
	*((unsigned int *)(offset + img.px_ptr)) = 0xff0000;
}

int custom_abs(int x)
{
    return (x < 0) ? -x : x;
}

void bresenham(t_img img, t_fdf fdf, int x0, int y0, int x1, int y1)
{
    int dx = custom_abs(x1 - x0);
    int dy = custom_abs(y1 - y0);
    int sx = (x0 < x1) ? 1 : -1;
    int sy = (y0 < y1) ? 1 : -1;
    int err = dx - dy;

    while (1) {
		if (x0 >= 0 && x0 < fdf.window_data->width && y0 >= 0 && y0 < fdf.window_data->height)
       		plotPixel(img, x0, y0);
        if (x0 == x1 && y0 == y1)
            break ;
        int e2 = err * 2;
        if (e2 > -dy)
		{
            err -= dy;
            x0 += sx;
        }
        if (e2 < dx)
		{
            err += dx;
            y0 += sy;
        }
    }
}

int	compare_two_point(t_coord p1, t_coord p2)
{
	if (p1.x != p2.x || p1.y != p2.y || p1.z != p2.z)
		return (0);
	return (1);
}

t_img	calcule_frame(t_fdf *fdf)
{
	t_img img;
	t_point actual;

	actual = *fdf->map->points;
	img.img_ptr = mlx_new_image(fdf->mlx, fdf->window_data->width, fdf->window_data->height);
	img.px_ptr = mlx_get_data_addr(img.img_ptr, &img.bpp, &img.line_len, &img.endian);
	while (actual.next_point != NULL)
	{
		int i = 0;
		while (i < 2)
		{
			if (compare_two_point(actual.coordinates, actual.linked_points[i]) == 0)
			{
				Point4D p1 = {actual.coordinates.x, actual.coordinates.y, actual.coordinates.z, fdf->param->size};
				Point4D	p2 = {actual.linked_points[i].x, actual.linked_points[i].y, actual.linked_points[i].z, fdf->param->size};
				p1.z *= fdf->param->z_ratio;
				p2.z *= fdf->param->z_ratio;
				p1 = applyCameraRotation(*fdf->camera, p1);
				p2 = applyCameraRotation(*fdf->camera, p2);
				// p1 = perspectivProjection(fdf->camera->focal, fdf->param->ratio, fdf->param->far, fdf->param->near, p1);
				// p2 = perspectivProjection(fdf->camera->focal, fdf->param->ratio, fdf->param->far, fdf->param->near, p2);
				p1 = orthoProjection(fdf->param->left, fdf->param->right, fdf->param->bottom, fdf->param->top, fdf->param->near, fdf->param->far, p1);
				p2 = orthoProjection(fdf->param->left, fdf->param->right, fdf->param->bottom, fdf->param->top, fdf->param->near, fdf->param->far, p2);
				// float z_order_1 = zOrdering(p1.z, fdf->param->near, fdf->param->far);
				// float z_order_2 = zOrdering(p2.z, fdf->param->near, fdf->param->far);
				// p1.x /= p1.w;
				// p1.y /= p1.w;
				// p2.x /= p2.w;
				// p2.y /= p2.w;
				// if (z_order_1 > z_order_2)
				// {
				// 	Point4D temp = p1;
				// 	p1 = p2;
				// 	p2 = temp;
				// }
				// bresenham(img, *fdf, p1.x * fdf->param->size + fdf->window_data->width / 2, p1.y * fdf->param->size + fdf->window_data->height / 2, p2.x * fdf->param->size + fdf->window_data->width / 2, p2.y * fdf->param->size + fdf->window_data->height / 2);
				bresenham(img, *fdf, (((p1.x/p1.w))/2)*fdf->window_data->width, ((1-(p1.y))/2)*fdf->window_data->height, (((p2.x)+1)/2)*fdf->window_data->width, ((1-(p2.y))/2)*fdf->window_data->height);
			}
			i++;
		}
		actual = *actual.next_point;
	}
	mlx_put_image_to_window(fdf->mlx, fdf->win, img.img_ptr, 0, 0);
	return (img);
}
