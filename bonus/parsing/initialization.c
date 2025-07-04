/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvauthey <dvauthey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 16:00:03 by akabbaj           #+#    #+#             */
/*   Updated: 2025/07/03 16:36:19 by dvauthey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

t_gen	*init_gen(int copy)
{
	t_gen	*res;

	res = malloc(sizeof(t_gen));
	if (!res)
		return (0);
	res->a = malloc(sizeof(t_amb));
	res->c = malloc(sizeof(t_cam));
	check_copy(res, copy);
	if (!res->c || !res->a || (!copy && (!res->shapes || !res->l)))
	{
		free_gen(res);
		return (0);
	}
	res->a->light = -1;
	res->c->fov = -1;
	if (!copy)
	{
		res->l[0] = 0;
		res->shapes[0] = 0;
	}
	return (res);
}

t_light	**copy_lights(t_light **o_light)
{
	t_light	**new_light;
	int		i;

	i = 0;
	while (o_light[i])
		i++;
	new_light = malloc(sizeof(t_light *) * (i + 1));
	if (!new_light)
		return (0);
	i = 0;
	while (o_light[i])
	{
		new_light[i] = malloc(sizeof(t_light));
		if (!new_light[i])
			return (0);
		new_light[i]->bright = o_light[i]->bright;
		new_light[i]->coords = o_light[i]->coords;
		new_light[i]->rgb = o_light[i]->rgb;
		i++;
	}
	new_light[i] = 0;
	return (new_light);
}

t_shape	**copy_shapes(t_shape **o_shape, int i)
{
	t_shape	**new_shape;

	new_shape = malloc(sizeof(t_shape *) * (shape_len(o_shape) + 1));
	if (!new_shape)
		return (0);
	while (o_shape[++i])
	{
		new_shape[i] = malloc(sizeof(t_shape));
		if (!new_shape[i])
			return (0);
		new_shape[i]->shape = o_shape[i]->shape;
		new_shape[i]->coords = o_shape[i]->coords;
		new_shape[i]->rgb = o_shape[i]->rgb;
		if (new_shape[i]->shape == CYLINDER || new_shape[i]->shape == SPHERE
			|| new_shape[i]->shape == CONE)
			new_shape[i]->diam = o_shape[i]->diam;
		if (new_shape[i]->shape == CYLINDER || new_shape[i]->shape == CONE)
			new_shape[i]->height = o_shape[i]->height;
		if (new_shape[i]->shape == CYLINDER || new_shape[i]->shape == PLANE
			|| new_shape[i]->shape == CONE)
			new_shape[i]->vector = o_shape[i]->vector;
	}
	new_shape[i] = 0;
	return (new_shape);
}

t_gen	*copy_gen(t_gen *o_gen)
{
	t_gen	*new_gen;

	new_gen = init_gen(1);
	if (!new_gen)
		return (0);
	new_gen->a->light = o_gen->a->light;
	new_gen->a->rgb = o_gen->a->rgb;
	new_gen->c->coords = o_gen->c->coords;
	new_gen->c->fov = o_gen->c->fov;
	new_gen->c->vector = o_gen->c->vector;
	new_gen->character = o_gen->character;
	new_gen->l = copy_lights(o_gen->l);
	if (!new_gen->l)
	{
		free_gen(new_gen);
		return (0);
	}
	new_gen->shapes = copy_shapes(o_gen->shapes, -1);
	if (!new_gen->shapes)
	{
		free_gen(new_gen);
		return (0);
	}
	new_gen->saved_gen = 0;
	return (new_gen);
}

t_gen	*parse_file(int fd, int i)
{
	char	*line;
	t_gen	*res;

	res = init_gen(0);
	if (!res)
		return (0);
	line = get_next_line(fd);
	while (line)
	{
		i++;
		if (line[0] == '\n')
		{
			free(line);
			line = get_next_line(fd);
			continue ;
		}
		if (!valid_line(line))
			return (handle_err(PARSE_ERR, line, i, res));
		if (!init_elem(res, line))
			return (handle_err(PARSE_ERR, line, i, res));
		free(line);
		line = get_next_line(fd);
	}
	return (res);
}
