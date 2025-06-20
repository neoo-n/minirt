/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_click.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbaj <akabbaj@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 15:30:11 by akabbaj           #+#    #+#             */
/*   Updated: 2025/06/20 23:08:14 by akabbaj          ###   ########.fr       */
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
	if (vars->obj_id == 0)
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

int	mouse_click(int button, int x, int y, t_vars *vars)
{
	t_dataimg	img;

	if (vars->state == PRERENDER)
		img = vars->pre_img_copy;
	else
		img = vars->img_copy;
	if (vars->state == RENDERING || button != 1)
		return (0);
	if (click_in_button(vars, x, y) == TEXT && vars->mode == BASIC)
		select_click(vars, img);
	else if (click_in_button(vars, x, y) == TEXT && (check_select_mode(vars)))
		select_obj(vars, img);
	else if (click_in_button(vars, x, y) == MENU)
		menu_click(vars, img);
	else if (click_in_button(vars, x, y) == ARROW_L)
		left_arrow_click(vars, img);
	else if (click_in_button(vars, x, y) == ARROW_R)
		right_arrow_click(vars, img);
	return (0);
}
