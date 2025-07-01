/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbaj <akabbaj@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 13:59:54 by akabbaj           #+#    #+#             */
/*   Updated: 2025/07/01 13:59:54 by akabbaj          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "intersections.h"

double	check_in_sphere(t_coords ray, t_coords origin,
		t_shape *sphere, double t)
{
	t_coords	point;
	double		dist;

	point = vect_add(origin, vect_mult(ray, t));
	dist = vect_dist(point, sphere->coords);
	if (fabs(dist - sphere->diam / 2) > 1e-8)
		return (-1);
	return (t);
}

double	sphere_intersect(t_coords ray, t_coords origin, t_shape *sphere)
{
	double		b;
	double		c;
	double		delta;
	t_coords	sub_vect;

	sub_vect = vect_sub(origin, sphere->coords);
	b = 2 * (dot_prod(sub_vect, ray));
	c = dot_prod(sub_vect, sub_vect) - pow(sphere->diam / 2, 2);
	delta = b * b - (4 * c);
	if (delta > 0)
	{
		if ((-b - sqrt(delta)) / 2 >= 0)
			return (check_in_sphere(ray, origin, sphere,
					(-b - sqrt(delta)) / 2));
		else if ((-b + sqrt(delta)) / 2 >= 0)
			return (check_in_sphere(ray, origin, sphere,
					(-b + sqrt(delta)) / 2));
	}
	else if (delta == 0)
		if (-(b / 2) >= 0)
			return (check_in_sphere(ray, origin, sphere, -(b / 2)));
	return (-1);
}
