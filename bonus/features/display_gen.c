/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_gen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbaj <akabbaj@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 17:23:24 by akabbaj           #+#    #+#             */
/*   Updated: 2025/06/26 17:25:56 by akabbaj          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "features.h"

void	print_gen(t_gen *gen)
{
	int	i;

	printf("A %.2f %.0f,%.0f,%.0f\n\n", gen->a->light, gen->a->rgb.r,
		gen->a->rgb.g, gen->a->rgb.b);
	printf("C %.2f,%.2f,%.2f %.2f,%.2f,%.2f, %.2f\n\n", gen->c->coords.x, gen->c->coords.y,
		gen->c->coords.z, gen->c->vector.x, gen->c->vector.y, gen->c->vector.z,
		gen->c->fov);
	i = 0;
	while (gen->l[i])
	{
		printf("L %.2f,%.2f,%.2f %.2f %.0f,%.0f,%.0f\n", gen->l[i]->coords.x,
			gen->l[i]->coords.y, gen->l[i]->coords.z, gen->l[i]->bright,
			gen->l[i]->rgb.r, gen->l[i]->rgb.g, gen->l[i]->rgb.b);
		i++;
	}
	printf("\n");
	i = 0;
	while (gen->shapes[i])
	{
		if (gen->shapes[i]->shape == PLANE)
			printf("pl ");
		else if (gen->shapes[i]->shape == SPHERE)
			printf("sp ");
		else if (gen->shapes[i]->shape == CYLINDER)
			printf("cy ");
		printf("%.2f,%.2f,%.2f ", gen->shapes[i]->coords.x, gen->shapes[i]->coords.y,
			gen->shapes[i]->coords.z);
		if (gen->shapes[i]->shape == CYLINDER || gen->shapes[i]->shape == PLANE)
			printf("%.2f,%.2f,%.2f ", gen->shapes[i]->vector.x,
				gen->shapes[i]->vector.y, gen->shapes[i]->vector.z);
		if (gen->shapes[i]->shape == CYLINDER || gen->shapes[i]->shape == SPHERE)
			printf("%.2f ", gen->shapes[i]->diam);
		if (gen->shapes[i]->shape == CYLINDER)
			printf("%.2f ", gen->shapes[i]->height);
		printf("%.0f,%.0f,%.0f\n", gen->shapes[i]->rgb.r, gen->shapes[i]->rgb.g,
			gen->shapes[i]->rgb.b);
		i++;
	}
	printf("\n");
}
