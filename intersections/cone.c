/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvauthey <dvauthey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 14:13:31 by dvauthey          #+#    #+#             */
/*   Updated: 2025/06/18 14:44:41 by dvauthey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "intersections.h"

double	cone_intersect(t_coords ray, t_coords origin, t_shape *cone, double t)
{
	t_coords	a;
	t_coords	b;
	t_coords	m;
	t_coords	p;
	double		angle;
	double		dist;

	cone->vector = vect_normalised(cone->vector);
	m = vect_sub(origin, cone->coords);
	b = vect_sub(m, vect_mult(cone->vector, dot_prod(m, cone->vector)));
	a = vect_sub(ray, vect_mult(cone->vector, dot_prod(ray, cone->vector)));
	angle = deg_to_rad((cone->diam * cone->diam / 4) / (cone->height * cone->height));
	t = quadratic(dot_prod(a, a), 2 * dot_prod(a, b), dot_prod(b, b)
			- (cone->diam * cone->diam / 4) * tan(angle) * tan(angle));
	if (t != -1)
	{
		p = vect_add(origin, vect_mult(ray, t));
		dist = dot_prod(vect_sub(p, cone->coords), cone->vector);
		if (dist < -(cone->height / 2) || dist > (cone->height / 2))
			t = -1;
	}
	printf("t : %f\n", t);
	t = check_caps(ray, origin, cone, t);
	return (t);
}
