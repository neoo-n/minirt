/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vect.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvauthey <dvauthey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 14:39:30 by dvauthey          #+#    #+#             */
/*   Updated: 2025/06/05 15:31:28 by dvauthey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double	vect_norm(t_coords v)
{
	double	result;

	result = v.x * v.x + v.y * v.y + v.z * v.z;
	result = sqrt(result);
	return (result);
}

t_coords	vect_normalised(t_coords v)
{
	double	norm;

	norm = vect_norm(v);
	if (norm == 1.0)
		return (v);
	v.x = v.x / norm;
	v.y = v.y / norm;
	v.z = v.z / norm;
	return (v);
}

t_coords	vect_cross(t_coords v1, t_coords v2)
{
	t_coords	v_res;

	v_res.x = v1.y * v2.z - v1.z * v2.y;
	v_res.y = v1.z * v2.x - v1.x * v2.z;
	v_res.z = v1.x * v2.y - v1.y * v2.x;
	return (v_res);
}

t_coords	vect_y(void)
{
	t_coords	v;

	v.x = 0.0;
	v.y = 1.0;
	v.z = 0.0;
	return (v);
}

t_coords	vect_add(t_coords a, t_coords b, int i)
{
	t_coords	res;

	res.x = a.x + (i * b.x);
	res.y = a.y + (i * b.y);
	res.z = a.z + (i * b.z);
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
