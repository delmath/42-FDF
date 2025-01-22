/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madelvin <madelvin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 18:07:15 by madelvin          #+#    #+#             */
/*   Updated: 2025/01/22 18:04:49 by madelvin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define W_WIDTH			1920
# define W_HEIGHT			1080

# define PI_10D				3.1415926535

# define TEXT_COLOR			0xEAEAEA
# define BACKGROUND			0x222222
# define MENU_BACKGROUND	0x1E1E1E

# define COLOR_DISCO		0x9A1F6A
# define COLOR_BRICK_RED	0xC2294E
# define COLOR_FLAMINGO		0xEC4B27
# define COLOR_JAFFA		0xEF8633
# define COLOR_SAFFRON		0xF3AF3D

typedef struct s_img
{
	void	*img_ptr;
	char    *px_ptr;
	int		bpp;
	int		endian;
	int		line_len;
}   t_img;

typedef struct s_coord
{
	int	x;
	int	y;
	int	z;
}	t_coord;

typedef struct s_point
{
	t_coord			coordinates;
	t_coord			*linked_points;
	struct s_point	*next_point;
}	t_point;

typedef struct	s_map
{
	int		**map;
	int		map_width;
	int		map_height;
	int		map_ratio;
}	t_map;

typedef struct  s_window_data
{
	int     width;
	int     height;
	int     x_pos;
	int     y_pos;
	char    *name;
}   t_window_data;

typedef	struct s_proj
{
	float	right;
	float	left;
	float	top;
	float	bottom;
	float	focale;
}	t_proj;

typedef struct s_param
{
	float	scale;
	float	z_ratio;
}	t_param;

typedef struct s_mouse
{
	int		mouse_last_x;
	int		mouse_last_y;
	int		mouse_click_rotation;
	int		mouse_click_translation;
	float	mouse_sensibility;
}	t_mouse;

typedef	struct s_axe
{
	float	cos_axe;
	float	sin_axe;
}	t_axe;

typedef	struct s_clipping
{
	float	near;
	float	far;
	float	znear;
	float	zfar;
}	t_clipping;

typedef struct s_camera
{
	float		yaw;
	float		pitch;
	float		roll;
	t_axe		axe_yaw;
	t_axe		axe_pitch;
	t_axe		axe_roll;
	t_coord		coord;
	t_coord		proj_coord;
	t_clipping	clipping_planes;
	float		fov;
	float		focal;
	float		distance;
	
}	t_camera;

typedef struct  t_scene
{
	void            *mlx;
	void            *win;
	t_window_data   win_data;
	t_map			map;
	t_camera		camera;
	t_param			param;
	t_mouse			mouse;
	t_proj			proj;
	char			render;
	char			*file;
}   t_scene;

// listener
int     mouse_hook(int keycode, t_scene *scene);
int     key_hook(int keycode, t_scene *scene);
int     close_window(t_scene *scene);

// hud
void	write_hud(t_scene *window);
int     render_frame(t_scene *window);

// parsing
int     check_entry(int argc, char *map);
void	init_map(t_scene *scene);

// exit
void	exit_handler(int return_value, char	*value);

// calcule frame
// t_img	calcule_frame(t_scene *fdf);

// init
void	init_scene(t_scene *scene);
void	init_cam(t_camera *cam);
int		init_mlx(t_scene *scene, char *map_path);

#endif