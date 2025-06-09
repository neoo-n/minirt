/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersections.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbaj <akabbaj@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 13:54:20 by akabbaj           #+#    #+#             */
/*   Updated: 2025/06/09 13:54:38 by akabbaj          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERSECTIONS_H
# define INTERSECTIONS_H
# include "../structures.h"
# include "../minirt.h"
# include <math.h>

double		plane_intersect(t_coords ray, t_coords origin, t_shape *plane);
double		dot_prod(t_coords a, t_coords b);
t_coords	vect_sub(t_coords	a, t_coords b);
t_coords	vect_add(t_coords	a, t_coords b);
t_coords	vect_mult(t_coords a, double mult);

#endif