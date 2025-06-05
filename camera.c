/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvauthey <dvauthey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 14:38:58 by dvauthey          #+#    #+#             */
/*   Updated: 2025/06/05 16:04:03 by dvauthey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static t_cam_screen	screen_calcul(t_vars *vars)
{
	t_cam_screen	screen;

	screen.len_x = tan(deg_to_rad(vars->gen->c->fov / 2)) * 2;
	screen.len_y = vars->win_sizes.y_height / vars->win_sizes.x_len * screen.len_x;
	screen.len_pix_x = screen.len_x / vars->win_sizes.x_len;
	screen.len_pix_y = screen.len_y / vars->win_sizes.y_height;
	screen.vect_x = vect_normalised(vect_cross(vect_y(), vars->gen->c->vector));
	screen.vect_y = vect_normalised(vect_cross(vars->gen->c->vector, screen.vect_x));
	screen.p_mid = vect_add(vars->gen->c->vector, vars->gen->c->coords, 1);
	return (screen);
}

static t_coords	camera_vect(t_vars *vars, int i, int j, t_cam_screen screen)
{
	t_coords	vect_ij;
	t_coords	p_ij;
	t_coords	temp;

	p_ij = vect_mult(screen.vect_x, (i * screen.len_pix_x) - (screen.len_x / 2));
	temp = vect_mult(screen.vect_y, (j * screen.len_pix_y) - (screen.len_y / 2));
	p_ij = vect_add(p_ij, temp, 1);
	p_ij = vect_add(p_ij, screen.p_mid, 1);
	vect_ij = vect_add(p_ij, vars->gen->c->coords, -1);
	vect_ij = vect_normalised(vect_ij);
	return (vect_ij);
}

void	camera(t_vars *vars)
{
	int				i;
	int				j;
	t_coords 		vect;
	t_cam_screen	screen;

	i = 0;
	screen = screen_calcul(vars);
	while (i < vars->win_sizes.x_len)
	{
		j = 0;
		while (j < vars->win_sizes.y_height)
		{
			vect = camera_vect(vars, i, j, screen);
			(void)vect;
			printf("vect(%f, %f, %f)\n", vect.x, vect.y, vect.z);
			j++;
		}
		i++;
	}
}
