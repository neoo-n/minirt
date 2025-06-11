/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specular.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvauthey <dvauthey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 11:45:55 by dvauthey          #+#    #+#             */
/*   Updated: 2025/06/11 11:55:04 by dvauthey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static t_coords	half_vect(t_vars *vars, t_coords vision, t_shape *shape)
{
	t_coords	light;

	light = vect_normalised(vect_add(vars->gen->c->coords, vect_mult(vision, shape.)));
}

void	specular(t_vars *vars, t_coords vision, t_shape *shape)
{
	t_coords	half;

	half = vect_normalised(vect_add())
}