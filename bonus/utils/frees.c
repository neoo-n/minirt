/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frees.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbaj <akabbaj@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 16:16:42 by akabbaj           #+#    #+#             */
/*   Updated: 2025/06/29 16:17:08 by akabbaj          ###   ########.ch       */
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

void	free_gen_saved(t_gen *gen)
{
	int	i;

	if (gen->a)
		free(gen->a);
	if (gen->c)
		free(gen->c);
	if (gen->l)
	{
		i = 0;
		while (gen->l[i])
		{
			free(gen->l[i]);
			i++;
		}
		free(gen->l);
	}
	if (gen->shapes)
	{
		i = -1;
		while (gen->shapes[++i])
			free(gen->shapes[i]);
		free(gen->shapes);
	}
	free(gen);
}

void	free_gen(t_gen *gen)
{
	int	i;

	if (gen->a)
		free(gen->a);
	if (gen->c)
		free(gen->c);
	if (gen->l)
	{
		i = -1;
		while (gen->l[++i])
			free(gen->l[i]);
		free(gen->l);
	}
	if (gen->shapes)
	{
		i = -1;
		while (gen->shapes[++i])
			free(gen->shapes[i]);
		free(gen->shapes);
	}
	free_characters(gen->character);
	if (gen->saved_gen)
		free_gen_saved(gen->saved_gen);
	free(gen);
}

void	free_characters(t_character *character)
{
	t_character	*next;

	while (character)
	{
		next = character->next;
		free(character);
		character = next;
	}
}
