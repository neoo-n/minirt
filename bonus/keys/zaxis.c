/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zaxis.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbaj <akabbaj@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 14:55:25 by akabbaj           #+#    #+#             */
/*   Updated: 2025/07/03 14:55:30 by akabbaj          ###   ########.ch       */
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
		simul.x = vars->gen->c->coords.x + vars->gen->c->vector.x
			- vars->screen.vect_x.x * 0.05;
		simul.y = vars->gen->c->coords.y + vars->gen->c->vector.y
			- vars->screen.vect_x.y * 0.05;
		simul.z = vars->gen->c->coords.z + vars->gen->c->vector.z
			- vars->screen.vect_x.z * 0.05;
		simul = vect_normalised(vect_sub(simul, vars->gen->c->coords));
		vars->gen->c->vector.x = simul.x;
		vars->gen->c->vector.y = simul.y;
		vars->gen->c->vector.z = simul.z;
	}
	else if (vars->obj == SHAPE && (vars->gen->shapes[shape_id]->shape == PLANE
			|| vars->gen->shapes[shape_id]->shape == CYLINDER || vars->gen->shapes[shape_id]->shape == CONE))
	{
		double cost;
		double sint;
		t_coords final;
		cost = cos(5 * PI / 180);
		sint = sin(5 * PI / 180);
		final.x = vars->gen->shapes[shape_id]->vector.x * cost - vars->gen->shapes[shape_id]->vector.y * sint;
		final.y = vars->gen->shapes[shape_id]->vector.x * sint + vars->gen->shapes[shape_id]->vector.y * cost;
		final.z = vars->gen->shapes[shape_id]->vector.z;
		final = vect_normalised(final);
		vars->gen->shapes[shape_id]->vector.x = final.x;
		vars->gen->shapes[shape_id]->vector.y = final.y;
		vars->gen->shapes[shape_id]->vector.z = final.z;
	}
}

void	x_press(t_vars *vars, int light_count)
{
	int			shape_id;
	t_coords	simul;

	shape_id = vars->obj_id - light_count - 1;
	if (vars->obj == CAM)
	{
		simul.x = vars->gen->c->coords.x + vars->gen->c->vector.x
			+ vars->screen.vect_x.x * 0.05;
		simul.y = vars->gen->c->coords.y + vars->gen->c->vector.y
			+ vars->screen.vect_x.y * 0.05;
		simul.z = vars->gen->c->coords.z + vars->gen->c->vector.z
			+ vars->screen.vect_x.z * 0.05;
		simul = vect_normalised(vect_sub(simul, vars->gen->c->coords));
		vars->gen->c->vector.x = simul.x;
		vars->gen->c->vector.y = simul.y;
		vars->gen->c->vector.z = simul.z;
	}
	else if (vars->obj == SHAPE && (vars->gen->shapes[shape_id]->shape == PLANE
			|| vars->gen->shapes[shape_id]->shape == CYLINDER || vars->gen->shapes[shape_id]->shape == CONE))
	{
		double cost;
		double sint;
		t_coords final;
		cost = cos(-5 * PI / 180);
		sint = sin(-5 * PI / 180);
		final.x = vars->gen->shapes[shape_id]->vector.x * cost - vars->gen->shapes[shape_id]->vector.y * sint;
		final.y = vars->gen->shapes[shape_id]->vector.x * sint + vars->gen->shapes[shape_id]->vector.y * cost;
		final.z = vars->gen->shapes[shape_id]->vector.z;
		final = vect_normalised(final);
		vars->gen->shapes[shape_id]->vector.x = final.x;
		vars->gen->shapes[shape_id]->vector.y = final.y;
		vars->gen->shapes[shape_id]->vector.z = final.z;
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
	pre_camera(vars, 0);
}
