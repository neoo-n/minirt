/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_click.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbaj <akabbaj@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 15:22:40 by akabbaj           #+#    #+#             */
/*   Updated: 2025/06/19 15:23:16 by akabbaj          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "buttons.h"

int	count_objs(t_vars *vars)
{
	int	i;

	i = 0;
	while (vars->gen->shapes[i])
		i++;
	return (i + 2);
}

int	max_for_page(t_vars *vars, int buttons)
{
	int	objs;
	int	max_pages;

	objs = count_objs(vars);
	max_pages = ceil((double) objs / (double) buttons);
	if (vars->page_num < max_pages)
		return (buttons);
	return ((objs % buttons) - 1);
}

t_type	click_in_button(t_vars *vars, int x, int y)
{
	int		button_len;
	int		button_height;
	int		button_start_x;
	int		button_start_y;
	int		length;
	int		buttons;
	int		i;

	button_start_x = vars->win_sizes.x_len - vars->win_sizes.x_len * 0.3;
	button_len = (vars->win_sizes.x_len - vars->win_sizes.x_len * 0.04) - (button_start_x);
	button_start_y = vars->win_sizes.y_height * 0.0035;
	button_height = button_len / 5 - button_start_y;
	buttons = 0;
	while ((button_start_y + button_height) + button_height * 1.05 < vars->win_sizes.y_height - vars->win_sizes.y_height * 0.035)
	{
		buttons++;
		button_start_y += button_height * 1.05;
	}
	button_start_y = vars->win_sizes.y_height * 0.0035;
	if (x >= vars->win_sizes.x_len - vars->win_sizes.x_len * 0.035 && x <= vars->win_sizes.x_len - vars->win_sizes.x_len * 0.005 && y >= vars->win_sizes.y_height * 0.0035 && y <= vars->win_sizes.y_height * 0.035)
		return (MENU);
	else if (vars->mode == BASIC)
	{
		if (x >= button_start_x && x <= button_start_x + button_len
			&& y >= button_start_y && y <= button_start_y + button_height)
			return (TEXT);
	}
	else if (vars->mode == OBJECT_SELECT || vars->mode == OBJECT_SELECT_ARROWS || vars->mode == OBJECT_SELECT_LASTPAGE)
	{
		if (vars->mode != OBJECT_SELECT)
		{
			length = (vars->win_sizes.x_len - vars->win_sizes.x_len * 0.04) - (vars->win_sizes.x_len - vars->win_sizes.x_len * 0.07);
			if (x >= vars->win_sizes.x_len - vars->win_sizes.x_len * 0.07 && x <= vars->win_sizes.x_len - vars->win_sizes.x_len * 0.04 && y >= vars->win_sizes.y_height * (1 - 0.035) && y <= vars->win_sizes.y_height * (1 - 0.0035) && vars->mode == OBJECT_SELECT_ARROWS)
				return (ARROW_R);
			if (vars->page_num > 1 && x >= (vars->win_sizes.x_len - vars->win_sizes.x_len * 0.07) - button_len + length && x <= (vars->win_sizes.x_len - vars->win_sizes.x_len * 0.04) - button_len + length && y >= vars->win_sizes.y_height * (1 - 0.035) && y <= vars->win_sizes.y_height * (1 - 0.0035) && vars->mode)
				return (ARROW_L);
		}
		i = 0;
		while ((button_start_y + button_height) + button_height * 1.05 < vars->win_sizes.y_height - vars->win_sizes.y_height * 0.035
				&& i < max_for_page(vars, buttons))
		{
			if (x >= button_start_x && x <= button_start_x + button_len
				&& y >= button_start_y && y <= button_start_y + button_height)
			{
				vars->obj_id = i + ((vars->page_num - 1) * buttons);
				return (TEXT);
			}
			button_start_y += button_height * 1.05;
			i++;
		}
	}
	return (EMPTY);
}

void	menu_click(t_vars *vars)
{
	if (vars->mode == HIDDEN)
	{
		vars->mode = BASIC;
		make_obj_button(vars);
	}
	else
	{
		vars->mode = HIDDEN;
		mlx_destroy_image(vars->mlx, vars->img_copy.img);
		copy_image(vars);
		vars->page_num = 1;
		vars->light_count = 0;
		vars->shape_count = 0;
		make_menu(vars, 0, 0);
	}
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img_copy.img, 0, 0);
}

int	button_fit(t_vars *vars)
{
	int	button_start_x;
	int	button_len;
	int	button_start_y;
	int	button_height;
	int	buttons;

	button_start_x = vars->win_sizes.x_len - vars->win_sizes.x_len * 0.3;
	button_len = (vars->win_sizes.x_len - vars->win_sizes.x_len * 0.04) - (button_start_x);
	button_start_y = vars->win_sizes.y_height * 0.0035;
	button_height = button_len / 5 - button_start_y;
	buttons = 0;
	while ((button_start_y + button_height) + button_height * 1.05 < vars->win_sizes.y_height - vars->win_sizes.y_height * 0.035)
	{
		buttons++;
		button_start_y += button_height * 1.05;
	}
	return (buttons);
}

void	select_click(t_vars *vars)
{
	if (count_objs(vars) > button_fit(vars))
		vars->mode = OBJECT_SELECT_ARROWS;
	else
		vars->mode = OBJECT_SELECT;
	mlx_destroy_image(vars->mlx, vars->img_copy.img);
	copy_image(vars);
	vars->page_num = 1;
	vars->light_count = 0;
	vars->shape_count = 0;
	display_all_objs(vars);
	make_menu(vars, 0, 0);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img_copy.img, 0, 0);
}

void	right_arrow_click(t_vars *vars)
{
	vars->page_num++;
	mlx_destroy_image(vars->mlx, vars->img_copy.img);
	copy_image(vars);
	make_menu(vars, 0, 0);
	display_all_objs(vars);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img_copy.img, 0, 0);
}

void	left_arrow_click(t_vars *vars)
{
	int	i;

	vars->page_num--;
	mlx_destroy_image(vars->mlx, vars->img_copy.img);
	copy_image(vars);
	vars->light_count = 0;
	vars->shape_count = 0;
	make_menu(vars, 0, 0);
	i = 0;
	while (i < vars->page_num)
	{
		display_all_objs(vars);
		i++;
	}
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img_copy.img, 0, 0);
}

void	select_obj(t_vars *vars)
{
	mlx_destroy_image(vars->mlx, vars->img_copy.img);
	copy_image(vars);
	vars->light_count = 0;
	vars->shape_count = 0;
	vars->page_num = 1;
	if (vars->obj_id == 0)
		vars->obj = CAM;
	else
	{
		vars->obj = SHAPE;
		vars->obj_id -= 1;
	}
	vars->mode = BASIC;
	make_obj_button(vars);
	make_menu(vars, 0, 0);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img_copy.img, 0, 0);
}

int	mouse_click(int button, int x, int y, t_vars *vars)
{
	if (click_in_button(vars, x, y) == TEXT && button == 1 && vars->mode == BASIC)
		select_click(vars);
	else if (click_in_button(vars, x, y) == TEXT && button == 1 && (vars->mode == OBJECT_SELECT || vars->mode == OBJECT_SELECT_ARROWS || vars->mode == OBJECT_SELECT_LASTPAGE))
		select_obj(vars);
	else if (click_in_button(vars, x, y) == MENU && button == 1)
		menu_click(vars);
	else if (click_in_button(vars, x, y) == ARROW_L && button == 1)
		left_arrow_click(vars);
	else if (click_in_button(vars, x, y) == ARROW_R && button == 1)
		right_arrow_click(vars);
	return (0);
}
