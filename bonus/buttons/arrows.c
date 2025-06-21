/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrows.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbaj <akabbaj@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 15:25:12 by akabbaj           #+#    #+#             */
/*   Updated: 2025/06/21 15:49:20 by akabbaj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "key_presses.h"

void	up_press(t_vars *vars, int light_count)

{
	int			shape_id;
	t_coords	simul;

	shape_id = vars->obj_id - light_count - 1;
	(void) shape_id;
	if (vars->obj == CAM)
	{
		simul.x = vars->gen->c->coords.x + vars->gen->c->vector.x + vars->screen.vect_y.x * 0.05;
		simul.y = vars->gen->c->coords.y + vars->gen->c->vector.y + vars->screen.vect_y.y * 0.05;
		simul.z = vars->gen->c->coords.z + vars->gen->c->vector.z + vars->screen.vect_y.z * 0.05;
		simul = vect_normalised(vect_sub(simul, vars->gen->c->coords));
		vars->gen->c->vector.x = simul.x;
		vars->gen->c->vector.y = simul.y;
		vars->gen->c->vector.z = simul.z;
	}
	// else if (vars->gen->shapes[shape_id]->shape == PLANE
	// 	|| vars->gen->shapes[shape_id]->shape == CYLINDER)
	// {
	// 	vars->gen->shapes[shape_id]->vector.x += vars->gen->c->vector.x * 0.2;
	// 	vars->gen->shapes[shape_id]->vector.y += vars->gen->c->vector.y * 0.2;
	// 	vars->gen->shapes[shape_id]->vector.z += vars->gen->c->vector.z * 0.2;
	// }
}

void	down_press(t_vars *vars, int light_count)

{
	int			shape_id;
	t_coords	simul;

	shape_id = vars->obj_id - light_count - 1;
	(void) shape_id;
	if (vars->obj == CAM)
	{
		simul.x = vars->gen->c->coords.x + vars->gen->c->vector.x - vars->screen.vect_y.x * 0.05;
		simul.y = vars->gen->c->coords.y + vars->gen->c->vector.y - vars->screen.vect_y.y * 0.05;
		simul.z = vars->gen->c->coords.z + vars->gen->c->vector.z - vars->screen.vect_y.z * 0.05;
		simul = vect_normalised(vect_sub(simul, vars->gen->c->coords));
		vars->gen->c->vector.x = simul.x;
		vars->gen->c->vector.y = simul.y;
		vars->gen->c->vector.z = simul.z;
	}
	// else if (vars->gen->shapes[shape_id]->shape == PLANE
	// 	|| vars->gen->shapes[shape_id]->shape == CYLINDER)
	// {
	// 	vars->gen->shapes[shape_id]->vector.x += vars->gen->c->vector.x * 0.2;
	// 	vars->gen->shapes[shape_id]->vector.y += vars->gen->c->vector.y * 0.2;
	// 	vars->gen->shapes[shape_id]->vector.z += vars->gen->c->vector.z * 0.2;
	// }
}

// void	left_press(t_vars *vars, int light_count)

// {
// 	int			shape_id;
// 	t_coords	simul;

// 	shape_id = vars->obj_id - light_count - 1;
// 	if (vars->obj == CAM)
// 	{
// 		simul.x = vars->gen->c->coords.x + vars->gen->c->vector.x + vars->gen->c->vector.x * 0.05;
// 		simul.y = vars->gen->c->coords.y + vars->gen->c->vector.y + vars->gen->c->vector.x * 0.05;
// 		simul.z = vars->gen->c->coords.z + vars->gen->c->vector.z + vars->gen->c->vector.x * 0.05;
// 		simul = vect_normalised(vect_sub(simul, vars->gen->c->coords));
// 		vars->gen->c->vector.x = simul.x;
// 		vars->gen->c->vector.y = simul.y;
// 		vars->gen->c->vector.z = simul.z;
// 	}
// 	// else if (vars->gen->shapes[shape_id]->shape == PLANE
// 	// 	|| vars->gen->shapes[shape_id]->shape == CYLINDER)
// 	// {
// 	// 	vars->gen->shapes[shape_id]->vector.x += vars->gen->c->vector.x * 0.2;
// 	// 	vars->gen->shapes[shape_id]->vector.y += vars->gen->c->vector.y * 0.2;
// 	// 	vars->gen->shapes[shape_id]->vector.z += vars->gen->c->vector.z * 0.2;
// 	// }
// }

// void	right_press(t_vars *vars, int light_count)

// {
// 	int			shape_id;
// 	t_coords	simul;

// 	shape_id = vars->obj_id - light_count - 1;
// 	if (vars->obj == CAM)
// 	{
// 		simul.x = vars->gen->c->coords.x + vars->gen->c->vector.x - vars->gen->c->vector.x * 0.05;
// 		simul.y = vars->gen->c->coords.y + vars->gen->c->vector.y - vars->gen->c->vector.x * 0.05;
// 		simul.z = vars->gen->c->coords.z + vars->gen->c->vector.z - vars->gen->c->vector.x * 0.05;
// 		simul = vect_normalised(vect_sub(simul, vars->gen->c->coords));
// 		vars->gen->c->vector.x = simul.x;
// 		vars->gen->c->vector.y = simul.y;
// 		vars->gen->c->vector.z = simul.z;
// 	}
// 	// else if (vars->gen->shapes[shape_id]->shape == PLANE
// 	// 	|| vars->gen->shapes[shape_id]->shape == CYLINDER)
// 	// {
// 	// 	vars->gen->shapes[shape_id]->vector.x += vars->gen->c->vector.x * 0.2;
// 	// 	vars->gen->shapes[shape_id]->vector.y += vars->gen->c->vector.y * 0.2;
// 	// 	vars->gen->shapes[shape_id]->vector.z += vars->gen->c->vector.z * 0.2;
// 	// }
// }

void	arrow_handler(int button, t_vars *vars, int light_count)
{
	vars->state = PRERENDER;
	clear_image(&(vars->pre_img), vars->win_sizes.x_len,
		vars->win_sizes.y_height);
	if (button == UP)
		up_press(vars, light_count);
	if (button == DOWN)
		down_press(vars, light_count);
	// if (button == LEFT)
	// 	left_press(vars, light_count);
	// if (button == RIGHT)
	// 	right_press(vars, light_count);
	pre_camera(vars, 0, 0);
}
