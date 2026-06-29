/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madelvin <madelvin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 18:24:31 by madelvin          #+#    #+#             */
/*   Updated: 2026/06/29 16:52:39 by madelvin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

/* ************************************************************************** */
/*                                 DEFINE                                     */
/* ************************************************************************** */

# define W_WIDTH			1920
# define W_HEIGHT			1080
# define PI_F				3.141592

# define TEXT_COLOR			0xEAEAEA
# define INFO_COLOR			0xF3AF3D
# define MENU_BACKGROUND	0x1E1E1E
# define COLOR_DEFAULT		0x9A1F6A
# define COLOR_ERROR		0xC2294E

/* ************************************************************************** */
/*                              ENUMERATIONS                                  */
/* ************************************************************************** */

typedef enum e_transform
{
	DEFAULT = 1,
	TORUS,
	SPHERE
}	t_transform;

/* ************************************************************************** */
/*                              STRUCTURES                                    */
/* ************************************************************************** */

typedef struct s_color_preset
{
	int	vlow;
	int	low;
	int	medium;
	int	high;
	int	vhigh;
}	t_color_preset;

typedef struct s_gradian
{
	int		g;
	int		r;
	int		b;
	int		temp_g;
	int		temp_r;
	int		temp_b;
	float	distance;
	float	t_inc;
	float	t;
}	t_gradian;

typedef struct s_line_param
{
	int			dx;
	int			dy;
	int			sx;
	int			sy;
	int			err;
	int			e2;
	t_gradian	gradian;
}	t_line_param;

typedef struct s_img
{
	void	*img_ptr;
	char	*px_ptr;
	int		bpp;
	int		endian;
	int		line_len;
}	t_img;

typedef struct s_point_4d
{
	float	x;
	float	y;
	float	z;
	float	w;
}	t_point_4d;

typedef struct s_coord
{
	float	x;
	float	y;
	float	z;
	float	default_z;
	int		colors;
}	t_coord;

typedef struct s_line
{
	t_coord	*start;
	t_coord	*end;
	float	depth;
}	t_line;

typedef struct s_map
{
	t_coord	*point_list;
	t_coord	*map;
	int		map_max_z;
	int		map_min_z;
	int		map_size;
	int		map_width;
	int		map_height;
	int		map_ratio;
}	t_map;

typedef struct s_window_data
{
	int		width;
	int		height;
	int		x_pos;
	int		y_pos;
	char	*name;
}	t_window_data;

typedef struct s_proj
{
	float	ortho_matrix[4][4];
	float	persp_matrix[4][4];
	float	right;
	float	left;
	float	top;
	float	bottom;
}	t_proj;

typedef struct s_param
{
	float		scale;
	float		z_ratio;
	char		persp;
	char		iso;
	char		z_order;
	char		color_preset;
	t_transform	transform;
	char		selected;
}	t_param;

typedef struct s_mouse
{
	int		mouse_last_x;
	int		mouse_last_y;
	char	mouse_click_rotation;
	char	mouse_click_translation;
	char	mouse_click_wheel;
	float	mouse_sensi;
}	t_mouse;

typedef struct s_axe
{
	float	cos_axe;
	float	sin_axe;
}	t_axe;

typedef struct s_clipping
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
	float		axes_matrix[3][3];
	t_coord		coord;
	t_coord		proj_coord;
	t_clipping	clipping_planes;
	float		fov;
	float		focal;
	float		distance;
	char		focus;
	float		max_zoom;
	float		min_zoom;
}	t_camera;

typedef struct t_scene
{
	void			*mlx;
	void			*win;
	t_window_data	win_data;
	t_map			map;
	t_camera		camera;
	t_param			param;
	t_mouse			mouse;
	t_proj			proj;
	char			*file;
	t_img 			img;
}	t_scene;

/* ************************************************************************** */
/*                              FUNCTIONS                                     */
/* ************************************************************************** */

/* --- Event Listeners --- */
int		key_hook(int keycode, t_scene *scene);
int		close_window(t_scene *scene);

/* --- Rendering --- */
int		render_frame(t_scene *window);
t_img	calcule_frame(t_scene *scene);
void	draw_pixel(t_img img, t_coord p1, t_gradian *gradian);
void	draw_line(t_img img, t_coord p1, t_coord p2, t_scene scene);
void	draw_reset_button(t_img img);
void	render_hud(t_scene *scene);

/* --- Parsing --- */
void	init_map(t_scene *scene);
int		get_color(char *line);
int		get_point_color(const char *line);
int		check_entry(int argc, char *map);
int		is_valid_value(char *line, int i);

/* --- Utilities --- */
int		get_abs(int x);
int		select_value_sign(int x, int value);
void	bresenham_algo(t_img img, t_line_param param, t_coord p1, t_coord p2);

/* --- Exit Handling --- */
void	exit_handler(int return_value, char *value, t_scene *scene);

/* --- Initialization --- */
int		init_mlx(t_scene *scene);
void	init_scene(t_scene *scene, char *file);
void	init_cam(t_scene *scene, int map_height, int map_width);

/* --- Camera Calculations --- */
void	calc_axis_value(t_camera *cam);
void	calc_proj_coord(t_scene *scene);

/* --- Color Handling --- */
void	init_gradiant(int color_s, int color_e, t_gradian *gradian, int d);
void	set_color(t_coord *p1, t_scene scene);
int		blend_colors(int color_x, int gray_color, float factor);
void	init_color_preset(t_color_preset *preset, int c_preset);
int		make_color(t_gradian gradian);

/* --- HUD Utilities --- */
char	*get_iso(char iso);
char	*get_color_preset(int value);
char	*get_projection(char projection);
char	*get_transform(t_transform transorm);
char	*get_hud_value(char **actual_value, char *new_value);

/* --- Matrix Calculations --- */
void	calc_ortho_matrix(t_scene *scene);
void	calc_persp_matrix(t_scene *scene);
void	multiply_matrix_vector_4d(float matrix[4][4], float p[4]);
void	multiply_matrix_vector_3d(float matrix[3][3], float p[4]);

/* --- Mouse & Movement Handlers --- */
int		mouse_down(int keycode, int x, int y, t_scene *scene);
int		mouse_up(int keycode, int x, int y, t_scene *scene);
int		mouse_move(int x, int y, t_scene *scene);
void	select_movement(int keycode, t_scene *scene);
void	rotate(int x, int y, t_scene *scene);
void	translate(int x, int y, t_scene *scene);
void	zoom(t_scene *scene, int direction);

/* --- Transformations --- */
void	transform_to_spherical(float vector[4], t_scene *scene, int i);
void	transform_to_torus(float vector[4], t_scene *scene, int i);

#endif