/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lighting_helper.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbaj <akabbaj@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 15:07:59 by akabbaj           #+#    #+#             */
/*   Updated: 2025/06/30 20:28:22 by akabbaj          ###   ########.fr       */
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
		s = vect_add(shape.shape->coords, vect_mult(shape.shape->vector, shape.shape->height));
		dist_ps = vect_dist(shape.point, s);
		pc = vect_sub(s, vect_mult(shape.shape->vector, dist_ps / cos(atan((shape.shape->diam / 2) / shape.shape->height))));
		n = vect_normalised(vect_sub(shape.point, pc));
	}
	return (n);
}

t_rgb	rgb_mult(t_rgb rgb, double mult)
{
	t_rgb	res;

	res.r = rgb.r * mult;
	res.g = rgb.g * mult;
	res.b = rgb.b * mult;
	return (res);
}

t_rgb	rgb_final(t_rgb rgb, t_rgb amb, t_rgb dif, t_rgb spec)
{
	rgb.r = fmin(rgb.r * (amb.r + dif.r) + spec.r, 1);
	rgb.g = fmin(rgb.g * (amb.g + dif.g) + spec.g, 1);
	rgb.b = fmin(rgb.b * (amb.b + dif.b) + spec.b, 1);
	return (rgb);
}
