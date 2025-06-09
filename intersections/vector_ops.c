/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_ops.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbaj <akabbaj@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 14:38:40 by akabbaj           #+#    #+#             */
/*   Updated: 2025/06/09 14:38:40 by akabbaj          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "intersections.h"

double	dot_prod(t_coords a, t_coords b)
{
	double	x;
	double	y;
	double	z;

	x = a.x * b.x;
	y = a.y * b.y;
	z = a.z * b.z;
	return (x + y + z);
}

t_coords	vect_sub(t_coords	a, t_coords b)
{
	t_coords	res;

	res.x = a.x - b.x;
	res.y = a.y - b.y;
	res.z = a.z - b.z;
	return (res);
}

t_coords	vect_add(t_coords	a, t_coords b)
{
	t_coords	res;

	res.x = a.x + b.x;
	res.y = a.y + b.y;
	res.z = a.z + b.z;
	return (res);
}

t_coords	vect_mult(t_coords a, double mult)
{
	t_coords	res;

	res.x = a.x * mult;
	res.y = a.y * mult;
	res.z = a.z * mult;
	return (res);
}