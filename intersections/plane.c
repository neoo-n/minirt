/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbaj <akabbaj@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 13:25:41 by akabbaj           #+#    #+#             */
/*   Updated: 2025/06/05 13:27:56 by akabbaj          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "intersections.h"

double	plane_intersect(t_coords ray, t_coords origin, t_shape *plane)
{
	double	x;
	double	y;
	double	z;
	double	val;
	double	mult;

	x = plane->vector.x * origin.x - plane->vector.x * plane->coords.x;
	y = plane->vector.y * origin.y - plane->vector.y * plane->coords.y;
	z = plane->vector.z * origin.z - plane->vector.z * plane->coords.z;
	val = -(x + y + z);
	mult = dot_prod(plane->vector, ray);
	if (mult == 0 && val == 0)
		return (0);
	else if (mult == 0)
		return (-1);
	else
		return (val / mult);
}

#include <stdio.h>

int	main(void)
{
	t_coords	ray;
	t_coords	origin;
	t_shape		plane;

	ray.x = 1;
	ray.y = 0;
	ray.z = 0;
	origin.x = 0;
	origin.y = 0;
	origin.z = 1;
	plane.coords.x = 0;
	plane.coords.y = 0;
	plane.coords.z = 1;
	plane.vector.x = 0;
	plane.vector.y = 0;
	plane.vector.z = 1;

	if (plane_intersect(ray, origin, &plane) == 1)
		printf("Intersect\n");
	if (plane_intersect(ray, origin, &plane) == 0)
		printf("No Intersect\n");
	if (plane_intersect(ray, origin, &plane) == -1)
		printf("Parallel\n");
}
