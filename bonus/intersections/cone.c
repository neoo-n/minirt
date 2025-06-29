/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvauthey <dvauthey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 14:13:31 by dvauthey          #+#    #+#             */
/*   Updated: 2025/06/29 16:33:07 by dvauthey         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "intersections.h"

static double	cone_quadratic(t_coords ray, t_coords inverted_n,
	t_coords edge_cam, double alpha)
{
	double	t;
	double	dot_ray_in;
	double	dot_edgecam_in;
	double	cos_alpha;

	dot_ray_in = dot_prod(ray, inverted_n);
	dot_edgecam_in = dot_prod(edge_cam, inverted_n);
	cos_alpha = cos(alpha);
	t = quadratic(dot_ray_in * dot_ray_in - (cos_alpha * cos_alpha), 2 * (dot_ray_in
		* dot_edgecam_in - (dot_prod(ray, edge_cam) * cos_alpha * cos_alpha)),
		dot_edgecam_in * dot_edgecam_in - (dot_prod(edge_cam, edge_cam)
		* cos_alpha * cos_alpha));
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
//	t_coords	inverted_n;
	t_coords	edge_cam;
	double		alpha;
	t_coords	p;
	double		dist;

	cone->vector = vect_normalised(cone->vector);
//	inverted_n = vect_mult(cone->vector, -1);
	edge_cam = vect_sub(vect_add(cone->coords, vect_mult(cone->vector, cone->height)), origin);
	alpha = atan((cone->diam / 2) / cone->height);
	// m = vect_sub(origin, cone->coords);
	// b = vect_sub(m, vect_mult(cone->vector, dot_prod(m, cone->vector)));
	// a = vect_sub(ray, vect_mult(cone->vector, dot_prod(ray, cone->vector)));
	t = cone_quadratic(ray, cone->vector, edge_cam, alpha);
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
