/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbaj <akabbaj@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 14:09:23 by akabbaj           #+#    #+#             */
/*   Updated: 2025/06/21 16:28:46 by akabbaj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "intersections.h"

double	plane_intersect(t_coords ray, t_coords origin, t_shape *plane)
{
	double		denom;
	t_coords	diff;
	double		numerator;
	double		t;

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
