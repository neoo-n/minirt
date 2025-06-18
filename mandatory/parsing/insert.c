/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbaj <akabbaj@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 10:51:00 by akabbaj           #+#    #+#             */
/*   Updated: 2025/06/18 10:51:07 by akabbaj          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	ins_rgb(char *str, t_rgb *rgb)
{
	char	**split_rgb;

	split_rgb = ft_split(str, ",");
	if (!split_rgb)
	{
		rgb->r = -1;
		return ;
	}
	rgb->r = (int) ft_datoi(split_rgb[0]);
	rgb->g = (int) ft_datoi(split_rgb[1]);
	rgb->b = (int) ft_datoi(split_rgb[2]);
	free_strarr(split_rgb);
	return ;
}

void	ins_coords(char *str, t_coords *coords)
{
	char	**split_coords;

	split_coords = ft_split(str, ",");
	if (!split_coords)
	{
		coords->valid = 0;
		return ;
	}
	coords->valid = 1;
	coords->x = ft_atof(split_coords[0]);
	coords->y = ft_atof(split_coords[1]);
	coords->z = ft_atof(split_coords[2]);
	free_strarr(split_coords);
	if (coords->x > 1 || coords->x < -1 || coords->y > 1 || coords->y < -1
		|| coords->z > 1 || coords->z < -1 || (coords->x == 0 && coords->y == 0
			&& coords->z == 0))
		coords->valid = 2;
	return ;
}
