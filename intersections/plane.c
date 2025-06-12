/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbaj <akabbaj@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 11:30:02 by akabbaj           #+#    #+#             */
/*   Updated: 2025/06/12 11:31:06 by akabbaj          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "intersections.h"

double plane_intersect(t_coords ray, t_coords origin, t_shape *plane)
{
    double denom;
    t_coords diff;
    double numerator;

    denom = dot_prod(plane->vector, ray);
    if (fabs(denom) < 1e-6)
        return (-1); // Ray is parallel to the plane

    diff = vect_sub(plane->coords, origin);
    numerator = dot_prod(diff, plane->vector);
    return (fabs(numerator/denom));
}



// #include <stdio.h>

// int	main(void)
// {
// 	t_coords	ray;
// 	t_coords	origin;
// 	t_shape		plane;

// 	ray.x = 1;
// 	ray.y = 0;
// 	ray.z = 0;
// 	origin.x = 0;
// 	origin.y = 0;
// 	origin.z = 1;
// 	plane.coords.x = 0;
// 	plane.coords.y = 0;
// 	plane.coords.z = 1;
// 	plane.vector.x = 0;
// 	plane.vector.y = 0;
// 	plane.vector.z = 1;

// 	if (plane_intersect(ray, origin, &plane) == 1)
// 		printf("Intersect\n");
// 	if (plane_intersect(ray, origin, &plane) == 0)
// 		printf("No Intersect\n");
// 	if (plane_intersect(ray, origin, &plane) == -1)
// 		printf("Parallel\n");
// }
