/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersections.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbaj <akabbaj@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 13:29:43 by akabbaj           #+#    #+#             */
/*   Updated: 2025/06/10 13:29:43 by akabbaj          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERSECTIONS_H
# define INTERSECTIONS_H
# include "../structures.h"
# include "../minirt.h"

double		sphere_intersect(t_coords ray, t_coords origin, t_shape *sphere);
double		plane_intersect(t_coords ray, t_coords origin, t_shape *plane);
double		cyl_intersect(t_coords ray, t_coords origin,
				t_shape *cyl, double t);

#endif