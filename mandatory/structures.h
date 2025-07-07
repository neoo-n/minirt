/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbaj <akabbaj@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 10:09:11 by akabbaj           #+#    #+#             */
/*   Updated: 2025/07/07 10:09:21 by akabbaj          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H
# include <math.h>
# include <fcntl.h>

typedef enum e_id
{
	SPHERE,
	PLANE,
	CYLINDER
}	t_id;

typedef enum e_errmes
{
	NO_FILE,
	NO_ARGS,
	INVALID_EXT,
	INCOMP_ELEM,
	PARSE_ERR
}	t_errmes;

typedef struct s_coords
{
	double	x;
	double	y;
	double	z;
	int		valid;
}	t_coords;

typedef struct s_rgb
{
	double	r;
	double	g;
	double	b;
}	t_rgb;

typedef struct s_amb
{
	double	light;
	t_rgb	rgb;
}	t_amb;

typedef struct s_cam
{
	t_coords	coords;
	t_coords	vector;
	double		fov;
}	t_cam;

typedef struct s_cam_screen
{
	t_coords	vect_x;
	t_coords	vect_y;
	double		len_x;
	double		len_y;
	double		len_pix_x;
	double		len_pix_y;
	t_coords	p_mid;
}	t_cam_screen;

typedef struct s_light
{
	t_coords	coords;
	double		bright;
	t_rgb		rgb;
}	t_light;

typedef struct s_shape
{
	t_id		shape;
	t_coords	coords;
	double		diam;
	double		height;
	t_coords	vector;
	t_rgb		rgb;
}	t_shape;

typedef struct s_inter
{
	t_shape		*shape;
	double		t;
	t_coords	point;
	t_coords	normal;
	t_coords	ray;
}	t_inter;

typedef struct s_gen
{
	t_amb	*a;
	t_cam	*c;
	t_light	*l;
	t_shape	**shapes;
}	t_gen;

typedef struct s_dataimg
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_dataimg;

typedef struct s_win_size
{
	float	x_len;
	float	y_height;
}	t_win_size;

typedef struct s_vars
{
	void		*mlx;
	void		*win;
	t_dataimg	img;
	t_win_size	win_sizes;
	t_gen		*gen;
	int			epsilon;
}	t_vars;

#endif