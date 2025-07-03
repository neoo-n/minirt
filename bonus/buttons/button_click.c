/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   button_click.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbaj <akabbaj@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 15:09:16 by akabbaj           #+#    #+#             */
/*   Updated: 2025/07/03 15:09:16 by akabbaj          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "buttons.h"

void	select_click(t_vars *vars, t_dataimg img)
{
	if (count_objs(vars) > button_fit(vars))
		vars->mode = OBJECT_SELECT_ARROWS;
	else
		vars->mode = OBJECT_SELECT;
	clear_image(&img, vars->win_sizes.x_len, vars->win_sizes.y_height);
	if (vars->state == PRERENDER)
		copy_pre_image(vars);
	else
		copy_image(vars);
	vars->page_num = 1;
	vars->light_count = 0;
	vars->shape_count = 0;
	display_all_objs(vars, img);
	make_menu(vars, 0, 0, img);
	mlx_put_image_to_window(vars->mlx, vars->win, img.img, 0, 0);
}

void	right_arrow_click(t_vars *vars, t_dataimg img)
{
	vars->page_num++;
	clear_image(&img, vars->win_sizes.x_len, vars->win_sizes.y_height);
	if (vars->state == PRERENDER)
		copy_pre_image(vars);
	else
		copy_image(vars);
	make_menu(vars, 0, 0, img);
	display_all_objs(vars, img);
	mlx_put_image_to_window(vars->mlx, vars->win, img.img, 0, 0);
}

void	left_arrow_click(t_vars *vars, t_dataimg img)
{
	int	i;

	vars->page_num--;
	clear_image(&img, vars->win_sizes.x_len, vars->win_sizes.y_height);
	if (vars->state == PRERENDER)
		copy_pre_image(vars);
	else
		copy_image(vars);
	vars->light_count = 0;
	vars->shape_count = 0;
	make_menu(vars, 0, 0, img);
	i = 0;
	while (i < vars->page_num)
	{
		display_all_objs(vars, img);
		i++;
	}
	mlx_put_image_to_window(vars->mlx, vars->win, img.img, 0, 0);
}
