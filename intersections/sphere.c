/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbaj <akabbaj@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 13:38:40 by akabbaj           #+#    #+#             */
/*   Updated: 2025/06/04 15:07:14 by akabbaj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "intersections.h"

double	sphere_intersect(t_coords ray, t_coords origin, t_shape *sphere)
{
	double	b;
	double	c;
	double	delta;

	b = 2 * ((origin.x - sphere->coords.x) * ray.x + (origin.y - sphere->coords.y) * ray.y + (origin.z - sphere->coords.z) * ray.z);
	c = pow(origin.x - sphere->coords.x, 2) + pow(origin.y - sphere->coords.y, 2) + pow(origin.z - sphere->coords.z, 2) - pow(sphere->diam / 2, 2);
	delta = pow(b, 2) - (4 * c);
	if (delta > 0)
	{
		if ((-b + sqrt(delta)) / 2 < (-b - sqrt(delta)) / 2 && (-b + sqrt(delta)) / 2 >= 0)
			return ((-b + sqrt(delta)) / 2);
		else if ((-b - sqrt(delta)) / 2 < (-b + sqrt(delta)) / 2 && (-b - sqrt(delta)) / 2 >= 0)
			return ((-b - sqrt(delta)) / 2);
	}
	else if (delta == 0)
	{
		if (-(b / 2) >= 0)
			return (-(b / 2));
	}
	return (-1);
}
