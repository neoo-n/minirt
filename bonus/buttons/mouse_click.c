/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_click.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbaj <akabbaj@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 14:31:13 by akabbaj           #+#    #+#             */
/*   Updated: 2025/07/04 14:31:13 by akabbaj          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "buttons.h"

void	select_obj(t_vars *vars, t_dataimg img)
{
	clear_image(&img, vars->win_sizes.x_len, vars->win_sizes.y_height);
	if (vars->state == PRERENDER)
		copy_pre_image(vars);
	else
		copy_image(vars);
	vars->light_count = 0;
	vars->shape_count = 0;
	vars->page_num = 1;
	if (vars->obj_id == -1)
		vars->obj = SETT;
	else if (vars->obj_id == 0)
		vars->obj = CAM;
	else if (vars->obj_id <= count_lights(vars))
		vars->obj = LIGHT;
	else
		vars->obj = SHAPE;
	vars->mode = BASIC;
	make_obj_button(vars, img);
	make_menu(vars, 0, 0, img);
	mlx_put_image_to_window(vars->mlx, vars->win, img.img, 0, 0);
}

void	reset_gen(t_vars *vars)
{
	t_gen	*gen;

	gen = copy_gen(vars->gen->saved_gen);
	free_gen(vars->gen);
	vars->gen = gen;
	vars->gen->character = init_characters();
	vars->gen->saved_gen = copy_gen(vars->gen);
	vars->obj = NONE;
	vars->obj_id = 0;
	vars->state = RENDERING;
	clear_image(&vars->img, vars->win_sizes.x_len, vars->win_sizes.y_height);
	clear_image(&vars->pre_img, vars->win_sizes.x_len,
		vars->win_sizes.y_height);
	mlx_put_image_to_window(vars->mlx, vars->win,
		vars->loading_image.img, 0, 0);
}

void	basic_handler(t_vars *vars, t_dataimg img, int x, int y)
{
	if (click_in_button(vars, x, y) == TEXT && vars->mode == BASIC)
		select_click(vars, img);
	else if (click_in_button(vars, x, y) == SETTINGS && vars->mode == BASIC)
	{
		vars->obj_id = -1;
		select_obj(vars, img);
	}
	else if (click_in_button(vars, x, y) == PRINT && vars->mode == BASIC)
		print_gen(vars->gen);
	else if (click_in_button(vars, x, y) == RESET && vars->mode == BASIC)
		reset_gen(vars);
	else if (click_in_button(vars, x, y) == ADD_OBJ && vars->mode == BASIC)
		add_obj(vars, img);
}

void	obj_add_handler(t_vars *vars, int x, int y)
{
	if (click_in_button(vars, x, y) == LIGHT_ADD && vars->mode == OBJ_ADD)
		new_obj(vars, LIGHT_ADD);
	else if (click_in_button(vars, x, y) == CYL_ADD && vars->mode == OBJ_ADD)
		new_obj(vars, CYL_ADD);
	else if (click_in_button(vars, x, y) == PLANE_ADD && vars->mode == OBJ_ADD)
		new_obj(vars, PLANE_ADD);
	else if (click_in_button(vars, x, y) == SPHERE_ADD && vars->mode == OBJ_ADD)
		new_obj(vars, SPHERE_ADD);
	else if (click_in_button(vars, x, y) == CONE_ADD && vars->mode == OBJ_ADD)
		new_obj(vars, CONE_ADD);
}

int	mouse_click(int button, int x, int y, t_vars *vars)
{
	t_dataimg	img;

	if (vars->state == PRERENDER)
		img = vars->pre_img_copy;
	else
		img = vars->img_copy;
	if (vars->state == RENDERING || button != 1)
		return (0);
	else if (click_in_button(vars, x, y) == MENU)
		menu_click(vars, img);
	else if (vars->mode == BASIC)
		basic_handler(vars, img, x, y);
	else if (click_in_button(vars, x, y) == TEXT && (check_select_mode(vars)))
		select_obj(vars, img);
	else if (click_in_button(vars, x, y) == ARROW_L)
		left_arrow_click(vars, img);
	else if (click_in_button(vars, x, y) == ARROW_R)
		right_arrow_click(vars, img);
	else if (vars->mode == OBJ_ADD)
		obj_add_handler(vars, x, y);
	return (0);
}
