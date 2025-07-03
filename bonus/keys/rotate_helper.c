/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_helper.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbaj <akabbaj@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 21:04:07 by akabbaj           #+#    #+#             */
/*   Updated: 2025/07/03 21:55:03 by akabbaj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "key_presses.h"

void	reassign_vector(t_coords *dst, t_coords src)
{
	src = vect_normalised(src);
	dst->x = src.x;
	dst->y = src.y;
	dst->z = src.z;
}

int	can_rotate(t_vars *vars, int shape_id)
{
	if (vars->obj == SHAPE && (vars->gen->shapes[shape_id]->shape == PLANE
			|| vars->gen->shapes[shape_id]->shape == CYLINDER
			|| vars->gen->shapes[shape_id]->shape == CONE))
		return (1);
	return (0);
}
