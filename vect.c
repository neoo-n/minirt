/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vect.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvauthey <dvauthey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 14:35:30 by akabbaj           #+#    #+#             */
/*   Updated: 2025/06/09 16:50:33 by dvauthey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	get_rgb(t_rgb rgb)
{
	return ((rgb.r << 16 | rgb.g << 8 | rgb.b));
}

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
