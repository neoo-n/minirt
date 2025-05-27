/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbaj <akabbaj@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 15:58:29 by akabbaj           #+#    #+#             */
/*   Updated: 2025/05/27 15:58:29 by akabbaj          ###   ########.ch       */
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
	int		j;

	rgb = ft_split(str, ",");
	if (!rgb)
		return (0);
	i = 0;
	while (rgb[i])
		i++;
	if (i != 3)
		return (free_strarr(rgb));
	i = 0;
	while (rgb[i])
	{
		j = 0;
		while (rgb[i][j] && rgb[i][j] != '\n')
		{
			if (rgb[i][j] < '0' || rgb[i][j] > '9')
				return (free_strarr(rgb));
			j++;
		}
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
	int		i;
	int		j;

	str = ft_substr(str, 0, find_end(str));
	if (!str)
		return (0);
	split_res = ft_split(str, ".");
	if (!split_res)
		return (free(str), 0);
	i = 0;
	while (split_res[i])
		i++;
	if (i != 1 && i != 2)
	{
		free(str);
		return (free_strarr(split_res));
	}
	j = 0;
	if (split_res[0][0] == '-')
		j++;
	while (split_res[0][j] && split_res[0][j] != '\n' && split_res[0][j] != ' ')
	{
		if (split_res[0][j] < '0' || split_res[0][j] > '9')
		{
			free(str);
			return (free_strarr(split_res));
		}
		j++;
	}
	if (i == 1)
	{
		free(str);
		free_strarr(split_res);
		return (1);
	}
	if (!split_res[0][0] || !split_res[1][0])
	{
		free(str);
		return (0);
	}
	j = 0;
	while (split_res[1][j] && split_res[1][j] != '\n' && split_res[1][j] != ' ')
	{
		if (split_res[1][j] < '0' || split_res[1][j] > '9')
		{
			free(str);
			return (free_strarr(split_res));
		}
		j++;
	}
	free(str);
	free_strarr(split_res);
	return (1);
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
	{
		free(str);
		return (0);
	}
	i = 0;
	while (coords[i])
		i++;
	if (i != 3)
	{
		free(str);
		return (free_strarr(coords));
	}
	i = 0;
	while (i < 3)
	{
		if (!valid_double(coords[i]))
		{
			free(str);
			return (free_strarr(coords));
		}
		i++;
	}
	free(str);
	free_strarr(coords);
	return (1);
}
