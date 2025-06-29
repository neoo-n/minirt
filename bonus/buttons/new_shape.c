/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_shape.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbaj <akabbaj@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 14:57:45 by akabbaj           #+#    #+#             */
/*   Updated: 2025/06/27 15:11:06 by akabbaj          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "buttons.h"

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

void	add_light(t_vars *vars)
{
	t_light	*light;
	t_rgb	rgb;

	light = malloc(sizeof(t_light));
	if (!light)
		return ;
	light->bright = 0.5;
	light->coords = vars->gen->c->coords;
	rgb.r = 255;
	rgb.g = 255;
	rgb.b = 255;
	light->rgb = rgb;
	vars->obj = LIGHT;
	vars->obj_id = count_lights(vars) + 1;
	vars->gen->l = realloc_light(vars->gen->l, light);
	if (!vars->gen->l)
		error_exit_vars(vars, "fuck", 0);
}

void	add_sphere(t_vars *vars)
{
	t_shape	*sphere;
	t_rgb	rgb;

	sphere = malloc(sizeof(t_shape));
	if (!sphere)
		return ;
	sphere->shape = SPHERE;
	sphere->diam = 2;
	sphere->coords = vect_add(vars->gen->c->coords, vect_mult(vars->gen->c->vector, 5));
	rgb.r = 255;
	rgb.g = 255;
	rgb.b = 255;
	sphere->rgb = rgb;
	vars->obj_id = count_lights(vars) + count_objs(vars) - 1;
	vars->obj = SHAPE;
	vars->gen->shapes = realloc_shape(vars->gen->shapes, sphere);
	if (!vars->gen->shapes)
		error_exit_vars(vars, "fuck", 0);
}

void	add_cyl(t_vars *vars)
{
	t_shape	*cyl;
	t_rgb	rgb;

	cyl = malloc(sizeof(t_shape));
	if (!cyl)
		return ;
	cyl->shape = CYLINDER;
	cyl->diam = 2;
	cyl->height = 2;
	cyl->vector.x = 0;
	cyl->vector.y = 1;
	cyl->vector.z = 0;
	cyl->vector = vect_normalised(cyl->vector);
	cyl->coords = vect_add(vars->gen->c->coords, vect_mult(vars->gen->c->vector, 5));
	rgb.r = 255;
	rgb.g = 255;
	rgb.b = 255;
	cyl->rgb = rgb;
	vars->obj = SHAPE;
	vars->obj_id = count_lights(vars) + count_objs(vars) - 1;
	vars->gen->shapes = realloc_shape(vars->gen->shapes, cyl);
	if (!vars->gen->shapes)
		error_exit_vars(vars, "fuck", 0);
}

void	add_plane(t_vars *vars)
{
	t_shape	*plane;
	t_rgb	rgb;

	plane = malloc(sizeof(t_shape));
	if (!plane)
		return ;
	plane->shape = PLANE;
	plane->vector.x = 0;
	plane->vector.y = 1;
	plane->vector.z = 0;
	plane->vector = vect_normalised(plane->vector);
	plane->coords = vect_add(vars->gen->c->coords, vect_mult(vars->gen->c->vector, 5));
	rgb.r = 255;
	rgb.g = 255;
	rgb.b = 255;
	plane->rgb = rgb;
	vars->obj = SHAPE;
	vars->obj_id = count_lights(vars) + count_objs(vars) - 1;
	vars->gen->shapes = realloc_shape(vars->gen->shapes, plane);
	if (!vars->gen->shapes)
		error_exit_vars(vars, "fuck", 0);
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
	pre_camera(vars, 0);
}
