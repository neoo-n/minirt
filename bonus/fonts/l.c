/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbaj <akabbaj@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 16:59:47 by akabbaj           #+#    #+#             */
/*   Updated: 2025/06/18 16:59:47 by akabbaj          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "fonts.h"

void	init_l(int l[7][5])
{
	init_char(l);
	l[0][0] = 1;
	l[1][0] = 1;
	l[2][0] = 1;
	l[3][0] = 1;
	l[4][0] = 1;
	l[5][0] = 1;
	l[6][0] = 1;
	l[6][1] = 1;
	l[6][2] = 1;
	l[6][3] = 1;
	l[6][4] = 1;
	return ;
}

void	make_l(t_vars *vars, t_letter letter)
{
	int	x;
	int	y;
	int	step;
	int	l[7][5];

	init_l(l);
	step = letter.size / 7;
	y = 0;
	while (y < 7)
	{
		x = 0;
		while (x < 5)
		{
			if (l[y][x] == 1)
				draw_part(vars, letter.i + x * step, letter.j + y * step, step);
			x++;
		}
		y++;
	}
}
