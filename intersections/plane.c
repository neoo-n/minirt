/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbaj <akabbaj@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 13:37:20 by akabbaj           #+#    #+#             */
/*   Updated: 2025/06/04 13:38:31 by akabbaj          ###   ########.fr       */
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
	mult = plane->vector.x * ray.x + plane->vector.y * ray.y + plane->vector.z * ray.z;
	if (mult == 0 && val == 0)
		return -1;//infinite;
	else if (mult == 0)
		return 0;// no intersect
	else
		return (val / mult);//(val / mult);
}