/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_shape.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbaj <akabbaj@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 15:46:32 by akabbaj           #+#    #+#             */
/*   Updated: 2025/07/03 15:46:32 by akabbaj          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "buttons.h"

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
	sphere->coords = vect_add(vars->gen->c->coords,
			vect_mult(vars->gen->c->vector, 5));
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
	cyl->coords = vect_add(vars->gen->c->coords,
			vect_mult(vars->gen->c->vector, 5));
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

void	add_cone(t_vars *vars)
{
	t_shape	*cyl;
	t_rgb	rgb;

	cyl = malloc(sizeof(t_shape));
	if (!cyl)
		return ;
	cyl->shape = CONE;
	cyl->diam = 2;
	cyl->height = 2;
	cyl->vector.x = 0;
	cyl->vector.y = 1;
	cyl->vector.z = 0;
	cyl->vector = vect_normalised(cyl->vector);
	cyl->coords = vect_add(vars->gen->c->coords,
			vect_mult(vars->gen->c->vector, 5));
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
	plane->coords = vect_add(vars->gen->c->coords,
			vect_mult(vars->gen->c->vector, 5));
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
