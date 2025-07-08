/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lighting_helper.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvauthey <dvauthey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 14:24:09 by akabbaj           #+#    #+#             */
/*   Updated: 2025/07/08 10:22:22 by dvauthey         ###   ########.fr       */
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
	else if (shape.shape->shape == CONE)
		n = co_n(shape);
	if (dot_prod(vect_normalised(n), vect_normalised(ray)) > 0)
		n = vect_mult(n, -1);
	return (n);
}

t_coords	cyl_n(t_inter shape)
{
	t_coords	n;
	t_coords	x;
	double		dist;

	dist = dot_prod(vect_sub(shape.point, shape.shape->coords),
			shape.shape->vector);
	if (fabs(dist - shape.shape->height / 2) < 1e-8)
		n = vect_normalised(shape.shape->vector);
	else if (fabs(dist + shape.shape->height / 2) < 1e-8)
		n = vect_normalised(vect_mult(shape.shape->vector, -1));
	else if (dist > -shape.shape->height / 2 && dist < shape.shape->height / 2)
	{
		x = vect_add(shape.shape->coords, vect_mult(shape.shape->vector, dist));
		n = vect_normalised(vect_sub(shape.point, x));
	}
	return (n);
}

t_coords	co_n(t_inter shape)
{
	t_coords	n;
	t_coords	s;
	t_coords	pc;
	double		dist_ps;
	double		dist;

	dist = dot_prod(vect_sub(shape.point, shape.shape->coords),
			shape.shape->vector);
	if (dist < 1e-6)
		n = vect_normalised(vect_mult(shape.shape->vector, -1));
	else if (fabs(shape.shape->height - dist) < 1e-6)
		n = vect_normalised(shape.shape->vector);
	else
	{
		s = vect_add(shape.shape->coords, vect_mult(shape.shape->vector,
					shape.shape->height));
		dist_ps = vect_dist(shape.point, s);
		pc = vect_sub(s, vect_mult(shape.shape->vector, dist_ps / cos(
						atan((shape.shape->diam / 2) / shape.shape->height))));
		n = vect_normalised(vect_sub(shape.point, pc));
	}
	return (n);
}

double	calc_fog(double t)
{
	double	fog;

	fog = (t - 30) / (100 - 30);
	if (fog > 1)
		fog = 1;
	else if (fog < 0)
		fog = 0;
	return (fog);
}

void	set_result_closestshape(t_inter *result, t_coords origin, t_coords ray)
{
	result->point = vect_add(origin, vect_mult(ray, result->t));
	result->normal = calc_norm(*result, ray);
	result->ray = ray;
}
