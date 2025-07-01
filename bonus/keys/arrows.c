/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrows.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvauthey <dvauthey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 11:51:57 by akabbaj           #+#    #+#             */
/*   Updated: 2025/07/01 16:50:06 by dvauthey         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "key_presses.h"



void	up_press(t_vars *vars, int light_count)

{
	int			shape_id;
	// t_coords	simul;

	shape_id = vars->obj_id - light_count - 1;
	if (vars->obj == CAM)
	{
		double cost;
		double sint;
		double	det;
		t_coords temp[3];
		t_coords temp2[3];

		cost = cos(-5 * PI / 180);
		sint = sin(-5 * PI / 180);
		det = 1 / (vars->screen.vect_x.x * vars->screen.vect_y.y * vars->gen->c->vector.z + vars->screen.vect_x.z * vars->screen.vect_y.x * vars->gen->c->vector.y + vars->screen.vect_x.y * vars->screen.vect_y.z * vars->gen->c->vector.x - (vars->screen.vect_x.z * vars->screen.vect_y.y * vars->gen->c->vector.x + vars->screen.vect_x.x * vars->screen.vect_y.z * vars->gen->c->vector.y + vars->screen.vect_x.y * vars->screen.vect_y.x * vars->gen->c->vector.z));
		temp[0].x = det * (vars->screen.vect_y.y * vars->gen->c->vector.z - vars->screen.vect_y.z * vars->gen->c->vector.y);
		temp[1].x = det * (-1) * (vars->screen.vect_y.x * vars->gen->c->vector.z - vars->screen.vect_y.z * vars->gen->c->vector.x);
		temp[2].x = det * (vars->screen.vect_y.x * vars->gen->c->vector.y - vars->screen.vect_y.y * vars->gen->c->vector.x);
		temp[0].y = det * (-1) * (vars->screen.vect_x.y * vars->gen->c->vector.z - vars->screen.vect_x.z * vars->gen->c->vector.y);
		temp[1].y = det * (vars->screen.vect_x.x * vars->gen->c->vector.z - vars->screen.vect_x.z * vars->gen->c->vector.x);
		temp[2].y = det * (-1) * (vars->screen.vect_x.x * vars->gen->c->vector.y - vars->screen.vect_x.y * vars->gen->c->vector.x);
		temp[0].z = det * (vars->screen.vect_x.y * vars->screen.vect_y.z - vars->screen.vect_x.z * vars->screen.vect_y.y);
		temp[1].z = det * (-1) * (vars->screen.vect_x.x * vars->screen.vect_y.z - vars->screen.vect_x.z * vars->screen.vect_y.x);
		temp[2].z = det * (vars->screen.vect_x.x * vars->screen.vect_y.y - vars->screen.vect_x.y * vars->screen.vect_y.x);
		temp2[0].x = temp[0].x;
		temp2[0].y = temp[0].y;
		temp2[0].z = temp[0].z;
		temp2[1].x = temp[1].x * cost + temp[2].x * sint;
		temp2[1].y = temp[1].y * cost + temp[2].y * sint;
		temp2[1].z = temp[1].z * cost + temp[2].z * sint;
		temp2[2].x = temp[2].x * cost - temp[1].x * sint; 
		temp2[2].y = temp[2].y * cost - temp[1].y * sint;
		temp2[2].z = temp[2].z * cost - temp[1].z * sint;
		temp[0].x = temp2[0].x * vars->screen.vect_x.x + temp2[1].x * vars->screen.vect_x.y + temp2[2].x * vars->screen.vect_x.z;
		temp[0].y = temp2[0].y * vars->screen.vect_x.x + temp2[1].y * vars->screen.vect_x.y + temp2[2].y * vars->screen.vect_x.z;
		temp[0].z = temp2[0].z * vars->screen.vect_x.x + temp2[1].z * vars->screen.vect_x.y + temp2[2].z * vars->screen.vect_x.z;
		temp[1].x = temp2[0].x * vars->screen.vect_y.x + temp2[1].x * vars->screen.vect_y.y + temp2[2].x * vars->screen.vect_y.z;
		temp[1].y = temp2[0].y * vars->screen.vect_y.x + temp2[1].y * vars->screen.vect_y.y + temp2[2].y * vars->screen.vect_y.z;
		temp[1].z = temp2[0].z * vars->screen.vect_y.x + temp2[1].z * vars->screen.vect_y.y + temp2[2].z * vars->screen.vect_y.z;
		temp[2].x = temp2[0].x * vars->gen->c->vector.x + temp2[1].x * vars->gen->c->vector.y + temp2[2].x * vars->gen->c->vector.z;
		temp[2].y = temp2[0].y * vars->gen->c->vector.x + temp2[1].y * vars->gen->c->vector.y + temp2[2].y * vars->gen->c->vector.z;
		temp[2].z = temp2[0].z * vars->gen->c->vector.x + temp2[1].z * vars->gen->c->vector.y + temp2[2].z * vars->gen->c->vector.z;
		temp2[0].x = temp[0].x * vars->screen.vect_x.x + temp[0].y * vars->screen.vect_x.y + temp[0].z * vars->screen.vect_x.z;
		temp2[0].y = temp[1].x * vars->screen.vect_x.x + temp[1].y * vars->screen.vect_x.y + temp[1].z * vars->screen.vect_x.z;
		temp2[0].z = temp[2].x * vars->screen.vect_x.x + temp[2].y * vars->screen.vect_x.y + temp[2].z * vars->screen.vect_x.z;
		vars->screen.vect_x = vect_normalised(temp2[0]);
		// simul.x = vars->gen->c->coords.x + vars->gen->c->vector.x
		// 	+ vars->screen.vect_y.x * 0.05;
		// simul.y = vars->gen->c->coords.y + vars->gen->c->vector.y
		// 	+ vars->screen.vect_y.y * 0.05;
		// simul.z = vars->gen->c->coords.z + vars->gen->c->vector.z
		// 	+ vars->screen.vect_y.z * 0.05;
		// simul = vect_normalised(vect_sub(simul, vars->gen->c->coords));
		// vars->gen->c->vector.x = simul.x;
		// vars->gen->c->vector.y = simul.y;
		// vars->gen->c->vector.z = simul.z;
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
