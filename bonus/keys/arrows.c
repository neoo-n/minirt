/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrows.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbaj <akabbaj@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 11:51:57 by akabbaj           #+#    #+#             */
/*   Updated: 2025/07/01 15:06:22 by akabbaj          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "key_presses.h"

void	up_press(t_vars *vars, int light_count)

{
	int			shape_id;
	t_coords	simul;

	shape_id = vars->obj_id - light_count - 1;
	if (vars->obj == CAM && vars->gen->c->vector.y > -0.999)
	{
		simul.x = vars->gen->c->coords.x + vars->gen->c->vector.x
			+ vars->screen.vect_y.x * 0.05;
		simul.y = vars->gen->c->coords.y + vars->gen->c->vector.y
			+ vars->screen.vect_y.y * 0.05;
		simul.z = vars->gen->c->coords.z + vars->gen->c->vector.z
			+ vars->screen.vect_y.z * 0.05;
		simul = vect_normalised(vect_sub(simul, vars->gen->c->coords));
		vars->gen->c->vector.x = simul.x;
		vars->gen->c->vector.y = simul.y;
		vars->gen->c->vector.z = simul.z;
	}
	else if (vars->obj == SHAPE && (vars->gen->shapes[shape_id]->shape == PLANE
			|| vars->gen->shapes[shape_id]->shape == CYLINDER || vars->gen->shapes[shape_id]->shape == CONE || vars->gen->shapes[shape_id]->shape == TORUS))
	{
		double cost;
		double sint;
		t_coords final;
		cost = cos(-5 * PI / 180);
		sint = sin(-5 * PI / 180);
		final.x = vars->gen->shapes[shape_id]->vector.x * cost + vars->gen->shapes[shape_id]->vector.z * sint;
		final.y = vars->gen->shapes[shape_id]->vector.y;
		final.z = -vars->gen->shapes[shape_id]->vector.x * sint + vars->gen->shapes[shape_id]->vector.z * cost;
		final = vect_normalised(final);
		vars->gen->shapes[shape_id]->vector.x = final.x;
		vars->gen->shapes[shape_id]->vector.y = final.y;
		vars->gen->shapes[shape_id]->vector.z = final.z;
	}
}

void	down_press(t_vars *vars, int light_count)

{
	int			shape_id;
	t_coords	simul;

	shape_id = vars->obj_id - light_count - 1;
	if (vars->obj == CAM && vars->gen->c->vector.y < 0.999)
	{
		simul.x = vars->gen->c->coords.x + vars->gen->c->vector.x
			- vars->screen.vect_y.x * 0.05;
		simul.y = vars->gen->c->coords.y + vars->gen->c->vector.y
			- vars->screen.vect_y.y * 0.05;
		simul.z = vars->gen->c->coords.z + vars->gen->c->vector.z
			- vars->screen.vect_y.z * 0.05;
		simul = vect_normalised(vect_sub(simul, vars->gen->c->coords));
		vars->gen->c->vector.x = simul.x;
		vars->gen->c->vector.y = simul.y;
		vars->gen->c->vector.z = simul.z;
	}
	else if (vars->obj == SHAPE && (vars->gen->shapes[shape_id]->shape == PLANE
			|| vars->gen->shapes[shape_id]->shape == CYLINDER || vars->gen->shapes[shape_id]->shape == CONE || vars->gen->shapes[shape_id]->shape == TORUS))
	{
		double cost;
		double sint;
		t_coords final;
		cost = cos(5 * PI / 180);
		sint = sin(5 * PI / 180);
		final.x = vars->gen->shapes[shape_id]->vector.x * cost + vars->gen->shapes[shape_id]->vector.z * sint;
		final.y = vars->gen->shapes[shape_id]->vector.y;
		final.z = -vars->gen->shapes[shape_id]->vector.x * sint + vars->gen->shapes[shape_id]->vector.z * cost;
		final = vect_normalised(final);
		vars->gen->shapes[shape_id]->vector.x = final.x;
		vars->gen->shapes[shape_id]->vector.y = final.y;
		vars->gen->shapes[shape_id]->vector.z = final.z;
	}
}

void	left_press(t_vars *vars, int light_count)

{
	int			shape_id;
	t_coords	simul;

	shape_id = vars->obj_id - light_count - 1;
	if (vars->obj == CAM)
	{
		simul.x = vars->gen->c->coords.x + vars->gen->c->vector.x + vars->gen->c->vector.x * 0.05;
		simul.y = vars->gen->c->coords.y + vars->gen->c->vector.y + vars->gen->c->vector.x * 0.05;
		simul.z = vars->gen->c->coords.z + vars->gen->c->vector.z + vars->gen->c->vector.x * 0.05;
		simul = vect_normalised(vect_sub(simul, vars->gen->c->coords));
		vars->gen->c->vector.x = simul.x;
		vars->gen->c->vector.y = simul.y;
		vars->gen->c->vector.z = simul.z;
	}
	else if (vars->obj == SHAPE && (vars->gen->shapes[shape_id]->shape == PLANE
			|| vars->gen->shapes[shape_id]->shape == CYLINDER || vars->gen->shapes[shape_id]->shape == CONE || vars->gen->shapes[shape_id]->shape == TORUS))
	{
		double cost;
		double sint;
		t_coords final;
		cost = cos(-5 * PI / 180);
		sint = sin(-5 * PI / 180);
		final.x = vars->gen->shapes[shape_id]->vector.x;
		final.y = vars->gen->shapes[shape_id]->vector.y * cost - vars->gen->shapes[shape_id]->vector.z * sint;
		final.z = vars->gen->shapes[shape_id]->vector.y * sint + vars->gen->shapes[shape_id]->vector.z * cost;
		final = vect_normalised(final);
		vars->gen->shapes[shape_id]->vector.x = final.x;
		vars->gen->shapes[shape_id]->vector.y = final.y;
		vars->gen->shapes[shape_id]->vector.z = final.z;
	}
}

void	right_press(t_vars *vars, int light_count)

{
	int			shape_id;
	t_coords	simul;

	shape_id = vars->obj_id - light_count - 1;
	if (vars->obj == CAM)
	{
		simul.x = vars->gen->c->coords.x + vars->gen->c->vector.x - vars->gen->c->vector.x * 0.05;
		simul.y = vars->gen->c->coords.y + vars->gen->c->vector.y - vars->gen->c->vector.x * 0.05;
		simul.z = vars->gen->c->coords.z + vars->gen->c->vector.z - vars->gen->c->vector.x * 0.05;
		simul = vect_normalised(vect_sub(simul, vars->gen->c->coords));
		vars->gen->c->vector.x = simul.x;
		vars->gen->c->vector.y = simul.y;
		vars->gen->c->vector.z = simul.z;
	}
	else if (vars->obj == SHAPE && (vars->gen->shapes[shape_id]->shape == PLANE
			|| vars->gen->shapes[shape_id]->shape == CYLINDER || vars->gen->shapes[shape_id]->shape == CONE || vars->gen->shapes[shape_id]->shape == TORUS))
	{
		double cost;
		double sint;
		t_coords final;
		cost = cos(5 * PI / 180);
		sint = sin(5 * PI / 180);
		final.x = vars->gen->shapes[shape_id]->vector.x;
		final.y = vars->gen->shapes[shape_id]->vector.y * cost - vars->gen->shapes[shape_id]->vector.z * sint;
		final.z = vars->gen->shapes[shape_id]->vector.y * sint + vars->gen->shapes[shape_id]->vector.z * cost;
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
		up_press(vars, light_count);
	if (button == DOWN)
		down_press(vars, light_count);
	if (button == LEFT)
		left_press(vars, light_count);
	if (button == RIGHT)
		right_press(vars, light_count);
	pre_camera(vars, 0);
}
