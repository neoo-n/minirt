/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specular.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvauthey <dvauthey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 11:45:55 by dvauthey          #+#    #+#             */
/*   Updated: 2025/06/13 15:04:33 by dvauthey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static t_coords	calc_norm(t_shape *shape, t_coords ray, t_coords origin)
{
	t_coords	n;
	t_coords	x;
	t_coords	point;
	double		dist;

	if (shape->shape == PLANE)
		return (shape->vector);
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

static t_coords	refl_vect(t_vars *vars, t_coords vision, t_shape *shape)
{
	t_coords	norm;
	t_coords	light;
	t_coords	refl_v;

	norm = calc_norm(shape, vision, vars->gen->c->coords);
	light = vect_normalised(vect_sub(vect_add(vars->gen->c->coords, vect_mult(vision, shape->t)), vars->gen->l->coords));
	refl_v = vect_normalised(vect_sub(vect_mult(norm, 2 * dot_prod(light, norm)), light));
	return (refl_v);
}

t_rgb	specular(t_vars *vars, t_coords vision, t_shape *shape)
{
	t_coords	refl;
	double		prod_RV;
	double		spec;
	t_rgb		color;

	refl = refl_vect(vars, vision, shape);
	prod_RV = dot_prod(refl, vision);
	if (prod_RV > 0)
	{
		spec = pow(prod_RV, vars->gen->l->bright);
		printf("\n --------------------------------------- \n");
		printf("spec : %f\n", spec);
		color.r = vars->gen->l->rgb.r * spec;
		printf("red : %d, %d\n", vars->gen->l->rgb.r, color.r);
		color.g = vars->gen->l->rgb.g * spec;
		printf("green: %d, %d\n", vars->gen->l->rgb.g, color.g);
		color.b = vars->gen->l->rgb.b * spec;
		printf("blue: %d, %d\n", vars->gen->l->rgb.b, color.b);
	}
	else
		spec = 0;
	return (color);
}
