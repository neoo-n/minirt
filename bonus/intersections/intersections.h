/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersections.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvauthey <dvauthey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 14:54:11 by akabbaj           #+#    #+#             */
/*   Updated: 2025/07/03 15:47:58 by dvauthey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERSECTIONS_H
# define INTERSECTIONS_H
# include "../structures.h"
# include "../minirt.h"

double	inter_dist(t_coords ray, t_coords origin, t_shape cap);
double	check_caps(t_coords ray, t_coords origin, t_shape *cyl, double t);
double	quadratic(double a, double b, double c);

double	sphere_intersect(t_coords ray, t_coords origin, t_shape *sphere);
double	plane_intersect(t_coords ray, t_coords origin, t_shape *plane);
double	cyl_intersect(t_coords ray, t_coords origin,
			t_shape *cyl, double t);
double	cone_intersect(t_coords ray, t_coords origin, t_shape *cone, double t);

#endif