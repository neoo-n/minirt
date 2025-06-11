/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lighting.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbaj <akabbaj@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 15:39:05 by akabbaj           #+#    #+#             */
/*   Updated: 2025/06/11 15:39:12 by akabbaj          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"

t_coords	calc_norm(t_shape *shape, t_coords ray, t_coords origin)
{
	t_coords	n;
	t_coords	x;
	t_coords	point;
	double		dist;

	if (shape->shape == PLANE)
		return (shape->vector);
	point = vect_add(origin, vect_mult(ray, shape->t));
	if (shape->shape == SPHERE)
		n = vect_normalised(vect_sub(point, shape->coords));
	if (shape->shape == CYLINDER)
	{
		dist = dot_prod(vect_sub(point, shape->coords), shape->vector);

		if (fabs(dist - shape->height / 2) < 1e-6)
			n = vect_normalised(shape->vector);
		else if (fabs(dist + shape->height / 2) < 1e-6)
			n = vect_normalised(vect_mult(shape->vector, -1));
		else if (dist > -shape->height / 2 && dist < shape->height / 2)
		{
			x = vect_add(shape->coords, vect_mult(shape->vector, dist));
			n = vect_normalised(vect_sub(point, x));
		}
	}	
	return (n);
}

int	in_shade(t_shape *shape, t_gen *gen, t_coords ray, t_coords origin)
{
	t_coords	point;
	t_coords	newray;
	t_shape		*closest_shape;
	double		dist;
	double 		shape_dist;
	t_coords	newpoint;

	point = vect_add(origin, vect_mult(ray, shape->t));
	newray = vect_normalised(vect_sub(gen->l->coords, point));
	closest_shape = find_closest_shape(newray, point, gen->shapes, shape);
	if (!closest_shape || closest_shape->t == -1 || closest_shape->shape == PLANE)
		return (0);
	dist = dot_prod(vect_sub(point, gen->l->coords), newray);
	newpoint = vect_add(point, vect_mult(newray, closest_shape->t));
	shape_dist = dot_prod(vect_sub(point, newpoint), newray);
	if (dist < shape_dist)
		return (1);
	return (0);
}

double	calc_dif_int(t_shape *shape, t_gen *gen, t_coords ray, t_coords origin)
{
	t_coords	n;
	double		angle;
	t_coords	point;
	t_coords	light_dir;
	double		dist;

	point = vect_add(origin, vect_mult(ray, shape->t));
	light_dir = vect_normalised(vect_sub(gen->l->coords, point));
	n = calc_norm(shape, ray, origin);
	if (shape->shape == PLANE)
	{
		if (dot_prod(n, light_dir) > 1e-6)
			n = vect_mult(n, -1);
	}
	else if (shape->shape == CYLINDER)
	{
		dist = dot_prod(vect_sub(point, shape->coords), shape->vector);
		if (dist >= shape->height / 2 - 1e-6 || dist <= -shape->height / 2 - 1e-6)
		{
			if (dot_prod(n, light_dir) > 1e-6)
				n = vect_mult(n, -1);
		}
	}
	angle = dot_prod(n, light_dir);
	if (shape->shape == PLANE)
		return (fabs(angle * gen->l->bright));
	if (angle <= 0)
		return (0);
	return (angle * gen->l->bright);
}

int	get_rgb(t_shape *shape, t_gen *gen, t_coords ray, t_coords origin)
{
	double	dif_int;

	dif_int = calc_dif_int(shape, gen, ray, origin);
	if (in_shade(shape, gen, ray, origin))
		dif_int = 0;
	// if (shape->shape == PLANE)
	// 	printf("%f\n", dif_int);
	return ((int)(shape->rgb.r * fmin(dif_int + gen->a->light, 1)) << 16 | (int)(shape->rgb.g * fmin(dif_int + gen->a->light, 1)) << 8 | (int)(shape->rgb.b * fmin(dif_int + gen->a->light, 1)));
}
