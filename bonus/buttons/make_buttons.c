/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_buttons.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbaj <akabbaj@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 15:35:51 by akabbaj           #+#    #+#             */
/*   Updated: 2025/07/03 15:35:55 by akabbaj          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "buttons.h"

void	make_add_button(t_vars *vars, t_dataimg img, int height)
{
	t_button	button;

	button.ex = vars->win_sizes.x_len - vars->win_sizes.x_len * 0.04;
	button.bx = vars->win_sizes.x_len - vars->win_sizes.x_len * 0.3;
	button.ey = (button.ex - button.bx) / 5;
	button.by = vars->win_sizes.y_height * 0.0035;
	button.by += height * 4.2;
	button.ey += height * 4.2;
	if (button.by > vars->win_sizes.y_height
		|| button.ey > vars->win_sizes.y_height)
		return ;
	button.type = TEXT;
	button.colour = 0x9c9797;
	button.text = "add objects";
	make_box(vars, button, 0, img);
}

void	make_reset_button(t_vars *vars, t_dataimg img, int height)
{
	t_button	button;

	button.ex = vars->win_sizes.x_len - vars->win_sizes.x_len * 0.04;
	button.bx = vars->win_sizes.x_len - vars->win_sizes.x_len * 0.3;
	button.ey = (button.ex - button.bx) / 5;
	button.by = vars->win_sizes.y_height * 0.0035;
	button.by += height * 3.15;
	button.ey += height * 3.15;
	if (button.by > vars->win_sizes.y_height
		|| button.ey > vars->win_sizes.y_height)
		return ;
	button.type = TEXT;
	button.colour = 0x9c9797;
	button.text = "reset";
	make_box(vars, button, 0, img);
	make_add_button(vars, img, height);
}

void	make_print_button(t_vars *vars, t_dataimg img, int height)
{
	t_button	button;

	button.ex = vars->win_sizes.x_len - vars->win_sizes.x_len * 0.04;
	button.bx = vars->win_sizes.x_len - vars->win_sizes.x_len * 0.3;
	button.ey = (button.ex - button.bx) / 5;
	button.by = vars->win_sizes.y_height * 0.0035;
	button.by += height * 2.1;
	button.ey += height * 2.1;
	if (button.by > vars->win_sizes.y_height
		|| button.ey > vars->win_sizes.y_height)
		return ;
	button.type = TEXT;
	button.colour = 0x9c9797;
	button.text = "print";
	make_box(vars, button, 0, img);
	make_reset_button(vars, img, height);
}

void	make_settings_button(t_vars *vars, t_dataimg img, int height)
{
	t_button	button;

	button.ex = vars->win_sizes.x_len - vars->win_sizes.x_len * 0.04;
	button.bx = vars->win_sizes.x_len - vars->win_sizes.x_len * 0.3;
	button.ey = (button.ex - button.bx) / 5;
	button.by = vars->win_sizes.y_height * 0.0035;
	button.by += height * 1.05;
	button.ey += height * 1.05;
	if (button.by > vars->win_sizes.y_height
		|| button.ey > vars->win_sizes.y_height)
		return ;
	button.type = TEXT;
	button.colour = 0x9c9797;
	button.text = "settings";
	make_box(vars, button, 0, img);
	make_print_button(vars, img, height);
}

void	make_obj_button(t_vars *vars, t_dataimg img)
{
	t_button	button;
	char		*num;

	button.ex = vars->win_sizes.x_len - vars->win_sizes.x_len * 0.04;
	button.bx = vars->win_sizes.x_len - vars->win_sizes.x_len * 0.3;
	button.ey = (button.ex - button.bx) / 5;
	button.by = vars->win_sizes.y_height * 0.0035;
	if (button.ey > vars->win_sizes.y_height)
		button.ey = vars->win_sizes.y_height;
	button.type = TEXT;
	button.colour = 0x9c9797;
	if (vars->obj == NONE)
		button.text = "no obj selected";
	else if (vars->obj == CAM)
		button.text = "cam selected";
	else if (vars->obj == LIGHT)
		light_text(vars, &button, &num);
	else if (vars->obj == SHAPE)
		shape_text(vars, &button, &num);
	make_box(vars, button, 0, img);
	if (vars->obj == LIGHT || vars->obj == SHAPE)
		free(num);
	make_settings_button(vars, img, button.ey - button.by);
}
