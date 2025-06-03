/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvauthey <dvauthey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 14:38:58 by dvauthey          #+#    #+#             */
/*   Updated: 2025/06/03 11:09:55 by dvauthey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static double	theta_i(t_vars *vars, int i)
{
	double	phi;
	double	angle_pixel;
	double	theta;

	phi = vars->gen->c->fov;
	angle_pixel = phi / vars->win_sizes.x_len;
	theta = phi / 2 - (i * angle_pixel);
	return (theta);
}

t_coords	camera_vect(t_vars *vars, int i)
{
	t_coords	vect;
	double		theta;

	theta = theta_i(vars, i);
	if (i < vars->win_sizes.x_len / 2)
	{
		vect.x = cos(theta) * vars->gen->c->vector.x - sin(theta) * vars->gen->c->vector.y;
		vect.y = sin(theta) * vars->gen->c->vector.x + cos(theta) * vars->gen->c->vector.y;
		vect.z = vars->gen->c->vector.z;
	}
	else
	{
		vect.x = cos(theta) * vars->gen->c->vector.x + sin(theta) * vars->gen->c->vector.y;
		vect.y = (sin(theta) * -1) * vars->gen->c->vector.x + cos(theta) * vars->gen->c->vector.y;
		vect.z = vars->gen->c->vector.z;
	}
	return (vect);
}

void	camera(t_vars *vars)
{
	int	i;
	t_coords vect;

	i = 0;
	while (i < vars->win_sizes.x_len)
	{
		vect = camera_vect(vars, i);
		printf("vect(%f, %f, %f)\n", vect.x, vect.y, vect.z);
		i++;
	}
}
