/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lighting.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbaj <akabbaj@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 11:19:32 by akabbaj           #+#    #+#             */
/*   Updated: 2025/06/18 11:19:32 by akabbaj          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"

t_coords	calc_norm(t_inter shape, t_coords ray)
{
	t_coords	n;

	if (shape.shape->shape == PLANE)
	{
		n = shape.shape->vector;
		return (n);
	}
	else if (shape.shape->shape == SPHERE)
		n = vect_normalised(vect_sub(shape.point, shape.shape->coords));
	else if (shape.shape->shape == CYLINDER)
		n = cyl_n(shape);
	if (dot_prod(n, ray) > 0)
		n = vect_mult(n, -1);
	return (n);
}

int	in_shade(t_inter shape, t_gen *gen, double angle)
{
	t_coords	newray;
	t_inter		closest_shape;
	double		dist;
	double		shape_dist;
	t_coords	newpoint;

	angle = dot_prod(calc_norm(shape, shape.ray), shape.ray);
	if (angle >= -1e-6)
		return (1);
	newray = vect_normalised(vect_sub(gen->l->coords, shape.point));
	closest_shape = find_closest_shape(newray, shape.point, gen->shapes,
			shape.shape);
	if (!closest_shape.shape || closest_shape.t == -1)
		return (0);
	dist = dot_prod(vect_sub(shape.point, gen->l->coords), newray);
	newpoint = vect_add(shape.point, vect_mult(newray, closest_shape.t));
	shape_dist = dot_prod(vect_sub(shape.point, newpoint), newray);
	if (dist < shape_dist - 1e-6)
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

	if (in_shade(shape, gen, 0))
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
