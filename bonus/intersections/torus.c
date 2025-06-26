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

double	torus_quadratic(t_coors a, t_coors b, t_shape *torus)
{
	double	t1;
	double	r;
	double	a_dot;
	double	ab_dot;
	double	b_dot;

	r = torus->diam / 2;
	a_dot = dot_prod(a, a);
	ab_dot = dot_prod(a, b);
	b_dot = dot_prod(b, b);
	t1 = quadratic(a_dot, 2 * ab_dot, b_dot - (torus->height + r)
		* (torus->height + r));
	if (t1 == -1)
	{
		t1 = quadratic(a_dot, 2 * ab_dot, b_dot - (torus->height - r)
			* (torus->height - r));
	}
	return (t1);
}

double	torus_intersect(t_coords ray, t_coords origin, t_shape *torus, double t)
{
	t_coords	a;
	t_coords	b;
	t_coords	m;
	t_coords	p;
	double		dist;

	torus->vector = vect_normalised(torus->vector);
	m = vect_sub(origin, torus->coords);
	b = vect_sub(m, vect_mult(torus->vector, dot_prod(m, torus->vector)));
	a = vect_sub(ray, vect_mult(torus->vector, dot_prod(ray, torus->vector)));
	t = torus_quadratic(a, b, torus);
	if (t != -1)
	{
		p = vect_add(origin, vect_mult(ray, t));
		dist = dot_prod(vect_sub(p, torus->coords), torus->vector);
		if (dist < -(torus->height / 2) || dist > (torus->height / 2))
			t = -1;
	}
	return (t);
}
