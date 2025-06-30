/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvauthey <dvauthey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 14:13:31 by dvauthey          #+#    #+#             */
/*   Updated: 2025/06/30 11:22:58 by dvauthey         ###   ########.fr       */
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
	// t = quadratic(dot_ray_in * dot_ray_in - (cos_alpha * cos_alpha), 2 * (dot_ray_in
	// 	* dot_edgecam_in - (dot_prod(ray, edge_cam) * cos_alpha * cos_alpha)),
	// 	dot_edgecam_in * dot_edgecam_in - (dot_prod(edge_cam, edge_cam)
	// 	* cos_alpha * cos_alpha));
	t = quadratic(dot_prod(ray, ray) - ratio * dot_ray_n * dot_ray_n,
		2 * (dot_prod(cam_edge, ray) - (ratio * dot_camedge_n * dot_ray_n)
		), dot_prod(cam_edge, cam_edge) - (ratio * dot_camedge_n *
		dot_camedge_n));
	return (t);
}

static double	check_caps_cone(t_coords ray, t_coords origin, t_shape *cone, double t)
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
	// t_coords	a;
	// t_coords	b;
	// t_coords	m;
	t_coords	cam_edge;
	double		ratio;
	t_coords	p;
	double		dist;

	cone->vector = vect_normalised(cone->vector);
	cam_edge = vect_sub(origin, vect_add(cone->coords, vect_mult(cone->vector, cone->height)));
	// alpha = atan((cone->diam / 2) / cone->height);
	ratio = ((cone->diam * cone->diam / 4) / (cone->height * cone->height)) + 1;
	// m = vect_sub(origin, cone->coords);
	// b = vect_sub(m, vect_mult(cone->vector, dot_prod(m, cone->vector)));
	// a = vect_sub(ray, vect_mult(cone->vector, dot_prod(ray, cone->vector)));
	t = cone_quadratic(ray, cone->vector, cam_edge, ratio);
	// t = quadratic(dot_prod(a, a), 2 * dot_prod(a, b), (-1) * (dot_prod(b, b)
	// 		- ((cone->diam * cone->diam / 4) * pow(dot_prod(ray, cone->vector) * cone->height, 2) / (cone->height * cone->height))));
	if (t != -1)
	{
		p = vect_add(origin, vect_mult(ray, t));
		dist = dot_prod(vect_sub(p, cone->coords), cone->vector);
		if (dist < 1e-6 || dist > cone->height)
			t = -1;
	}
//	printf("t : %f\n", t);
	t = check_caps_cone(ray, origin, cone, t);
	return (t);
}
