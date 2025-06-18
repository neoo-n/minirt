/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbaj <akabbaj@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 16:56:15 by akabbaj           #+#    #+#             */
/*   Updated: 2025/06/18 16:56:15 by akabbaj          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "fonts.h"

void	init_t(int t[7][5])
{
	init_char(t);
	t[0][0] = 1;
	t[0][1] = 1;
	t[0][2] = 1;
	t[0][3] = 1;
	t[0][4] = 1;
	t[1][2] = 1;
	t[2][2] = 1;
	t[3][2] = 1;
	t[4][2] = 1;
	t[5][2] = 1;
	t[6][2] = 1;
	return ;
}

void	make_t(t_vars *vars, t_letter letter)
{
	int	x;
	int	y;
	int	step;
	int	t[7][5];

	init_t(t);
	step = letter.size / 7;
	y = 0;
	while (y < 7)
	{
		x = 0;
		while (x < 5)
		{
			if (t[y][x] == 1)
				draw_part(vars, letter.i + x * step, letter.j + y * step, step);
			x++;
		}
		y++;
	}
}
