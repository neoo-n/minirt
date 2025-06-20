/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lighting.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvauthey <dvauthey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 15:51:34 by akabbaj           #+#    #+#             */
/*   Updated: 2025/06/20 11:59:12 by dvauthey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"

int	in_shade(t_inter shape, t_gen *gen, double angle)
{
	int			i;
	t_coords	newray;
	t_inter		closest_shape;
	double		dist[2];
	t_coords	newpoint;

	i = 0;
	angle = dot_prod(calc_norm(shape, shape.ray), shape.ray);
	if (angle >= -1e-6)
		return (1);
	while (gen->l[i])
	{
		newray = vect_normalised(vect_sub(gen->l[i]->coords, shape.point));
		closest_shape = find_closest_shape(newray, shape.point, gen->shapes,
				shape.shape);
		if (!closest_shape.shape || closest_shape.t == -1)
			return (0);
		dist[0] = dot_prod(vect_sub(shape.point, gen->l[i]->coords), newray);
		newpoint = vect_add(shape.point, vect_mult(newray, closest_shape.t));
		dist[1] = dot_prod(vect_sub(shape.point, newpoint), newray);
		if (dist[0] < dist[1] - 1e-6)
			return (1);
		i++;
	}
	return (0);
}

double	calc_dif_int(t_inter shape, t_gen *gen, t_light	*light)
{
	double		angle;
	t_coords	light_dir;

	light_dir = vect_normalised(vect_sub(light->coords, shape.point));
	angle = dot_prod(shape.normal, light_dir);
	if (angle <= 1e-6)
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
		spec = pow(prod_rv, 25);
	else
		spec = 0;
	return (spec);
}



int	get_rgb(t_inter shape, t_gen *gen, t_vars *vars)
{
	int		i;
	double	light[2];
	t_rgb	spec_light;
	t_rgb	dif_light;
	t_rgb	amb_light;
	t_rgb	shape_col;

	i = 0;
	while (gen->l[i])
	{
		if (in_shade(shape, gen, 0))
		{
			light[0] = 0;
			light[1] = 0;
		}
		else
		{
			light[0] += calc_dif_int(shape, gen, gen->l[i]);
			light[1] += specular(vars, shape, gen->l[i]);
		}
		dif_light = rgb_mult(norm_rgb(gen->l[i]->rgb), light[0]);
		spec_light = rgb_mult(norm_rgb(gen->l[i]->rgb), light[1] * gen->l[i]->bright);
		amb_light = rgb_mult(norm_rgb(gen->a->rgb), gen->a->light);
		i++;
	}
	shape_col = rgb_final(norm_rgb(shape.shape->rgb), amb_light,
			dif_light, spec_light);
	return ((int)(shape_col.r * 255) << 16 | (int)(shape_col.g * 255) << 8
		| (int)(shape_col.b * 255));
}
