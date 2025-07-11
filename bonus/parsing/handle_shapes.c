/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_shapes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvauthey <dvauthey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 14:58:51 by akabbaj           #+#    #+#             */
/*   Updated: 2025/07/03 15:09:14 by dvauthey         ###   ########.fr       */
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

static t_id	which_type_ct(char *line)
{
	if (line[1] == 'y')
		return (CYLINDER);
	else
		return (CONE);
}

int	handle_cts(t_gen *gen, char *line, int i)
{
	t_shape	*shape;

	shape = malloc(sizeof(t_shape));
	if (!shape)
		return (0);
	shape->shape = which_type_ct(line);
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
