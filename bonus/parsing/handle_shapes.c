/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbaj <akabbaj@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 09:38:14 by akabbaj           #+#    #+#             */
/*   Updated: 2025/06/26 09:38:14 by akabbaj          ###   ########.ch       */
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

int	cy_helper(t_shape *shape, char *line, int i)
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

int	handle_cy(t_gen *gen, char *line, int i)
{
	t_shape	*shape;

	shape = malloc(sizeof(t_shape));
	if (!shape)
		return (0);
	shape->shape = CYLINDER;
	i = parse_coords(line, next_elem(line, 0), &shape->coords);
	if (i == -1)
		return (free(shape), 0);
	i = parse_coords(line, i, &shape->vector);
	if (i == -1)
		return (free(shape), 0);
	if (shape->vector.valid != 1)
		return (free(shape), 0);
	i = cy_helper(shape, line, i);
	if (i == -1)
		return (free(shape), 0);
	if (line[i] && line[i] != '\n')
		return (free(shape), 0);
	gen->shapes = realloc_shape(gen->shapes, shape);
	if (!gen->shapes)
		return (free(shape), 0);
	return (1);
}
