/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zaxis.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbaj <akabbaj@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 14:55:25 by akabbaj           #+#    #+#             */
/*   Updated: 2025/07/03 21:54:34 by akabbaj          ###   ########.fr       */
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

void	z_press(t_vars *vars, int light_count, int shape_id)
{
	t_coords	simul;
	double		cost;
	double		sint;
	t_cam		*cam;

	shape_id = vars->obj_id - light_count - 1;
	if (vars->obj == CAM)
	{
		cam = vars->gen->c;
		simul.x = cam->coords.x + cam->vector.x - vars->screen.vect_x.x * 0.05;
		simul.y = cam->coords.y + cam->vector.y - vars->screen.vect_x.y * 0.05;
		simul.z = cam->coords.z + cam->vector.z - vars->screen.vect_x.z * 0.05;
		reassign_vector(&vars->gen->c->vector, vect_sub(simul, cam->coords));
	}
	else if (can_rotate(vars, shape_id))
	{
		cost = cos(5 * PI / 180);
		sint = sin(5 * PI / 180);
		simul.x = vars->gen->shapes[shape_id]->vector.x * cost
			- vars->gen->shapes[shape_id]->vector.y * sint;
		simul.y = vars->gen->shapes[shape_id]->vector.x * sint
			+ vars->gen->shapes[shape_id]->vector.y * cost;
		simul.z = vars->gen->shapes[shape_id]->vector.z;
		reassign_vector(&vars->gen->shapes[shape_id]->vector, simul);
	}
}

void	x_press(t_vars *vars, int light_count, int shape_id)
{
	t_coords	simul;
	double		cost;
	double		sint;
	t_cam		*cam;

	shape_id = vars->obj_id - light_count - 1;
	if (vars->obj == CAM)
	{
		cam = vars->gen->c;
		simul.x = cam->coords.x + cam->vector.x + vars->screen.vect_x.x * 0.05;
		simul.y = cam->coords.y + cam->vector.y + vars->screen.vect_x.y * 0.05;
		simul.z = cam->coords.z + cam->vector.z + vars->screen.vect_x.z * 0.05;
		reassign_vector(&vars->gen->c->vector, vect_sub(simul, cam->coords));
	}
	else if (can_rotate(vars, shape_id))
	{
		cost = cos(-5 * PI / 180);
		sint = sin(-5 * PI / 180);
		simul.x = vars->gen->shapes[shape_id]->vector.x * cost
			- vars->gen->shapes[shape_id]->vector.y * sint;
		simul.y = vars->gen->shapes[shape_id]->vector.x * sint
			+ vars->gen->shapes[shape_id]->vector.y * cost;
		simul.z = vars->gen->shapes[shape_id]->vector.z;
		reassign_vector(&vars->gen->shapes[shape_id]->vector, simul);
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
		z_press(vars, light_count, 0);
	if (button == X)
		x_press(vars, light_count, 0);
	pre_camera(vars, 0);
}
