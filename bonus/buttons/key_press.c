/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbaj <akabbaj@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 20:21:59 by akabbaj           #+#    #+#             */
/*   Updated: 2025/06/19 22:36:40 by akabbaj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "buttons.h"

int	key_press(int button, t_vars *vars)
{
	if (button == 65293 && vars->state == PRERENDER)
	{
		vars->state = RENDERING;
		mlx_put_image_to_window(vars->mlx, vars->win, vars->loading_image.img, 0, 0);
	}
	else if (button == 61 && vars->obj == SHAPE)
	{
		clear_image(&(vars->pre_img), vars->win_sizes.x_len, vars->win_sizes.y_height);
		vars->state = RENDER;
		vars->gen->shapes[0]->height += 0.5;
		pre_camera(vars, 0, 0);
	}
	else if (button == 45 && vars->obj == SHAPE && vars->gen->shapes[0]->height > 0.5)
	{
		clear_image(&(vars->pre_img), vars->win_sizes.x_len, vars->win_sizes.y_height);
		vars->state = RENDER;
		vars->gen->shapes[0]->height -= 0.5;
		pre_camera(vars, 0, 0);
	}
	return (0);
}

int	render_next_frame(t_vars *vars)
{
	if (vars->state == RENDERING)
	{
		//mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, 0, 0);
		vars->light_count = 0;
		vars->shape_count = 0;
		vars->page_num = 1;
		vars->obj = NONE;
		camera(vars, 0, 0);
	}
	return (0);
}
