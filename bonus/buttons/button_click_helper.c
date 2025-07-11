/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   button_click_helper.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbaj <akabbaj@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 14:26:47 by akabbaj           #+#    #+#             */
/*   Updated: 2025/07/04 14:42:04 by akabbaj          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "buttons.h"

void	hide_buttons(t_vars *vars, t_dataimg img)
{
	vars->mode = HIDDEN;
	clear_image(&img, vars->win_sizes.x_len, vars->win_sizes.y_height);
	if (vars->state == PRERENDER)
		copy_pre_image(vars);
	else
		copy_image(vars);
	vars->page_num = 1;
	vars->light_count = 0;
	vars->shape_count = 0;
	make_menu(vars, 0, 0, img);
}

void	menu_click(t_vars *vars, t_dataimg img)
{
	t_button	button;

	if (vars->mode == HIDDEN || vars->mode == RED || vars->mode == GREEN
		|| vars->mode == BLUE)
	{
		vars->mode = BASIC;
		if (vars->state == PRERENDER)
		{
			button.colour = 0x9c9797;
			button.type = TEXT;
			button.text = "press enter to render";
			button.bx = (vars->win_sizes.x_len / 2) * 0.8;
			button.ex = (vars->win_sizes.x_len / 2) * 1.2;
			button.ey = vars->win_sizes.y_height;
			button.by = vars->win_sizes.y_height * 0.95;
			make_box(vars, button, 0, img);
		}
		make_obj_button(vars, img);
	}
	else
		hide_buttons(vars, img);
	mlx_put_image_to_window(vars->mlx, vars->win, img.img, 0, 0);
}

int	button_fit(t_vars *vars)
{
	int	button_start_x;
	int	button_len;
	int	button_start_y;
	int	button_height;
	int	buttons;

	button_start_x = vars->win_sizes.x_len - vars->win_sizes.x_len * 0.3;
	button_len = (vars->win_sizes.x_len - vars->win_sizes.x_len * 0.04)
		- (button_start_x);
	button_start_y = vars->win_sizes.y_height * 0.0035;
	button_height = button_len / 5 - button_start_y;
	buttons = 0;
	while ((button_start_y + button_height) + button_height * 1.05
		< vars->win_sizes.y_height - vars->win_sizes.y_height * 0.035)
	{
		buttons++;
		button_start_y += button_height * 1.05;
	}
	return (buttons);
}
