/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvauthey <dvauthey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 14:38:58 by dvauthey          #+#    #+#             */
/*   Updated: 2025/06/02 15:12:25 by dvauthey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static double	theta_i(t_vars *vars, int i, double angle_pixel)
{
	double	phi;
	double	theta;

	phi = vars->gen->c->fov;
	theta = phi / 2 - (i * angle_pixel);
	return (theta);
}

t_coords	camera_vect(t_vars *vars, int i)
{
	t_coords	vect;
	double		angle_pixel;
	double		theta;

	angle_pixel = vars->gen->c->fov / vars->win_sizes.x_len;
	theta = theta_i(vars, i, angle_pixel);
	if (i < vars->win_sizes.x_len / 2)
	{
		vect.x = cos(theta) * vars->gen->c->coords.x - sin(theta) * vars->gen->c->coords.y;
		vect.y = sin(theta) * vars->gen->c->coords.x + cos(theta) * vars->gen->c->coords.y;
		vect.z = vars->gen->c->coords.z;
	}
	else
	{
		vect.x = cos(theta) * vars->gen->c->coords.x + sin(theta) * vars->gen->c->coords.y;
		vect.y = (sin(theta) * -1) * vars->gen->c->coords.x + cos(theta) * vars->gen->c->coords.y;
		vect.z = vars->gen->c->coords.z;
	}
	return (vect);
}

void	camera(t_vars *vars)
{
	int	index[2];

	index[0] = 0;
	index[1] = 0;
	
}