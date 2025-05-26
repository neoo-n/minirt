/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbaj <akabbaj@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 15:31:28 by akabbaj           #+#    #+#             */
/*   Updated: 2025/05/26 15:33:34 by akabbaj          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H
# include "gnl/get_next_line.h"
# include <math.h>

typedef enum e_id
{
	SPHERE,
	PLANE,
	CYLINDER,
	CONE
}	t_id;

typedef struct s_coords
{
	float	x;
	float	y;
	float	z;
}	t_coords;

typedef struct s_rgb
{
	int	r;
	int	g;
	int	b;
}	t_rgb;

typedef struct s_amb
{
	float	light;
	t_rgb	rgb;
}	t_amb;

typedef struct s_cam
{
	t_coords	coords;
	t_coords	vector;
	int			fov;
}	t_cam;

typedef struct s_light
{
	t_coords	coords;
	int			bright;
	t_rgb		rgb;
}	t_light;

typedef struct s_shape
{
	t_id		shape;
	t_coords	coords;
	float		diam;
	float		height;
	t_coords	vector;
	t_rgb		rgb;
}	t_shape;

typedef struct s_gen
{
	t_amb	*a;
	t_cam	*c;
	t_light	*l;
	t_shape	**shapes;
}	t_gen;

#endif