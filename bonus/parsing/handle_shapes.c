/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_shapes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvauthey <dvauthey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 16:07:18 by akabbaj           #+#    #+#             */
/*   Updated: 2025/06/18 14:35:13 by dvauthey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	handle_sp(t_gen *gen, char *line, int i)
{
	t_shape	*shape;

	shape = malloc(sizeof(t_shape));
	if (!shape)
		return (0);
	shape->shape = SPHERE;
	i = next_elem(line, 0);
	i = parse_coords(line, i, &shape->coords);
	if (i == -1)
		return (free(shape), 0);
	i = parse_double(line, i, &shape->diam);
	if (i == -1)
		return (free(shape), 0);
	i = parse_rgb(line, i, &shape->rgb);
	if (i == -1)
		return (free(shape), 0);
	if (line[i] && line[i] != '\n')
		return (free(shape), 0);
	gen->shapes = realloc_shape(gen->shapes, shape);
	if (!gen->shapes)
		return (free(shape), 0);
	return (1);
}

int	handle_pl(t_gen *gen, char *line, int i)
{
	t_shape	*shape;

	shape = malloc(sizeof(t_shape));
	if (!shape)
		return (0);
	shape->shape = PLANE;
	i = next_elem(line, 0);
	i = parse_coords(line, i, &shape->coords);
	if (i == -1)
		return (free(shape), 0);
	i = parse_coords(line, i, &shape->vector);
	if (i == -1)
		return (free(shape), 0);
	if (shape->vector.valid != 1)
		return (free(shape), 0);
	i = parse_rgb(line, i, &shape->rgb);
	if (i == -1)
		return (free(shape), 0);
	if (line[i] && line[i] != '\n')
		return (free(shape), 0);
	gen->shapes = realloc_shape(gen->shapes, shape);
	if (!gen->shapes)
		return (free(shape), 0);
	return (1);
}

int	c_helper(t_shape *shape, char *line, int i)
{
	i = parse_double(line, i, &shape->diam);
	if (i == -1)
		return (-1);
	i = parse_double(line, i, &shape->height);
	if (i == -1)
		return (-1);
	i = parse_rgb(line, i, &shape->rgb);
	if (i == -1)
		return (-1);
	return (i);
}

int	handle_cs(t_gen *gen, char *line, int i)
{
	t_shape	*shape;

	shape = malloc(sizeof(t_shape));
	if (!shape)
		return (0);
	shape->shape = CYLINDER;
	if (line[1] == 'o')
		shape->shape = CONE;
	i = parse_coords(line, next_elem(line, 0), &shape->coords);
	if (i == -1)
		return (free(shape), 0);
	i = parse_coords(line, i, &shape->vector);
	if (i == -1)
		return (free(shape), 0);
	if (shape->vector.valid != 1)
		return (free(shape), 0);
	i = c_helper(shape, line, i);
	if (i == -1)
		return (free(shape), 0);
	if (line[i] && line[i] != '\n')
		return (free(shape), 0);
	gen->shapes = realloc_shape(gen->shapes, shape);
	if (!gen->shapes)
		return (free(shape), 0);
	return (1);
}
