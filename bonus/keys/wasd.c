/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wasd.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbaj <akabbaj@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 10:35:24 by akabbaj           #+#    #+#             */
/*   Updated: 2025/06/27 10:35:46 by akabbaj          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "key_presses.h"

void	w_press(t_vars *vars, int light_count)
{
	int	shape_id;
	int	light_id;

	light_id = vars->obj_id - 1;
	shape_id = vars->obj_id - light_count - 1;
	if (vars->obj == CAM)
	{
		vars->gen->c->coords.x -= vars->screen.vect_y.x * 0.2;
		vars->gen->c->coords.y -= vars->screen.vect_y.y * 0.2;
		vars->gen->c->coords.z -= vars->screen.vect_y.z * 0.2;
	}
	else if (vars->obj == SHAPE)
	{
		vars->gen->shapes[shape_id]->coords.x -= vars->screen.vect_y.x * 0.2;
		vars->gen->shapes[shape_id]->coords.y -= vars->screen.vect_y.y * 0.2;
		vars->gen->shapes[shape_id]->coords.z -= vars->screen.vect_y.z * 0.2;
	}
	else
	{
		vars->gen->l[light_id]->coords.x -= vars->screen.vect_y.x * 0.2;
		vars->gen->l[light_id]->coords.y -= vars->screen.vect_y.y * 0.2;
		vars->gen->l[light_id]->coords.z -= vars->screen.vect_y.z * 0.2;
	}
}

void	a_press(t_vars *vars, int light_count)
{
	int	shape_id;
	int	light_id;

	light_id = vars->obj_id - 1;
	shape_id = vars->obj_id - light_count - 1;
	if (vars->obj == CAM)
	{
		vars->gen->c->coords.x -= vars->screen.vect_x.x * 0.2;
		vars->gen->c->coords.y -= vars->screen.vect_x.y * 0.2;
		vars->gen->c->coords.z -= vars->screen.vect_x.z * 0.2;
	}
	else if (vars->obj == SHAPE)
	{
		vars->gen->shapes[shape_id]->coords.x -= vars->screen.vect_x.x * 0.2;
		vars->gen->shapes[shape_id]->coords.y -= vars->screen.vect_x.y * 0.2;
		vars->gen->shapes[shape_id]->coords.z -= vars->screen.vect_x.z * 0.2;
	}
	else
	{
		vars->gen->l[light_id]->coords.x -= vars->screen.vect_x.x * 0.2;
		vars->gen->l[light_id]->coords.y -= vars->screen.vect_x.y * 0.2;
		vars->gen->l[light_id]->coords.z -= vars->screen.vect_x.z * 0.2;
	}
}

void	s_press(t_vars *vars, int light_count)
{
	int	shape_id;
	int	light_id;

	light_id = vars->obj_id - 1;
	shape_id = vars->obj_id - light_count - 1;
	if (vars->obj == CAM)
	{
		vars->gen->c->coords.x += vars->screen.vect_y.x * 0.2;
		vars->gen->c->coords.y += vars->screen.vect_y.y * 0.2;
		vars->gen->c->coords.z += vars->screen.vect_y.z * 0.2;
	}
	else if (vars->obj == SHAPE)
	{
		vars->gen->shapes[shape_id]->coords.x += vars->screen.vect_y.x * 0.2;
		vars->gen->shapes[shape_id]->coords.y += vars->screen.vect_y.y * 0.2;
		vars->gen->shapes[shape_id]->coords.z += vars->screen.vect_y.z * 0.2;
	}
	else
	{
		vars->gen->l[light_id]->coords.x += vars->screen.vect_y.x * 0.2;
		vars->gen->l[light_id]->coords.y += vars->screen.vect_y.y * 0.2;
		vars->gen->l[light_id]->coords.z += vars->screen.vect_y.z * 0.2;
	}
}

void	d_press(t_vars *vars, int light_count)
{
	int	shape_id;
	int	light_id;

	light_id = vars->obj_id - 1;
	shape_id = vars->obj_id - light_count - 1;
	if (vars->obj == CAM)
	{
		vars->gen->c->coords.x += vars->screen.vect_x.x * 0.2;
		vars->gen->c->coords.y += vars->screen.vect_x.y * 0.2;
		vars->gen->c->coords.z += vars->screen.vect_x.z * 0.2;
	}
	else if (vars->obj == SHAPE)
	{
		vars->gen->shapes[shape_id]->coords.x += vars->screen.vect_x.x * 0.2;
		vars->gen->shapes[shape_id]->coords.y += vars->screen.vect_x.y * 0.2;
		vars->gen->shapes[shape_id]->coords.z += vars->screen.vect_x.z * 0.2;
	}
	else
	{
		vars->gen->l[light_id]->coords.x += vars->screen.vect_x.x * 0.2;
		vars->gen->l[light_id]->coords.y += vars->screen.vect_x.y * 0.2;
		vars->gen->l[light_id]->coords.z += vars->screen.vect_x.z * 0.2;
	}
}

void	wasd_handler(int button, t_vars *vars, int light_count)
{
	vars->state = PRERENDER;
	clear_image(&(vars->pre_img), vars->win_sizes.x_len,
		vars->win_sizes.y_height);
	if (button == W)
		w_press(vars, light_count);
	if (button == A)
		a_press(vars, light_count);
	if (button == S)
		s_press(vars, light_count);
	if (button == D)
		d_press(vars, light_count);
	pre_camera(vars, 0, 0);
}
