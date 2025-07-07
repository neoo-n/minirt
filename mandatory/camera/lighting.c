/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lighting.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbaj <akabbaj@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 10:21:09 by akabbaj           #+#    #+#             */
/*   Updated: 2025/07/07 10:23:43 by akabbaj          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"

t_coords	calc_norm(t_inter shape, t_coords ray)
{
	t_coords	n;

	if (shape.shape->shape == PLANE)
		n = shape.shape->vector;
	else if (shape.shape->shape == SPHERE)
		n = vect_normalised(vect_sub(shape.point, shape.shape->coords));
	else if (shape.shape->shape == CYLINDER)
		n = cyl_n(shape);
	if (dot_prod(vect_normalised(n), vect_normalised(ray)) > 0)
		n = vect_mult(n, -1);
	return (n);
}

int	in_shade(t_inter shape, t_gen *gen)
{
	t_coords	newray;
	t_inter		closest_shape;
	double		dist[2];
	t_coords	newpoint;
	t_coords	offset_point;

	newray = vect_normalised(vect_sub(gen->l->coords, shape.point));
	offset_point = vect_add(shape.point, vect_mult(shape.normal, 1e-6));
	closest_shape = find_closest_shape(newray, offset_point, gen->shapes, NULL);
	if (!closest_shape.shape || closest_shape.t == -1)
		return (0);
	dist[0] = dot_prod(vect_sub(gen->l->coords, offset_point), newray);
	newpoint = vect_add(offset_point, vect_mult(newray, closest_shape.t));
	dist[1] = dot_prod(vect_sub(newpoint, offset_point), newray);
	if (dist[1] < dist[0] - 1e-6)
		return (1);
	return (0);
}

double	calc_dif_int(t_inter shape, t_gen *gen)
{
	double		angle;
	t_coords	light_dir;

	light_dir = vect_normalised(vect_sub(gen->l->coords, shape.point));
	angle = dot_prod(shape.normal, light_dir);
	if (angle <= 1e-6)
		return (0);
	return (angle * gen->l->bright);
}

int	get_rgb(t_inter shape, t_gen *gen, double dif_int)
{
	t_rgb	dif_light;
	t_rgb	amb_light;
	t_rgb	shape_col;

	if (in_shade(shape, gen))
		dif_int = 0;
	else
		dif_int = calc_dif_int(shape, gen);
	dif_light = rgb_mult(norm_rgb(gen->l->rgb), dif_int);
	amb_light = rgb_mult(norm_rgb(gen->a->rgb), gen->a->light);
	shape_col = rgb_final(norm_rgb(shape.shape->rgb), amb_light,
			dif_light);
	return ((int)(shape_col.r * 255) << 16 | (int)(shape_col.g * 255) << 8
		| (int)(shape_col.b * 255));
}
