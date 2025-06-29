/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   font.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbaj <akabbaj@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 15:56:48 by akabbaj           #+#    #+#             */
/*   Updated: 2025/06/29 15:58:03 by akabbaj          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "fonts.h"

void	init_char(int chr[7][5])
{
	int	i;
	int	j;

	i = 0;
	while (i < 5)
	{
		j = 0;
		while (j < 7)
		{
			chr[j][i] = 0;
			j++;
		}
		i++;
	}
	return ;
}

void	draw_part(int i, int j, int step, t_dataimg img)
{
	int	x;
	int	y;

	y = j;
	while (y < j + step)
	{
		x = i;
		while (x < i + step)
		{
			my_mlx_pixel_put(&(img), x, y, 0);
			x++;
		}
		y++;
	}
}

void	make_char(t_vars *vars, t_letter letter, t_dataimg img)
{
	int			x;
	int			y;
	int			step;
	t_character	*character;

	vars->colour = letter.colour;
	character = vars->gen->character;
	while (character && character->c != letter.letter)
		character = character->next;
	if (!character)
		return ;
	step = letter.size / 7;
	y = 0;
	while (y < 7)
	{
		x = 0;
		while (x < 5)
		{
			if (character->grid[y][x] == 1)
				draw_part(letter.i + x * step,
					letter.j + y * step, step, img);
			x++;
		}
		y++;
	}
}

t_character	*init_characters(void)
{
	int			i;
	t_character	*res;
	t_character	*next;

	res = malloc(sizeof(t_character));
	if (!res)
		return (0);
	next = res;
	i = -1;
	while ("abcdefghijklmnopqrstuvwxyz0123456789<>"[++i])
	{
		next->c = "abcdefghijklmnopqrstuvwxyz0123456789<>"[i];
		handle_let(next->grid, next->c);
		if (i < 37)
			next->next = malloc(sizeof(t_character));
		if (i < 37 && !next->next)
		{
			free_characters(res);
			return (0);
		}
		if (i < 37)
			next = next->next;
	}
	next->next = 0;
	return (res);
}
