/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrows.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbaj <akabbaj@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 14:54:58 by akabbaj           #+#    #+#             */
/*   Updated: 2025/07/03 21:55:35 by akabbaj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "key_presses.h"

void	up_press(t_vars *vars, int light_count, int shape_id)
{
	t_coords	simul;
	double		cost;
	double		sint;
	t_cam		*cam;

	shape_id = vars->obj_id - light_count - 1;
	if (vars->obj == CAM && vars->gen->c->vector.y > -0.999)
	{
		cam = vars->gen->c;
		simul.x = cam->coords.x + cam->vector.x + vars->screen.vect_y.x * 0.05;
		simul.y = cam->coords.y + cam->vector.y + vars->screen.vect_y.y * 0.05;
		simul.z = cam->coords.z + cam->vector.z + vars->screen.vect_y.z * 0.05;
		reassign_vector(&vars->gen->c->vector, vect_sub(simul, cam->coords));
	}
	else if (can_rotate(vars, shape_id))
	{
		cost = cos(-5 * PI / 180);
		sint = sin(-5 * PI / 180);
		simul.x = vars->gen->shapes[shape_id]->vector.x * cost
			+ vars->gen->shapes[shape_id]->vector.z * sint;
		simul.y = vars->gen->shapes[shape_id]->vector.y;
		simul.z = -vars->gen->shapes[shape_id]->vector.x * sint
			+ vars->gen->shapes[shape_id]->vector.z * cost;
		reassign_vector(&vars->gen->shapes[shape_id]->vector, simul);
	}
}

void	down_press(t_vars *vars, int light_count, int shape_id)
{
	t_coords	simul;
	double		cost;
	double		sint;
	t_cam		*cam;

	shape_id = vars->obj_id - light_count - 1;
	if (vars->obj == CAM && vars->gen->c->vector.y < 0.999)
	{
		cam = vars->gen->c;
		simul.x = cam->coords.x + cam->vector.x - vars->screen.vect_y.x * 0.05;
		simul.y = cam->coords.y + cam->vector.y - vars->screen.vect_y.y * 0.05;
		simul.z = cam->coords.z + cam->vector.z - vars->screen.vect_y.z * 0.05;
		reassign_vector(&vars->gen->c->vector, vect_sub(simul, cam->coords));
	}
	else if (can_rotate(vars, shape_id))
	{
		cost = cos(5 * PI / 180);
		sint = sin(5 * PI / 180);
		simul.x = vars->gen->shapes[shape_id]->vector.x * cost
			+ vars->gen->shapes[shape_id]->vector.z * sint;
		simul.y = vars->gen->shapes[shape_id]->vector.y;
		simul.z = -vars->gen->shapes[shape_id]->vector.x * sint
			+ vars->gen->shapes[shape_id]->vector.z * cost;
		reassign_vector(&vars->gen->shapes[shape_id]->vector, simul);
	}
}

void	left_press(t_vars *vars, int light_count)

{
	int			shape_id;
	double		cost;
	double		sint;
	t_coords	final;

	shape_id = vars->obj_id - light_count - 1;
	if (vars->obj == SHAPE && (vars->gen->shapes[shape_id]->shape == PLANE
			|| vars->gen->shapes[shape_id]->shape == CYLINDER
			|| vars->gen->shapes[shape_id]->shape == CONE))
	{
		cost = cos(-5 * PI / 180);
		sint = sin(-5 * PI / 180);
		final.x = vars->gen->shapes[shape_id]->vector.x;
		final.y = vars->gen->shapes[shape_id]->vector.y * cost
			- vars->gen->shapes[shape_id]->vector.z * sint;
		final.z = vars->gen->shapes[shape_id]->vector.y * sint
			+ vars->gen->shapes[shape_id]->vector.z * cost;
		final = vect_normalised(final);
		vars->gen->shapes[shape_id]->vector.x = final.x;
		vars->gen->shapes[shape_id]->vector.y = final.y;
		vars->gen->shapes[shape_id]->vector.z = final.z;
	}
}

void	right_press(t_vars *vars, int light_count)
{
	int			shape_id;
	double		cost;
	double		sint;
	t_coords	final;

	shape_id = vars->obj_id - light_count - 1;
	if (vars->obj == SHAPE && (vars->gen->shapes[shape_id]->shape == PLANE
			|| vars->gen->shapes[shape_id]->shape == CYLINDER
			|| vars->gen->shapes[shape_id]->shape == CONE))
	{
		cost = cos(5 * PI / 180);
		sint = sin(5 * PI / 180);
		final.x = vars->gen->shapes[shape_id]->vector.x;
		final.y = vars->gen->shapes[shape_id]->vector.y * cost
			- vars->gen->shapes[shape_id]->vector.z * sint;
		final.z = vars->gen->shapes[shape_id]->vector.y * sint
			+ vars->gen->shapes[shape_id]->vector.z * cost;
		final = vect_normalised(final);
		vars->gen->shapes[shape_id]->vector.x = final.x;
		vars->gen->shapes[shape_id]->vector.y = final.y;
		vars->gen->shapes[shape_id]->vector.z = final.z;
	}
}

void	arrow_handler(int button, t_vars *vars, int light_count)
{
	vars->state = PRERENDER;
	clear_image(&(vars->pre_img), vars->win_sizes.x_len,
		vars->win_sizes.y_height);
	if (button == UP)
		up_press(vars, light_count, 0);
	if (button == DOWN)
		down_press(vars, light_count, 0);
	if (button == LEFT)
		left_press(vars, light_count);
	if (button == RIGHT)
		right_press(vars, light_count);
	pre_camera(vars, 0);
}
