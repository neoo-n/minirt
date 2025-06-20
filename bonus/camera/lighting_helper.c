/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lighting_helper.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvauthey <dvauthey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 15:07:59 by akabbaj           #+#    #+#             */
/*   Updated: 2025/06/20 13:35:39 by dvauthey         ###   ########.fr       */
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
