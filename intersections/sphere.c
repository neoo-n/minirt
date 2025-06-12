/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbaj <akabbaj@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 13:30:01 by akabbaj           #+#    #+#             */
/*   Updated: 2025/06/12 10:53:25 by akabbaj          ###   ########.ch       */
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
	if (fabs(dist - sphere->diam / 2) > 1e-6)
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

// #include <stdio.h>

// int	main(void)
// {
// 	t_coords	ray;
// 	t_coords	origin;
// 	t_shape		cyl;

// 	ray.x = 0.85;
// 	ray.y = -0.1;
// 	ray.z = 0.52;
// 	origin.x = -2.87;
// 	origin.y = 3.61;
// 	origin.z = 0;
// 	cyl.coords.x = 3.8;
// 	cyl.coords.y = 4.07;
// 	cyl.coords.z = 2.58;
// 	// cyl.vector.x = -0.19;
// 	// cyl.vector.y = 0.19;
// 	// cyl.vector.z = 0.96;
// 	// cyl.height = 5.2;
// 	cyl.diam = 5.19;

// 	if (sphere_intersect(ray, origin, &cyl) >= 0)
// 		printf("Intersect\n");
// 	if (sphere_intersect(ray, origin, &cyl) == -1)
// 		printf("No Interesect \n");
// }