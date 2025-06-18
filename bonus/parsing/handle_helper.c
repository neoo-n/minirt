/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_helper.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbaj <akabbaj@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 16:53:52 by akabbaj           #+#    #+#             */
/*   Updated: 2025/05/27 17:05:39 by akabbaj          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	parse_coords(char *line, int i, t_coords *coords)
{
	if (!valid_coords(line + i))
		return (-1);
	ins_coords(line + i, coords);
	if (!coords->valid)
		return (-1);
	return (next_elem(line, i));
}

int	parse_double(char *line, int i, double *value)
{
	if (!valid_double(line + i))
		return (-1);
	*value = ft_atof(line + i);
	if (*value <= 0)
		return (-1);
	return (next_elem(line, i));
}

int	parse_rgb(char *line, int i, t_rgb *rgb)
{
	if (!valid_rgb(line + i))
		return (-1);
	ins_rgb(line + i, rgb);
	return (next_elem(line, i));
}
