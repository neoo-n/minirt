/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_shapes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbaj <akabbaj@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 15:56:11 by akabbaj           #+#    #+#             */
/*   Updated: 2025/05/27 15:56:11 by akabbaj          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	handle_sp(t_gen *gen, char *line)
{
	t_shape	*shape;
	int		i;

	shape = malloc(sizeof(t_shape));
	if (!shape)
		return (0);
	shape->shape = SPHERE;
	i = next_elem(line, 0);
	if (!valid_coords(line + i))
		return (free(shape), 0);
	ins_coords(line + i, &shape->coords);
	if (!shape->coords.valid)
		return (free(shape), 0);
	i = next_elem(line, i);
	if (!(valid_double(line + i) && ft_atof(line + i) > 0))
		return (free(shape), 0);
	shape->diam = ft_atof(line + i);
	i = next_elem(line, i);
	if (!valid_rgb(line + i))
		return (free(shape), 0);
	ins_rgb(line + i, &shape->rgb);
	i = next_elem(line, i);
	if (line[i] && line[i] != '\n')
		return (free(shape), 0);
	gen->shapes = realloc_shape(gen->shapes, shape);
	if (!gen->shapes)
		return (free(shape), 0);
	return (1);
}

int	handle_pl(t_gen *gen, char *line)
{
	t_shape	*shape;
	int		i;

	shape = malloc(sizeof(t_shape));
	if (!shape)
		return (0);
	shape->shape = PLANE;
	i = next_elem(line, 0);
	if (!valid_coords(line + i))
		return (free(shape), 0);
	ins_coords(line + i, &shape->coords);
	if (!shape->coords.valid)
		return (free(shape), 0);
	i = next_elem(line, i);
	if (!valid_coords(line + i))
		return (0);
	ins_coords(line + i, &shape->vector);
	if (shape->vector.valid != 1)
		return (0);
	i = next_elem(line, i);
	if (!valid_rgb(line + i))
		return (free(shape), 0);
	ins_rgb(line + i, &shape->rgb);
	i = next_elem(line, i);
	if (line[i] && line[i] != '\n')
		return (free(shape), 0);
	gen->shapes = realloc_shape(gen->shapes, shape);
	if (!gen->shapes)
		return (free(shape), 0);
	return (1);
}

int	handle_cy(t_gen *gen, char *line)
{
	t_shape	*shape;
	int		i;

	shape = malloc(sizeof(t_shape));
	if (!shape)
		return (0);
	shape->shape = CYLINDER;
	i = next_elem(line, 0);
	if (!valid_coords(line + i))
		return (free(shape), 0);
	ins_coords(line + i, &shape->coords);
	if (!shape->coords.valid)
		return (free(shape), 0);
	i = next_elem(line, i);
	if (!valid_coords(line + i))
		return (0);
	ins_coords(line + i, &shape->vector);
	if (gen->c->vector.valid != 1)
		return (0);
	i = next_elem(line, i);
	if (!(valid_double(line + i) && ft_atof(line + i) > 0))
		return (free(shape), 0);
	shape->diam = ft_atof(line + i);
	i = next_elem(line, i);
	if (!(valid_double(line + i) && ft_atof(line + i) > 0))
		return (free(shape), 0);
	shape->height = ft_atof(line + i);
	i = next_elem(line, i);
	if (!valid_rgb(line + i))
		return (free(shape), 0);
	ins_rgb(line + i, &shape->rgb);
	i = next_elem(line, i);
	if (line[i] && line[i] != '\n')
		return (free(shape), 0);
	gen->shapes = realloc_shape(gen->shapes, shape);
	if (!gen->shapes)
		return (free(shape), 0);
	return (1);
}
