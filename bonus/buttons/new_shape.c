/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_shape.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbaj <akabbaj@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 15:46:39 by akabbaj           #+#    #+#             */
/*   Updated: 2025/07/03 15:46:46 by akabbaj          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "buttons.h"

void	add_obj(t_vars *vars, t_dataimg img)
{
	t_button	button;

	clear_image(&img, vars->win_sizes.x_len, vars->win_sizes.y_height);
	if (vars->state == PRERENDER)
		copy_pre_image(vars);
	else
		copy_image(vars);
	vars->page_num = 1;
	vars->light_count = 0;
	vars->shape_count = 0;
	make_menu(vars, 0, 0, img);
	vars->mode = OBJ_ADD;
	button.ex = vars->win_sizes.x_len - vars->win_sizes.x_len * 0.04;
	button.bx = vars->win_sizes.x_len - vars->win_sizes.x_len * 0.3;
	button.ey = (button.ex - button.bx) / 5;
	button.by = vars->win_sizes.y_height * 0.0035;
	if (button.by > vars->win_sizes.y_height
		|| button.ey > vars->win_sizes.y_height)
		return ;
	button.type = TEXT;
	button.colour = 0x9c9797;
	button.text = "light";
	make_box(vars, button, 0, img);
	make_sphere_button(vars, img, button.ey - button.by);
	mlx_put_image_to_window(vars->mlx, vars->win, img.img, 0, 0);
}

void	new_obj(t_vars *vars, t_type obj)
{
	if (obj == LIGHT_ADD)
		add_light(vars);
	else if (obj == SPHERE_ADD)
		add_sphere(vars);
	else if (obj == PLANE_ADD)
		add_plane(vars);
	else if (obj == CYL_ADD)
		add_cyl(vars);
	else if (obj == CONE_ADD)
		add_cone(vars);
	pre_camera(vars, 0);
}
