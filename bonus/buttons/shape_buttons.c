/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shape_buttons.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbaj <akabbaj@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 15:43:56 by akabbaj           #+#    #+#             */
/*   Updated: 2025/07/03 15:43:56 by akabbaj          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "buttons.h"

void	make_cone_button(t_vars *vars, t_dataimg img, int height)
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
	button.text = "cone";
	make_box(vars, button, 0, img);
}

void	make_cyl_button(t_vars *vars, t_dataimg img, int height)
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
	button.text = "cylinder";
	make_box(vars, button, 0, img);
	make_cone_button(vars, img, height);
}

void	make_plane_button(t_vars *vars, t_dataimg img, int height)
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
	button.text = "plane";
	make_box(vars, button, 0, img);
	make_cyl_button(vars, img, height);
}

void	make_sphere_button(t_vars *vars, t_dataimg img, int height)
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
	button.text = "sphere";
	make_box(vars, button, 0, img);
	make_plane_button(vars, img, height);
}
