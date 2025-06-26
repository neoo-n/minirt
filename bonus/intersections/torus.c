/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   torus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvauthey <dvauthey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 10:56:28 by dvauthey          #+#    #+#             */
/*   Updated: 2025/06/26 11:54:28 by dvauthey         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "intersections.h"

// double	torus_quadratic(t_coors a, t_coors b, t_shape *torus)
// {
// 	double	t1;
// 	double	r;
// 	double	a_dot;
// 	double	ab_dot;
// 	double	b_dot;

// 	r = torus->diam / 2;
// 	a_dot = dot_prod(a, a);
// 	ab_dot = dot_prod(a, b);
// 	b_dot = dot_prod(b, b);
// 	t1 = quadratic(a_dot, 2 * ab_dot, b_dot - (torus->height + r)
// 		* (torus->height + r));
// 	if (t1 == -1)
// 	{
// 		t1 = quadratic(a_dot, 2 * ab_dot, b_dot - (torus->height - r)
// 			* (torus->height - r));
// 	}
// 	return (t1);
// }

static double	dist_p_ct(t_coords p, t_coords ct, double h, t_inter *shape)
{
	t_coords	p_ct;
	double		dist;

	p_ct = vect_sub(p, ct);
	if (vect_norm(p_ct) == 0.0)
		return (-1);
	shape->center_t = vect_add(shape->shape->coords, vect_mult(p_ct, h / vect_norm(p_ct)));
	dist = vect_norm(vect_sub(p_ct, shape->center_t));
	return (dist);
}

static double	r_smaller_h(t_coords ray, t_coords origin, t_inter *shape, double t)
{
	t_coords	a;
	t_coords	b;
	t_coords	m;
	t_coords	p;
	double		dist;

	shape->shape->vector = vect_normalised(shape->shape->vector);
	m = vect_sub(origin, shape->shape->coords);
	b = vect_sub(m, vect_mult(shape->shape->vector, dot_prod(m, shape->shape->vector)));
	a = vect_sub(ray, vect_mult(shape->shape->vector, dot_prod(ray, shape->shape->vector)));
	t = quadratic(dot_prod(a, a), 2 * dot_prod(b, a), dot_prod(b, b)
		- ((shape->shape->height - shape->shape->diam / 2)
		* (shape->shape->height - shape->shape->diam / 2)));
	if (t != -1)
	{
		p = vect_add(origin, vect_mult(ray, t));
		dist = dist_p_ct(p, shape->shape->coords, shape->shape->height, shape);
		if (dist == -1 || dist < shape->shape->diam / 2 || dist > shape->shape->diam / 2)
			t = -1;
	}
	return (t);
}

double	torus_intersect(t_coords ray, t_coords origin, t_shape *torus,
	t_inter *shape)
{
	// double	diff;
	double	t;

	t = 0.0;
	// diff = torus->diam / 2 - torus->height;
	if (torus->height > -1e-6)
	{
		t = sphere_intersect(ray, origin, torus);
		shape->center_t = origin;
	}
	else 
		t = r_smaller_h(ray, origin, shape, t);
	return (t);
}
