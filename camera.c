/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvauthey <dvauthey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 16:17:00 by akabbaj           #+#    #+#             */
/*   Updated: 2025/06/09 16:40:32 by dvauthey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "intersections/intersections.h"

static t_cam_screen	screen_calcul(t_vars *vars)
{
	t_cam_screen	screen;

	screen.len_x = tan(deg_to_rad(vars->gen->c->fov / 2.0)) * 2.0;
	screen.len_y = vars->win_sizes.y_height / vars->win_sizes.x_len * screen.len_x;
	screen.len_pix_x = screen.len_x / vars->win_sizes.x_len;
	screen.len_pix_y = screen.len_y / vars->win_sizes.y_height;
	screen.vect_x = vect_normalised(vect_cross(vect_y(), vars->gen->c->vector));
	screen.vect_y = vect_normalised(vect_cross(vars->gen->c->vector, screen.vect_x));
	screen.p_mid = vect_add(vars->gen->c->vector, vars->gen->c->coords);
	return (screen);
}

static t_coords	camera_vect(t_vars *vars, int i, int j, t_cam_screen screen)
{
	t_coords	vect_ij;
	t_coords	p_ij;
	t_coords	temp;

	p_ij = vect_mult(screen.vect_x, (i * screen.len_pix_x) - (screen.len_x / 2));
	temp = vect_mult(screen.vect_y, (j * screen.len_pix_y) - (screen.len_y / 2));
	p_ij = vect_add(p_ij, temp);
	p_ij = vect_add(p_ij, screen.p_mid);
	vect_ij = vect_sub(p_ij, vars->gen->c->coords);
	vect_ij = vect_normalised(vect_ij);
	return (vect_ij);
}

t_shape	*find_closest_shape(t_coords ray, t_coords origin, t_shape **shapes)
{
	int		i;
	int		j;
	float	t;
	float	ot;

	i = 0;
	ot = -1;
	while (shapes[i])
	{
		if (shapes[i]->shape == CYLINDER)
			t = cyl_intersect(ray, origin, shapes[i], 0);
		if (shapes[i]->shape == SPHERE)
			t = sphere_intersect(ray, origin, shapes[i]);
		if (shapes[i]->shape == PLANE)
			t = plane_intersect(ray, origin, shapes[i]);
		if ((ot == -1 || t < ot) && t != -1)
		{
			j = i;
			ot = t;
		}
		i++;
	}
	if (ot == -1)
		return (0);
	return (shapes[j]);
}

void	camera(t_vars *vars)
{
	int				i;
	int				j;
	t_shape			*shape;
	t_coords		vect;
	t_cam_screen	screen;

	i = 0;
	screen = screen_calcul(vars);
	while (i < vars->win_sizes.x_len)
	{
		j = 0;
		while (j < vars->win_sizes.y_height)
		{
			vect = camera_vect(vars, i, j, screen);
			shape = find_closest_shape(vect, vars->gen->c->coords, vars->gen->shapes);
			if (shape)
				my_mlx_pixel_put(&(vars->img), i, j, get_rgb(shape->rgb));
			j++;
		}
		i++;
	}
}
