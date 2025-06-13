/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lighting.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvauthey <dvauthey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 14:26:34 by akabbaj           #+#    #+#             */
/*   Updated: 2025/06/13 11:52:04 by dvauthey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"

t_coords	calc_norm(t_shape *shape, t_coords ray, t_coords origin)
{
	t_coords	n;
	t_coords	x;
	t_coords	point;
	double		dist;

	if (shape->shape == PLANE)
	{
		t_coords normal = shape->vector;
		if (dot_prod(normal, ray) > 0)
			normal = vect_mult(normal, -1);
		return normal;
	}
	point = vect_add(origin, vect_mult(ray, shape->t));
	if (shape->shape == SPHERE)
		n = vect_normalised(vect_sub(point, shape->coords));
	if (shape->shape == CYLINDER)
	{
		dist = dot_prod(vect_sub(point, shape->coords), shape->vector);
		if (fabs(dist - shape->height / 2) < 1e-6)
			n = vect_normalised(shape->vector);
		else if (fabs(dist + shape->height / 2) < 1e-6)
			n = vect_normalised(vect_mult(shape->vector, -1));
		else if (dist > -shape->height / 2 && dist < shape->height / 2)
		{
			x = vect_add(shape->coords, vect_mult(shape->vector, dist));
			n = vect_normalised(vect_sub(point, x));
		}
	}	
	return (n);
}

int	in_shade(t_shape *shape, t_gen *gen, t_coords ray, t_coords origin)
{
	t_coords	point;
	t_coords	newray;
	t_shape		*closest_shape;
	double		dist;
	double 		shape_dist;
	t_coords	newpoint;

	point = vect_add(origin, vect_mult(ray, shape->t));
	newray = vect_normalised(vect_sub(gen->l->coords, point));
	closest_shape = find_closest_shape(newray, point, gen->shapes, shape);
	if (!closest_shape || closest_shape->t == -1 || closest_shape->shape == PLANE)
		return (0);
	dist = dot_prod(vect_sub(point, gen->l->coords), newray);
	newpoint = vect_add(point, vect_mult(newray, closest_shape->t));
	shape_dist = dot_prod(vect_sub(point, newpoint), newray);
	if (dist < shape_dist - 1e-6)
		return (1);
	return (0);
}

double	calc_dif_int(t_shape *shape, t_gen *gen, t_coords ray, t_coords origin)
{
	t_coords	n;
	double		angle;
	t_coords	point;
	t_coords	light_dir;
	//double		dist;

	point = vect_add(origin, vect_mult(ray, shape->t));
	light_dir = vect_normalised(vect_sub(gen->l->coords, point));
	n = calc_norm(shape, ray, origin);
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
	angle = dot_prod(n, light_dir);
	// if (shape->shape == PLANE)
	// 	return (fabs(angle * gen->l->bright));
	if (angle <= 1e-6)
		return (0);
	return (angle * gen->l->bright);
}

static t_coords	refl_vect(t_vars *vars, t_coords ray, t_shape *shape)
{
	t_coords	norm;
	t_coords	light;
	t_coords	refl_v;

	norm = calc_norm(shape, ray, vars->gen->c->coords);
	light = vect_normalised(vect_sub(vect_add(vars->gen->c->coords, vect_mult(ray, shape->t)), vars->gen->l->coords));
	refl_v = vect_normalised(vect_sub(vect_mult(norm, 2 * dot_prod(light, norm)), light));
	return (refl_v);
}

double	specular(t_vars *vars, t_coords ray, t_shape *shape)
{
	t_coords	refl;
	double		prod_HN;
	double		spec;
	// t_rgb		color;

	refl = refl_vect(vars, ray, shape);
	prod_HN = dot_prod(refl, ray);
	if (prod_HN > 0)
	{
		spec = pow(prod_HN, vars->gen->l->bright);
		printf("refl_v : (%f, %f, %f), prod_HN : %f, spec : %f\n", refl.x, refl.y, refl.z, prod_HN, spec);
		if (spec > 1)
			spec = 1;
		//printf("\n --------------------------------------- \n");
		//("spec : %f\n", spec);
		// color.r = vars->gen->l->rgb.r * spec;
		// //printf("red : %d, %d\n", vars->gen->l->rgb.r, color.r);
		// color.g = vars->gen->l->rgb.g * spec;
		// //printf("green: %d, %d\n", vars->gen->l->rgb.g, color.g);
		// color.b = vars->gen->l->rgb.b * spec;
		//printf("blue: %d, %d\n", vars->gen->l->rgb.b, color.b);
	}
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

int	get_rgb(t_shape *shape, t_gen *gen, t_coords ray, t_coords origin, t_vars *vars)
{
	double	dif_int;
	double	spec;
	t_rgb	spec_light;
	t_rgb	dif_light;
	t_rgb	amb_light;

	dif_int = calc_dif_int(shape, gen, ray, origin);
	spec = specular(vars, ray, shape);
	// dif_int = 0;
	// gen->a->light = 0;
	if (in_shade(shape, gen, ray, origin))
		dif_int = 0;
	dif_light = norm_rgb(gen->l->rgb);
	dif_light.r =  dif_light.r * dif_int;
	dif_light.g =  dif_light.g * dif_int;
	dif_light.b =  dif_light.b * dif_int;
	spec_light.r = dif_light.r * spec;
	spec_light.g = dif_light.g * spec;
	spec_light.b = dif_light.b * spec;
	amb_light = norm_rgb(gen->a->rgb);
	amb_light.r =  amb_light.r * gen->a->light;
	amb_light.g =  amb_light.g * gen->a->light;
	amb_light.b =  amb_light.b * gen->a->light;
	return ((int)(shape->rgb.r * fmin(dif_light.r + amb_light.r + spec_light.r, 1)) << 16 | (int)(shape->rgb.g * fmin(dif_light.g + amb_light.g + spec_light.g, 1)) << 8 | (int)(shape->rgb.b * fmin(dif_light.b + amb_light.b + spec_light.b, 1)));
}
