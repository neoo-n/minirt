/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lighting_helper.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvauthey <dvauthey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 11:18:18 by akabbaj           #+#    #+#             */
/*   Updated: 2025/07/08 10:20:11 by dvauthey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"

t_rgb	norm_rgb(t_rgb rgb)
{
	rgb.r = rgb.r / 255;
	rgb.g = rgb.g / 255;
	rgb.b = rgb.b / 255;
	return (rgb);
}

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

t_rgb	rgb_mult(t_rgb rgb, double mult)
{
	t_rgb	res;

	res.r = rgb.r * mult;
	res.g = rgb.g * mult;
	res.b = rgb.b * mult;
	return (res);
}

t_rgb	rgb_final(t_rgb rgb, t_rgb amb, t_rgb dif)
{
	rgb.r = fmin(rgb.r * (amb.r + dif.r), 1);
	rgb.g = fmin(rgb.g * (amb.g + dif.g), 1);
	rgb.b = fmin(rgb.b * (amb.b + dif.b), 1);
	return (rgb);
}

void	set_result_closestshape(t_inter *result, t_coords origin, t_coords ray)
{
	result->point = vect_add(origin, vect_mult(ray, result->t));
	result->normal = calc_norm(*result, ray);
	result->ray = ray;
}
