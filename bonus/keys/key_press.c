/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbaj <akabbaj@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 10:36:09 by akabbaj           #+#    #+#             */
/*   Updated: 2025/06/27 10:39:05 by akabbaj          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "key_presses.h"

long	current_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

int	key_press(int button, t_vars *vars)
{
	int	light_count;

	light_count = count_lights(vars);
	if (current_time() - vars->starttime < 200)
		return (0);
	else if (button == ENTER && vars->state == PRERENDER)
	{
		vars->state = RENDERING;
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->loading_image.img, 0, 0);
	}
	if (button == H || button == J || button == K || button == L)
		hjkl_handler(vars, button);
	else if (vars->obj != NONE)
	{
		if (button == W || button == A || button == S || button == D)
			wasd_handler(button, vars, light_count);
		else if ((button == PLUS || button == MINUS || button == ZERO
				|| button == NINE) && (vars->obj == SHAPE
				|| vars->obj == LIGHT))
			mod_handler(button, vars, light_count);
		else if (button == E || button == Q || button == Z || button == X)
			zaxis_handler(button, vars, light_count);
		else if (button == UP || button == DOWN || button == LEFT || button == RIGHT)
			arrow_handler(button, vars, light_count);
	}
	return (0);
}

int	render_next_frame(t_vars *vars)
{
	if (vars->state == RENDERING)
	{
		clear_image(&(vars->img), vars->win_sizes.x_len,
			vars->win_sizes.y_height);
		vars->light_count = 0;
		vars->shape_count = 0;
		vars->page_num = 1;
		vars->obj = NONE;
		camera(vars, 0, 0);
	}
	return (0);
}
