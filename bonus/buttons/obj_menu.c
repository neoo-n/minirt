/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_menu.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbaj <akabbaj@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 11:20:20 by akabbaj           #+#    #+#             */
/*   Updated: 2025/06/30 21:48:13 by akabbaj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "buttons.h"

void	light_buttons(t_vars *vars, t_dataimg img, t_button *button, int height)
{
	char	*text;
	char	*num;

	while (vars->gen->l[vars->light_count] && (*button).ey + height * 1.05
		< vars->win_sizes.y_height - vars->win_sizes.y_height * 0.035)
	{
		num = ft_itoa(vars->light_count + 1);
		text = ft_strjoin("light ", num);
		(*button).text = text;
		make_box(vars, (*button), 0, img);
		free(num);
		free(text);
		(*button).by += height * 1.05;
		(*button).ey += height * 1.05;
		vars->light_count++;
	}
}

void	shape_buttons(t_vars *vars, t_dataimg img, t_button *button, int height)
{
	char	*text;
	char	*num;

	while (vars->gen->shapes[vars->shape_count] && (*button).ey + height * 1.05
		< vars->win_sizes.y_height - vars->win_sizes.y_height * 0.035)
	{
		num = ft_itoa(get_shapenum(vars,
					vars->gen->shapes[vars->shape_count]->shape, 1));
		if (vars->gen->shapes[vars->shape_count]->shape == CYLINDER)
			text = "cylinder ";
		else if (vars->gen->shapes[vars->shape_count]->shape == SPHERE)
			text = "sphere ";
		else if (vars->gen->shapes[vars->shape_count]->shape == PLANE)
			text = "plane ";
		else if (vars->gen->shapes[vars->shape_count]->shape == TORUS)
			text = "torus ";
		else if (vars->gen->shapes[vars->shape_count]->shape == CONE)
			text = "cone ";
		text = ft_strjoin(text, num);
		(*button).text = text;
		make_box(vars, (*button), 0, img);
		free(text);
		free(num);
		(*button).by += height * 1.05;
		(*button).ey += height * 1.05;
		vars->shape_count++;
	}
}

void	arrow_buttons(t_vars *vars, t_dataimg img, t_button *button)
{
	if (vars->gen->shapes[vars->shape_count])
	{
		vars->mode = OBJECT_SELECT_ARROWS;
		if (vars->page_num == 1)
			make_arrows(vars, (*button).ex - (*button).bx, 1, img);
		else
			make_arrows(vars, (*button).ex - (*button).bx, 0, img);
	}
	else if (vars->page_num != 1)
	{
		make_arrows(vars, (*button).ex - (*button).bx, -1, img);
		vars->mode = OBJECT_SELECT_LASTPAGE;
	}
	else
		vars->mode = OBJECT_SELECT;
}

void	camera_button(t_vars *vars, t_dataimg img, t_button *button, int height)
{
	if (vars->shape_count == 0 && vars->light_count == 0)
	{
		(*button).text = "camera";
		make_box(vars, (*button), 0, img);
		(*button).by += height * 1.05;
		(*button).ey += height * 1.05;
	}
}

void	display_all_objs(t_vars *vars, t_dataimg img)
{
	t_button	button;
	int			height;

	button.ex = vars->win_sizes.x_len - vars->win_sizes.x_len * 0.04;
	button.bx = vars->win_sizes.x_len - vars->win_sizes.x_len * 0.3;
	button.type = TEXT;
	button.colour = 0x9c9797;
	button.ey = (button.ex - button.bx) / 5;
	if (button.ey > vars->win_sizes.y_height)
		button.ey = vars->win_sizes.y_height;
	button.by = vars->win_sizes.y_height * 0.0035;
	height = button.ey - button.by;
	camera_button(vars, img, &button, height);
	light_buttons(vars, img, &button, height);
	shape_buttons(vars, img, &button, height);
	arrow_buttons(vars, img, &button);
}
