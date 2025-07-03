/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mod.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbaj <akabbaj@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 16:04:19 by akabbaj           #+#    #+#             */
/*   Updated: 2025/07/03 22:36:39 by akabbaj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "key_presses.h"

void	plus_press(t_vars *vars, int light_count)
{
	int	shape_id;
	int	light_id;

	light_id = vars->obj_id - 1;
	shape_id = vars->obj_id - light_count - 1;
	if (vars->mode == RED || vars->mode == GREEN || vars->mode == BLUE)
		plus_rgb(vars, light_id, shape_id);
	else if (vars->obj == SHAPE)
		vars->gen->shapes[shape_id]->diam += 0.1;
	else if (vars->gen->l[light_id]->bright <= 0.95)
		vars->gen->l[light_id]->bright += 0.05;
}

void	minus_press(t_vars *vars, int light_count)
{
	int	shape_id;
	int	light_id;

	light_id = vars->obj_id - 1;
	shape_id = vars->obj_id - light_count - 1;
	if (vars->mode == RED || vars->mode == GREEN || vars->mode == BLUE)
		minus_rgb(vars, light_id, shape_id);
	else if (vars->obj == SHAPE
		&& vars->gen->shapes[shape_id]->diam > 0.2)
		vars->gen->shapes[shape_id]->diam -= 0.1;
	else if (vars->obj == LIGHT && vars->gen->l[light_id]->bright >= 0.05)
		vars->gen->l[light_id]->bright -= 0.05;
}

void	nine_press(t_vars *vars, int light_count)
{
	int	shape_id;

	shape_id = vars->obj_id - light_count - 1;
	if (vars->gen->shapes[shape_id]->height > 0.2)
		vars->gen->shapes[shape_id]->height -= 0.2;
}

void	zero_press(t_vars *vars, int light_count)
{
	int	shape_id;

	shape_id = vars->obj_id - light_count - 1;
	vars->gen->shapes[shape_id]->height += 0.2;
}

void	mod_handler(int button, t_vars *vars, int light_count)
{
	vars->state = PRERENDER;
	clear_image(&(vars->pre_img), vars->win_sizes.x_len,
		vars->win_sizes.y_height);
	if (button == PLUS && vars->obj != CAM)
		plus_press(vars, light_count);
	else if (button == MINUS && vars->obj != CAM)
		minus_press(vars, light_count);
	else if (button == ZERO && vars->obj != LIGHT)
		zero_press(vars, light_count);
	else if (button == NINE && vars->obj != LIGHT)
		nine_press(vars, light_count);
	pre_camera(vars, 0);
}
