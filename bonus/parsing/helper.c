/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbaj <akabbaj@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 16:03:14 by akabbaj           #+#    #+#             */
/*   Updated: 2025/06/09 16:03:14 by akabbaj          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	arr_len(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}

int	is_numeric(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '\n')
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	find_end(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != ' ' && str[i] != '\n')
		i++;
	return (i);
}

int	next_elem(char *line, int i)
{
	while (line[i] != ' ' && line[i])
		i++;
	while (line[i] == ' ' && line[i])
		i++;
	return (i);
}

t_shape	**realloc_shape(t_shape **shapes, t_shape *new_shape)
{
	int		len;
	int		i;
	t_shape	**res;

	len = 0;
	while (shapes[len])
		len++;
	res = ft_calloc(len + 2, sizeof(t_shape *));
	if (!res)
		return (0);
	i = 0;
	while (shapes[i])
	{
		res[i] = shapes[i];
		i++;
	}
	res[i++] = new_shape;
	res[i] = 0;
	free(shapes);
	return (res);
}
