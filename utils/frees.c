/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frees.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbaj <akabbaj@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 16:38:52 by akabbaj           #+#    #+#             */
/*   Updated: 2025/05/27 16:46:01 by akabbaj          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	free_strarr_str(char **tofree, char *strtofree, int i)
{
	free_strarr(tofree);
	free(strtofree);
	return (i);
}

int	free_strarr(char **tofree)
{
	int	i;

	i = 0;
	if (!tofree)
		return (0);
	while (tofree[i])
	{
		if (tofree[i])
			free(tofree[i]);
		i++;
	}
	free(tofree);
	return (0);
}

char	**free_strarr_char(char **tofree)
{
	int	i;

	i = 0;
	if (!tofree)
		return (0);
	while (tofree[i])
	{
		if (tofree[i])
			free(tofree[i]);
		i++;
	}
	free(tofree);
	return (0);
}

void	free_gen(t_gen *gen)
{
	int	i;

	if (gen->a)
		free(gen->a);
	if (gen->c)
		free(gen->c);
	if (gen->l)
		free(gen->l);
	if (gen->shapes)
	{
		i = 0;
		while (gen->shapes[i])
		{
			free(gen->shapes[i]);
			i++;
		}
		free(gen->shapes);
	}
	free(gen);
}
