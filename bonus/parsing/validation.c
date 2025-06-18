/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbaj <akabbaj@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 16:04:10 by akabbaj           #+#    #+#             */
/*   Updated: 2025/06/09 16:05:05 by akabbaj          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	valid_line(char *line)
{
	if (line[0] == '\n')
		return (1);
	if (ft_strncmp(line, "A ", 2) || ft_strncmp(line, "C ", 2)
		|| ft_strncmp(line, "L ", 2))
		return (1);
	if (ft_strncmp(line, "sp ", 3) || ft_strncmp(line, "pl ", 3)
		|| ft_strncmp(line, "cy ", 3))
		return (1);
	return (0);
}

int	valid_ratio(char *str)
{
	int	i;

	if (str[0] != '0' && str[0] != '1')
		return (0);
	if (str[1] != ' ' && str[1] != '.')
		return (0);
	if (str[1] == '.')
	{
		if (str[2] == ' ')
			return (0);
		i = 2;
		while (str[i] != ' ' && str[i])
		{
			if (str[i] < '0' || str[i] > '9')
				return (0);
			i++;
		}
		if (!str[i])
			return (0);
	}
	return (1);
}

int	valid_rgb(char *str)
{
	char	**rgb;
	int		i;

	rgb = ft_split(str, ",");
	if (!rgb)
		return (0);
	i = 0;
	if (arr_len(rgb) != 3)
		return (free_strarr(rgb));
	while (rgb[i])
	{
		if (!is_numeric(rgb[i]))
			return (free_strarr(rgb));
		if (ft_datoi(rgb[i]) < 0 || ft_datoi(rgb[i]) > 255)
			return (free_strarr(rgb));
		i++;
	}
	free_strarr(rgb);
	return (1);
}

int	valid_double(char *str)
{
	char	**split_res;
	int		j;

	str = ft_substr(str, 0, find_end(str));
	if (!str)
		return (0);
	split_res = ft_split(str, ".");
	if (!split_res)
		return (free(str), 0);
	if (arr_len(split_res) != 1 && arr_len(split_res) != 2)
		return (free_strarr_str(split_res, str, 0));
	j = 0;
	if (split_res[0][0] == '-')
		j++;
	if (!is_numeric(split_res[0] + j))
		return (free_strarr_str(split_res, str, 0));
	if (arr_len(split_res) == 1)
		return (free_strarr_str(split_res, str, 1));
	if (!split_res[0][0] || !split_res[1][0])
		return (free_strarr_str(split_res, str, 0));
	if (!is_numeric(split_res[1]))
		return (free_strarr_str(split_res, str, 0));
	return (free_strarr_str(split_res, str, 1));
}

int	valid_coords(char *str)
{
	char	**coords;
	int		i;

	str = ft_substr(str, 0, find_end(str));
	if (!str)
		return (0);
	coords = ft_split(str, ",");
	if (!coords)
		return (free(str), 0);
	i = 0;
	while (coords[i])
		i++;
	if (i != 3)
		return (free_strarr_str(coords, str, 0));
	i = 0;
	while (i < 3)
	{
		if (!valid_double(coords[i]))
			return (free_strarr_str(coords, str, 0));
		i++;
	}
	return (free_strarr_str(coords, str, 1));
}
