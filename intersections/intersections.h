/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersections.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbaj <akabbaj@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 14:41:29 by akabbaj           #+#    #+#             */
/*   Updated: 2025/06/09 14:41:39 by akabbaj          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERSECTIONS_H
# define INTERSECTIONS_H
# include "../structures.h"
# include "../minirt.h"
# include <math.h>

double		sphere_intersect(t_coords ray, t_coords origin, t_shape *sphere);
double		plane_intersect(t_coords ray, t_coords origin, t_shape *plane);
double		cyl_intersect(t_coords ray, t_coords origin, t_shape *cyl, double t);
double		dot_prod(t_coords a, t_coords b);
t_coords	vect_sub(t_coords	a, t_coords b);
t_coords	vect_add(t_coords	a, t_coords b);
t_coords	vect_mult(t_coords a, double mult);

#endif