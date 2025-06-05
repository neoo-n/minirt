/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbaj <akabbaj@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 13:21:49 by akabbaj           #+#    #+#             */
/*   Updated: 2025/06/05 13:23:34 by akabbaj          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "intersections.h"

double	sphere_intersect(t_coords ray, t_coords origin, t_shape *sphere)
{
	double		b;
	double		c;
	double		delta;
	t_coords	sub_vect;

	sub_vect = vect_sub(origin, sphere->coords);
	b = 2 * (dot_prod(sub_vect, ray));
	c = dot_prod(sub_vect, sub_vect);
	delta = pow(b, 2) - (4 * c);
	if (delta > 0)
	{
		if ((-b + sqrt(delta)) / 2 < (-b - sqrt(delta)) / 2
			&& (-b + sqrt(delta)) / 2 >= 0)
			return ((-b + sqrt(delta)) / 2);
		else if ((-b - sqrt(delta)) / 2 < (-b + sqrt(delta)) / 2
			&& (-b - sqrt(delta)) / 2 >= 0)
			return ((-b - sqrt(delta)) / 2);
	}
	else if (delta == 0)
	{
		if (-(b / 2) >= 0)
			return (-(b / 2));
	}
	return (-1);
}
