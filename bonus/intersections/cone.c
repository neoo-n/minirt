/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvauthey <dvauthey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 14:13:31 by dvauthey          #+#    #+#             */
/*   Updated: 2025/06/30 17:03:19 by dvauthey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "intersections.h"

static double	cone_quadratic(t_coords ray, t_coords n,
	t_coords cam_edge, double ratio)
{
	double	t;
	double	dot_ray_n;
	double	dot_camedge_n;

	dot_ray_n = dot_prod(ray, n);
	dot_camedge_n = dot_prod(cam_edge, n);
	t = quadratic(dot_prod(ray, ray) - ratio * dot_ray_n * dot_ray_n,
			2 * (dot_prod(cam_edge, ray) - (ratio * dot_camedge_n * dot_ray_n)
				), dot_prod(cam_edge, cam_edge) - (ratio * dot_camedge_n
				* dot_camedge_n));
	return (t);
}

static double	check_caps_cone(t_coords ray, t_coords origin, t_shape *cone,
	double t)
{
	double		intersect;

	intersect = plane_intersect(ray, origin, cone);
	if (intersect > 1e-6)
		if (inter_dist(ray, origin, *cone) <= pow(cone->diam / 2, 2))
			if (intersect < t || t == -1)
				t = intersect;
	return (t);
}

double	cone_intersect(t_coords ray, t_coords origin, t_shape *cone, double t)
{
	t_coords	cam_edge;
	double		ratio;
	t_coords	p;
	double		dist;

	cone->vector = vect_normalised(cone->vector);
	cam_edge = vect_sub(origin, vect_add(cone->coords, vect_mult(cone->vector,
					cone->height)));
	ratio = ((cone->diam * cone->diam / 4) / (cone->height * cone->height)) + 1;
	t = cone_quadratic(ray, cone->vector, cam_edge, ratio);
	if (t != -1)
	{
		p = vect_add(origin, vect_mult(ray, t));
		dist = dot_prod(vect_sub(p, cone->coords), cone->vector);
		if (dist < 1e-6 || dist > cone->height)
			t = -1;
	}
	t = check_caps_cone(ray, origin, cone, t);
	return (t);
}
