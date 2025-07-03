/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_helper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbaj <akabbaj@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 16:00:06 by akabbaj           #+#    #+#             */
/*   Updated: 2025/07/03 16:00:06 by akabbaj          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	shape_len(t_shape **o_shape)
{
	int	i;

	i = 0;
	while (o_shape[i])
		i++;
	return (i);
}

void	check_copy(t_gen *res, int copy)
{
	if (!copy)
	{
		res->l = malloc(sizeof(t_light *));
		res->shapes = malloc(sizeof(t_shape *));
	}
	else
	{
		res->l = 0;
		res->shapes = 0;
	}
}

t_gen	*handle_err(t_errmes mes, char *line, int i, t_gen *res)
{
	print_error(mes, line, i);
	free(line);
	free_gen(res);
	return (0);
}

int	init_elem(t_gen *gen, char *line)
{
	if (line[0] == 'A')
		return (handle_a(gen, line));
	if (line[0] == 'C')
		return (handle_c(gen, line));
	if (line[0] == 'L')
		return (handle_l(gen, line, 0));
	if (line[0] == 's')
		return (handle_sp(gen, line, 0));
	if (line[0] == 'p')
		return (handle_pl(gen, line, 0));
	if (line[0] == 'c' || line[0] == 't')
		return (handle_cts(gen, line, 0));
	return (0);
}
