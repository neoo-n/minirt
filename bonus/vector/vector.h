/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbaj <akabbaj@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 16:19:21 by akabbaj           #+#    #+#             */
/*   Updated: 2025/07/07 16:19:35 by akabbaj          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H
# include "../structures.h"
# include "../minirt.h"

double		vect_norm(t_coords v);
t_coords	vect_normalised(t_coords v);
t_coords	vect_cross(t_coords v1, t_coords v2);
t_coords	vect_y(void);
t_coords	vect_x(void);
double		dot_prod(t_coords a, t_coords b);
t_coords	vect_sub(t_coords	a, t_coords b);
t_coords	vect_add(t_coords	a, t_coords b);
t_coords	vect_mult(t_coords a, double mult);
double		vect_dist(t_coords a, t_coords b);

#endif