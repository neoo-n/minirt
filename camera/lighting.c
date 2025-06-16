/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lighting.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbaj <akabbaj@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 11:55:20 by akabbaj           #+#    #+#             */
/*   Updated: 2025/06/16 12:38:34 by akabbaj          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"

t_coords	calc_norm(t_inter shape, t_coords ray)
{
	t_coords	n;
	t_coords	x;
	double		dist;

	if (shape.shape->shape == PLANE)
	{
		n = shape.shape->vector;
		if (dot_prod(n, ray) > 0)
			n = vect_mult(n, -1);
		return (n);
	}
	if (shape.shape->shape == SPHERE)
		n = vect_normalised(vect_sub(shape.point, shape.shape->coords));
	if (shape.shape->shape == CYLINDER)
	{
		dist = dot_prod(vect_sub(shape.point, shape.shape->coords), shape.shape->vector);
		if (fabs(dist - shape.shape->height / 2) < 1e-6)
			n = vect_normalised(shape.shape->vector);
		else if (fabs(dist + shape.shape->height / 2) < 1e-6)
			n = vect_normalised(vect_mult(shape.shape->vector, -1));
		else if (dist > -shape.shape->height / 2 && dist < shape.shape->height / 2)
		{
			x = vect_add(shape.shape->coords, vect_mult(shape.shape->vector, dist));
			n = vect_normalised(vect_sub(shape.point, x));
		}
	}	
	return (n);
}

int	in_shade(t_inter shape, t_gen *gen)
{
	t_coords	newray;
	t_inter		closest_shape;
	double		dist;
	double 		shape_dist;
	t_coords	newpoint;

	newray = vect_normalised(vect_sub(gen->l->coords, shape.point));
	closest_shape = find_closest_shape(newray, shape.point, gen->shapes, shape.shape);
	if (!closest_shape.shape || closest_shape.t == -1)
		return (0);
	dist = dot_prod(vect_sub(shape.point, gen->l->coords), newray);
	newpoint = vect_add(shape.point, vect_mult(newray, closest_shape.t));
	shape_dist = dot_prod(vect_sub(shape.point, newpoint), newray);
	if (dist < shape_dist - 1e-6)
		return (1);
	return (0);
}

double	calc_dif_int(t_inter shape, t_gen *gen)
{
	double		angle;
	t_coords	light_dir;
	//double		dist;

	light_dir = vect_normalised(vect_sub(gen->l->coords, shape.point));
	// if (shape->shape == PLANE)
	// {
	// 	if (dot_prod(n, light_dir) < 0)
	// 		n = vect_mult(n, -1);
	// }
	// if (shape->shape == CYLINDER)
	// {
	// 	dist = dot_prod(vect_sub(point, shape->coords), shape->vector);
	// 	if (dist >= shape->height / 2 - 1e-6 || dist <= -shape->height / 2 - 1e-6)
	// 	{
	// 		if (dot_prod(n, light_dir) < 0)
	// 			n = vect_mult(n, -1);
	// 	}
	// }
	angle = dot_prod(shape.normal, light_dir);
	// if (shape->shape == PLANE)
	// 	return (fabs(angle * gen->l->bright));
	if (angle <= 1e-6)
		return (0);
	return (angle * gen->l->bright);
}

static t_coords	refl_vect(t_vars *vars, t_inter shape)
{
	t_coords	light;
	t_coords	refl_v;

	light = vect_normalised(vect_sub(vect_add(vars->gen->c->coords, vect_mult(shape.ray, shape.t)), vars->gen->l->coords));
	refl_v = vect_normalised(vect_sub(vect_mult(shape.normal, 2 * dot_prod(light, shape.normal)), light));
	return (refl_v);
}

double	specular(t_vars *vars, t_inter shape)
{
	t_coords	refl;
	double		prod_RV;
	double		spec;

	refl = refl_vect(vars, shape);
	prod_RV = dot_prod(refl, shape.ray);
	if (prod_RV > 0)
		spec = pow(prod_RV, 25);
	else
		spec = 0;
	return (spec);
}

t_rgb	norm_rgb(t_rgb rgb)
{
	rgb.r = rgb.r / 255;
	rgb.g = rgb.g / 255;
	rgb.b = rgb.b / 255;
	return (rgb);
}

int	get_rgb(t_inter shape, t_gen *gen, t_vars *vars)
{
	double	dif_int;
	double	spec;
	t_rgb	spec_light;
	t_rgb	dif_light;
	t_rgb	amb_light;
    t_rgb    shape_col;
    double    tr;
    double    tg;
    double    tb;

	dif_int = calc_dif_int(shape, gen);
	spec = specular(vars, shape);
	// dif_int = 0;
	// gen->a->light = 0;
	if (in_shade(shape, gen))
		dif_int = 0;
	dif_light = norm_rgb(gen->l->rgb);
	dif_light.r =  dif_light.r * dif_int;
	dif_light.g =  dif_light.g * dif_int;
	dif_light.b =  dif_light.b * dif_int;
	spec_light = norm_rgb(gen->l->rgb);
	spec_light.r = spec_light.r * spec * gen->l->bright;
	spec_light.g = spec_light.g * spec * gen->l->bright;
	spec_light.b = spec_light.b * spec * gen->l->bright;
	amb_light = norm_rgb(gen->a->rgb);
	amb_light.r = amb_light.r * gen->a->light;
	amb_light.g = amb_light.g * gen->a->light;
	amb_light.b = amb_light.b * gen->a->light;
	shape_col = norm_rgb(shape.shape->rgb);
	tr = fmin(shape_col.r * (amb_light.r + dif_light.r) + spec_light.r, 1);
	tg = fmin(shape_col.g * (amb_light.g + dif_light.g) + spec_light.g, 1);
	tb = fmin(shape_col.b * (amb_light.b + dif_light.b) + spec_light.b, 1);
    return ((int)(tr * 255) << 16 | (int)(tg * 255) << 8 | (int)(tb * 255));
}

