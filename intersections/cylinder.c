/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbaj <akabbaj@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 11:37:01 by akabbaj           #+#    #+#             */
/*   Updated: 2025/06/11 11:38:17 by akabbaj          ###   ########.ch       */
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
	t_shape		top;
	t_shape		bottom;
	double		top_intersect;
	double		bottom_intersect;

	top.coords = vect_add(cyl->coords, vect_mult(cyl->vector, cyl->height / 2));
	top.vector = cyl->vector;
	top_intersect = plane_intersect(ray, origin, &top);
	bottom.coords = vect_sub(cyl->coords,
			vect_mult(cyl->vector, cyl->height / 2));
	bottom.vector = cyl->vector;
	bottom_intersect = plane_intersect(ray, origin, &bottom);
	if (top_intersect > 1e-6)
	{
		if (inter_dist(ray, origin, top) <= pow(cyl->diam / 2, 2))
		{
			if (top_intersect < t || t == -1)
				t = top_intersect;
		}
	}
	if (bottom_intersect > 1e-6)
	{
		if (inter_dist(ray, origin, bottom) <= pow(cyl->diam / 2, 2))
		{
			if (bottom_intersect < t || t == -1)
				t = bottom_intersect;
		}
	}
	return (t);
}

double	quadratic(double a, double b, double c)
{
	double	delta;
	double	t;

	delta = pow(b, 2) - (4 * a * c);
	if (delta < 0)
		t = -1;
	else if (delta > 0)
	{
		if ((-b + sqrt(delta)) / (2 * a) < (-b - sqrt(delta)) / (2 * a)
			&& (-b + sqrt(delta)) / (2 * a) >= 0)
			t = (-b + sqrt(delta)) / (2 * a);
		else if ((-b - sqrt(delta)) / (2 * a) < (-b + sqrt(delta)) / (2 * a)
			&& (-b - sqrt(delta)) / (2 * a) >= 0)
			t = (-b - sqrt(delta)) / (2 * a);
		else
			t = -1;
	}
	else if (delta == 0)
	{
		if (-(b / (2 * a)) >= 0)
			t = -(b / (2 * a));
		else
			t = -1;
	}
	return (t);
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

// #include <stdio.h>

// int	main(void)
// {
// 	t_coords	ray;
// 	t_coords	origin;
// 	t_shape		cyl;

// 	ray.x = 0.52;
// 	ray.y = 0.38;
// 	ray.z = 0.76;
// 	origin.x = -2.87;
// 	origin.y = 3.61;
// 	origin.z = 0;
// 	cyl.coords.x = 0.5;
// 	cyl.coords.y = 5.5;
// 	cyl.coords.z = 4.5;
// 	cyl.vector.x = -0.19;
// 	cyl.vector.y = 0.19;
// 	cyl.vector.z = 0.96;
// 	cyl.height = 5.2;
// 	cyl.diam = 2;

// 	if (cyl_intersect(ray, origin, &cyl, 0) >= 0)
// 		printf("Intersect\n");
// 	if (cyl_intersect(ray, origin, &cyl, 0) == -1)
// 		printf("No Interesect\n");
// }
