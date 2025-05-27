/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbaj <akabbaj@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 17:08:35 by akabbaj           #+#    #+#             */
/*   Updated: 2025/05/27 17:08:35 by akabbaj          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

t_gen	*init_gen(void)
{
	t_gen	*res;

	res = malloc(sizeof(t_gen));
	if (!res)
		return (0);
	res->a = malloc(sizeof(t_amb));
	res->c = malloc(sizeof(t_cam));
	res->l = malloc(sizeof(t_light));
	res->shapes = malloc(sizeof(t_shape *));
	if (!res->shapes || !res->a || !res->c || !res->l)
	{
		free_gen(res);
		return (0);
	}
	res->a->light = -1;
	res->c->fov = -1;
	res->l->bright = -1;
	res->shapes[0] = 0;
	return (res);
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
	if (line[0] == 'c')
		return (handle_cy(gen, line, 0));
	return (0);
}

t_gen	*handle_err(t_errmes mes, char *line, int i, t_gen *res)
{
	print_error(mes, line, i);
	free(line);
	free_gen(res);
	return (0);
}

t_gen	*parse_file(int fd, int i)
{
	char	*line;
	t_gen	*res;

	line = get_next_line(fd);
	res = init_gen();
	if (!res)
		return (0);
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
	close(fd);
	return (res);
}
