/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbaj <akabbaj@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 10:35:35 by akabbaj           #+#    #+#             */
/*   Updated: 2025/07/08 10:36:29 by akabbaj          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "intersections.h"

double	plane_intersect(t_coords ray, t_coords origin, t_shape *plane)
{
	double		denom;
	t_coords	diff;
	t_coords	temp;
	double		numerator;
	double		t;

	temp = vect_sub(origin, plane->coords);
	if (dot_prod(temp, plane->vector) == 0)
		return (0);
	denom = dot_prod(plane->vector, ray);
	if (fabs(denom) < 1e-8)
		return (-1);
	diff = vect_sub(plane->coords, origin);
	numerator = dot_prod(diff, plane->vector);
	t = numerator / denom;
	if (t < 1e-8)
		return (-1);
	return (t);
}
