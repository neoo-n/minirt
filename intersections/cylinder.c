/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   settings.json                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbaj <akabbaj@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 15:16:26 by akabbaj           #+#    #+#             */
/*   Updated: 2025/06/16 15:19:12 by akabbaj          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "intersections.h"

double	inter_dist(t_coords ray, t_coords origin, t_shape cap)
{
	double		plane_inter;
	t_coords	mult;
	t_coords	addition;
	t_coords	subtraction;
	double		product;

	plane_inter = plane_intersect(ray, origin, &cap);
	mult = vect_mult(ray, plane_inter);
	addition = vect_add(origin, mult);
	subtraction = vect_sub(addition, cap.coords);
	product = dot_prod(subtraction, subtraction);
	return (product);
}

double	check_caps(t_coords ray, t_coords origin, t_shape *cyl, double t)
{
	t_shape		cap;
	double		intersect;

	cap.coords = vect_add(cyl->coords, vect_mult(cyl->vector, cyl->height / 2));
	cap.vector = cyl->vector;
	intersect = plane_intersect(ray, origin, &cap);
	if (intersect > 1e-6)
		if (inter_dist(ray, origin, cap) <= pow(cyl->diam / 2, 2))
			if (intersect < t || t == -1)
				t = intersect;
	cap.coords = vect_sub(cyl->coords,
			vect_mult(cyl->vector, cyl->height / 2));
	cap.vector = cyl->vector;
	intersect = plane_intersect(ray, origin, &cap);
	if (intersect > 1e-6)
		if (inter_dist(ray, origin, cap) <= pow(cyl->diam / 2, 2))
			if (intersect < t || t == -1)
				t = intersect;
	return (t);
}

double	quadratic(double a, double b, double c)
{
	double	delta;
	double	t1;
	double	t2;

	delta = pow(b, 2) - (4 * a * c);
	if (delta < 0)
		return (-1);
	t1 = (-b + sqrt(delta)) / (2 * a);
	t2 = (-b - sqrt(delta)) / (2 * a);
	if (t1 >= 0 && t2 >= 0)
	{
		if (t1 < t2)
			return (t1);
		return (t2);
	}
	else if (t1 >= 0)
		return (t1);
	else if (t2 >= 0)
		return (t2);
	return (-1);
}

double	cyl_intersect(t_coords ray, t_coords origin, t_shape *cyl, double t)
{
	t_coords	a;
	t_coords	b;
	t_coords	m;
	t_coords	p;
	double		dist;

	cyl->vector = vect_normalised(cyl->vector);
	m = vect_sub(origin, cyl->coords);
	b = vect_sub(m, vect_mult(cyl->vector, dot_prod(m, cyl->vector)));
	a = vect_sub(ray, vect_mult(cyl->vector, dot_prod(ray, cyl->vector)));
	t = quadratic(dot_prod(a, a), 2 * dot_prod(a, b), dot_prod(b, b)
			- pow(cyl->diam / 2, 2));
	if (t != -1)
	{
		p = vect_add(origin, vect_mult(ray, t));
		dist = dot_prod(vect_sub(p, cyl->coords), cyl->vector);
		if (dist < -(cyl->height / 2) || dist > (cyl->height / 2))
			t = -1;
	}
	t = check_caps(ray, origin, cyl, t);
	return (t);
}
