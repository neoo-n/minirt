/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbaj <akabbaj@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 10:45:26 by akabbaj           #+#    #+#             */
/*   Updated: 2025/07/07 10:45:26 by akabbaj          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H
# include <math.h>
# include <fcntl.h>
# define W 119
# define A 97
# define S 115
# define D 100
# define Q 113
# define E 101
# define ZERO 48
# define NINE 57
# define X 120
# define Z 122
# define UP 65362
# define DOWN 65364
# define LEFT 65361
# define RIGHT 65363
# define PLUS 61
# define MINUS 45
# define ENTER 65293
# define H 104
# define J 106
# define K 107
# define L 108
# define R 114
# define G 103
# define B 98
# define PIXELS 10
# ifndef X_LEN
#  define X_LEN 1920.0
# endif
# ifndef Y_HEIGHT
#  define Y_HEIGHT 1080.0
# endif
# ifndef SHINY
#  define SHINY 25
# endif
# ifndef ROUGH
#  define ROUGH 0.9
# endif

typedef enum e_bool
{
	TRUE = 1,
	FALSE = 0,
}	t_bool;

typedef enum e_toggle
{
	ON,
	OFF,
}	t_toggle;

typedef enum e_state
{
	RENDER,
	PRERENDER,
	RENDERING,
}	t_state;

typedef enum e_id
{
	SPHERE,
	PLANE,
	CYLINDER,
	CONE,
}	t_id;

typedef enum e_type
{
	CLOSE,
	MENU,
	ARROW_L,
	ARROW_R,
	TEXT,
	EMPTY,
	PRINT,
	SETTINGS,
	RESET,
	ADD_OBJ,
	LIGHT_ADD,
	CYL_ADD,
	PLANE_ADD,
	SPHERE_ADD,
	CONE_ADD,
	TOR_ADD,
}	t_type;

typedef enum e_obj
{
	CAM,
	LIGHT,
	SHAPE,
	SETT,
	NONE,
}	t_obj;

typedef enum e_mode
{
	HIDDEN,
	BASIC,
	OBJECT_SELECT,
	OBJECT_SELECT_ARROWS,
	OBJECT_SELECT_LASTPAGE,
	OBJECT_SETTINGS,
	GLOBAL_SETTINGS,
	OBJ_ADD,
	RED,
	GREEN,
	BLUE,
}	t_mode;

typedef enum e_errmes
{
	NO_FILE,
	NO_ARGS,
	INVALID_EXT,
	INCOMP_ELEM,
	PARSE_ERR
}	t_errmes;

typedef struct s_button
{
	int		bx;
	int		ex;
	int		by;
	int		ey;
	int		colour;
	t_type	type;
	char	*text;
}	t_button;

typedef struct s_text
{
	int		size;
	int		x;
	int		y;
	int		max_char;
	char	*text;
	int		colour;
}	t_text;

typedef struct s_coords
{
	double	x;
	double	y;
	double	z;
	int		valid;
}	t_coords;

typedef struct s_letter
{
	int		i;
	int		j;
	int		size;
	char	letter;
	int		colour;
}	t_letter;

typedef struct s_character
{
	char				c;
	int					grid[7][5];
	struct s_character	*next;
}	t_character;

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
	t_amb			*a;
	t_cam			*c;
	t_light			**l;
	t_shape			**shapes;
	t_character		*character;
	struct s_gen	*saved_gen;
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
	void			*mlx;
	void			*win;
	t_dataimg		img;
	t_dataimg		img_copy;
	t_dataimg		pre_img;
	t_dataimg		pre_img_copy;
	t_dataimg		loading_image;
	t_win_size		win_sizes;
	t_gen			*gen;
	int				colour;
	t_mode			mode;
	t_obj			obj;
	int				obj_id;
	int				light_count;
	int				shape_count;
	int				page_num;
	t_state			state;
	long			starttime;
	t_toggle		shadow;
	t_toggle		specular;
	t_toggle		ambient;
	t_toggle		diffuse;
	t_cam_screen	screen;
}	t_vars;

typedef struct s_data
{
	t_vars	*vars;
	int		sx;
	int		ex;
	int		i;
	int		j;
}	t_data;

#endif