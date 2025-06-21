/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zaxis.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbaj <akabbaj@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 22:27:54 by akabbaj           #+#    #+#             */
/*   Updated: 2025/06/21 15:30:46 by akabbaj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "key_presses.h"

void	q_press(t_vars *vars, int light_count)
{
	int	shape_id;
	int	light_id;

	light_id = vars->obj_id - 1;
	shape_id = vars->obj_id - light_count - 1;
	if (vars->obj == CAM)
	{
		vars->gen->c->coords.x += vars->gen->c->vector.x * 0.2;
		vars->gen->c->coords.y += vars->gen->c->vector.y * 0.2;
		vars->gen->c->coords.z += vars->gen->c->vector.z * 0.2;
	}
	else if (vars->obj == SHAPE)
	{
		vars->gen->shapes[shape_id]->coords.x += vars->gen->c->vector.x * 0.2;
		vars->gen->shapes[shape_id]->coords.y += vars->gen->c->vector.y * 0.2;
		vars->gen->shapes[shape_id]->coords.z += vars->gen->c->vector.z * 0.2;
	}
	else
	{
		vars->gen->l[light_id]->coords.x += vars->gen->c->vector.x * 0.2;
		vars->gen->l[light_id]->coords.y += vars->gen->c->vector.y * 0.2;
		vars->gen->l[light_id]->coords.z += vars->gen->c->vector.z * 0.2;
	}
}

void	e_press(t_vars *vars, int light_count)
{
	int	shape_id;
	int	light_id;

	light_id = vars->obj_id - 1;
	shape_id = vars->obj_id - light_count - 1;
	if (vars->obj == CAM)
	{
		vars->gen->c->coords.x -= vars->gen->c->vector.x * 0.2;
		vars->gen->c->coords.y -= vars->gen->c->vector.y * 0.2;
		vars->gen->c->coords.z -= vars->gen->c->vector.z * 0.2;
	}
	else if (vars->obj == SHAPE)
	{
		vars->gen->shapes[shape_id]->coords.x -= vars->gen->c->vector.x * 0.2;
		vars->gen->shapes[shape_id]->coords.y -= vars->gen->c->vector.y * 0.2;
		vars->gen->shapes[shape_id]->coords.z -= vars->gen->c->vector.z * 0.2;
	}
	else
	{
		vars->gen->l[light_id]->coords.x -= vars->gen->c->vector.x * 0.2;
		vars->gen->l[light_id]->coords.y -= vars->gen->c->vector.y * 0.2;
		vars->gen->l[light_id]->coords.z -= vars->gen->c->vector.z * 0.2;
	}
}

void	z_press(t_vars *vars, int light_count)

{
	int			shape_id;
	t_coords	simul;

	shape_id = vars->obj_id - light_count - 1;
	if (vars->obj == CAM)
	{
		simul.x = vars->gen->c->coords.x + vars->gen->c->vector.x - vars->screen.vect_x.x * 0.05;
		simul.y = vars->gen->c->coords.y + vars->gen->c->vector.y - vars->screen.vect_x.y * 0.05;
		simul.z = vars->gen->c->coords.z + vars->gen->c->vector.z - vars->screen.vect_x.z * 0.05;
		simul = vect_normalised(vect_sub(simul, vars->gen->c->coords));
		vars->gen->c->vector.x = simul.x;
		vars->gen->c->vector.y = simul.y;
		vars->gen->c->vector.z = simul.z;
	}
	else if (vars->gen->shapes[shape_id]->shape == PLANE
		|| vars->gen->shapes[shape_id]->shape == CYLINDER)
	{
		vars->gen->shapes[shape_id]->vector.x += vars->gen->c->vector.x * 0.2;
		vars->gen->shapes[shape_id]->vector.y += vars->gen->c->vector.y * 0.2;
		vars->gen->shapes[shape_id]->vector.z += vars->gen->c->vector.z * 0.2;
	}
}

void	x_press(t_vars *vars, int light_count)
{
	int			shape_id;
	t_coords	simul;

	shape_id = vars->obj_id - light_count - 1;
	if (vars->obj == CAM)
	{
		simul.x = vars->gen->c->coords.x + vars->gen->c->vector.x + vars->screen.vect_x.x * 0.05;
		simul.y = vars->gen->c->coords.y + vars->gen->c->vector.y + vars->screen.vect_x.y * 0.05;
		simul.z = vars->gen->c->coords.z + vars->gen->c->vector.z + vars->screen.vect_x.z * 0.05;
		simul = vect_normalised(vect_sub(simul, vars->gen->c->coords));
		vars->gen->c->vector.x = simul.x;
		vars->gen->c->vector.y = simul.y;
		vars->gen->c->vector.z = simul.z;
	}
	else if (vars->gen->shapes[shape_id]->shape == PLANE
		|| vars->gen->shapes[shape_id]->shape == CYLINDER)
	{
		vars->gen->shapes[shape_id]->vector.x += vars->gen->c->vector.x * 0.2;
		vars->gen->shapes[shape_id]->vector.y += vars->gen->c->vector.y * 0.2;
		vars->gen->shapes[shape_id]->vector.z += vars->gen->c->vector.z * 0.2;
	}
}

void	zaxis_handler(int button, t_vars *vars, int light_count)
{
	vars->state = PRERENDER;
	clear_image(&(vars->pre_img), vars->win_sizes.x_len,
		vars->win_sizes.y_height);
	if (button == Q)
		q_press(vars, light_count);
	if (button == E)
		e_press(vars, light_count);
	if (button == Z)
		z_press(vars, light_count);
	if (button == X)
		x_press(vars, light_count);
	pre_camera(vars, 0, 0);
}
