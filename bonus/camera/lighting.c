/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lighting.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbaj <akabbaj@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 14:40:24 by akabbaj           #+#    #+#             */
/*   Updated: 2025/07/03 14:40:32 by akabbaj          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"

t_coords	calc_norm(t_inter shape, t_coords ray)
{
	t_coords	n;

	if (shape.shape->shape == PLANE)
		n = shape.shape->vector;
	else if (shape.shape->shape == SPHERE)
		n = vect_normalised(vect_sub(shape.point, shape.shape->coords));
	else if (shape.shape->shape == CYLINDER)
		n = cyl_n(shape);
	else if (shape.shape->shape == CONE)
		n = co_n(shape);
	else if (shape.shape->shape == TORUS)
		n = vect_normalised(vect_sub(shape.point, shape.center_t));
	if (dot_prod(vect_normalised(n), vect_normalised(ray)) > 0)
		n = vect_mult(n, -1);
	return (n);
}

int	in_shade(t_inter shape, t_gen *gen, double angle, int i)
{
	t_coords	newray;
	t_inter		closest_shape;
	double		dist[2];
	t_coords	newpoint;
	t_coords	offset_point;

	(void) angle;
	newray = vect_normalised(vect_sub(gen->l[i]->coords, shape.point));
	offset_point = vect_add(shape.point, vect_mult(shape.normal, 1e-6));
	closest_shape = find_closest_shape(newray, offset_point, gen->shapes, NULL);
	if (!closest_shape.shape || closest_shape.t == -1)
		return (0);
	dist[0] = dot_prod(vect_sub(gen->l[i]->coords, offset_point), newray);
	newpoint = vect_add(offset_point, vect_mult(newray, closest_shape.t));
	dist[1] = dot_prod(vect_sub(newpoint, offset_point), newray);
	if (dist[1] < dist[0] - 1e-6)
		return (1);
	return (0);
}

double	calc_dif_int(t_inter shape, t_light	*light)
{
	double		angle;
	t_coords	light_dir;

	light_dir = vect_normalised(vect_sub(light->coords, shape.point));
	angle = dot_prod(shape.normal, light_dir);
	if (angle <= 1e-8)
		return (0);
	return (angle * light->bright);
}

double	specular(t_vars *vars, t_inter shape, t_light *light_pt)
{
	t_coords	refl;
	double		prod_rv;
	double		spec;
	t_coords	light;

	light = vect_normalised(vect_sub(vect_add(vars->gen->c->coords,
					vect_mult(shape.ray, shape.t)), light_pt->coords));
	refl = vect_normalised(vect_sub(vect_mult(shape.normal,
					2 * dot_prod(light, shape.normal)), light));
	prod_rv = dot_prod(refl, shape.ray);
	if (prod_rv > 0)
		spec = pow(prod_rv, SHINY);
	else
		spec = 0;
	return (spec);
}

double	calc_fog(double t)
{
	double	fog;

	fog = (t - 30) / (100 - 30);
	if (fog > 1)
		fog = 1;
	else if (fog < 0)
		fog = 0;
	return (fog);
}

t_rgb	calc_lights(t_vars *vars, t_inter shape, t_rgb *spec_light, int i)
{
	t_rgb	dif_light;
	double	light[2];

	dif_light = init_rgb();
	if (!in_shade(shape, vars->gen, 0, i) || vars->shadow == OFF)
	{
		light[0] = calc_dif_int(shape, vars->gen->l[i]);
		light[1] = specular(vars, shape, vars->gen->l[i]);
	}
	else
	{
		light[0] = 0;
		light[1] = 0;
	}
	if (vars->diffuse == ON)
		dif_light = rgb_mult(norm_rgb(vars->gen->l[i]->rgb), light[0]);
	if (vars->specular == ON)
		*spec_light = rgb_sum(*spec_light,
				rgb_mult(norm_rgb(vars->gen->l[i]->rgb),
					light[1] * vars->gen->l[i]->bright));
	return (dif_light);
}

int	get_rgb(t_inter shape, t_gen *gen, t_vars *vars)
{
	int		i;
	t_rgb	spec_light;
	t_rgb	dif_light;
	t_rgb	amb_light;
	t_rgb	shape_col;

	i = 0;
	spec_light = init_rgb();
	amb_light = init_rgb();
	dif_light = init_rgb();
	while (gen->l[i])
		dif_light = rgb_sum(dif_light,
				calc_lights(vars, shape, &spec_light, i++));
	if (vars->ambient == ON)
		amb_light = rgb_mult(rgb_mult(norm_rgb(gen->a->rgb),
					gen->a->light), 1 - calc_fog(shape.t));
	shape_col = rgb_final(norm_rgb(shape.shape->rgb), amb_light,
			dif_light, spec_light);
	return ((int)(shape_col.r * 255) << 16 | (int)(shape_col.g * 255) << 8
		| (int)(shape_col.b * 255));
}
