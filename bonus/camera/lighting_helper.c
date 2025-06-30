/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lighting_helper.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvauthey <dvauthey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: Invalid date        by                   #+#    #+#             */
/*   Updated: 2025/06/30 16:51:14 by dvauthey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "camera.h"

t_coords	cyl_n(t_inter shape)
{
	t_coords	n;
	t_coords	x;
	double		dist;

	dist = dot_prod(vect_sub(shape.point, shape.shape->coords),
			shape.shape->vector);
	if (fabs(dist - shape.shape->height / 2) < 1e-6)
		n = vect_normalised(shape.shape->vector);
	else if (fabs(dist + shape.shape->height / 2) < 1e-6)
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
		s = vect_add(shape.shape->coords, vect_mult(shape.shape->vector, shape.shape->height));
		dist_ps = vect_dist(shape.point, s);
		pc = vect_sub(s, vect_mult(shape.shape->vector, dist_ps / cos(atan((shape.shape->diam / 2) / shape.shape->height))));
		n = vect_normalised(vect_sub(shape.point, pc));
	}
	return (n);
}
