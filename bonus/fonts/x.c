/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbaj <akabbaj@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 17:00:17 by akabbaj           #+#    #+#             */
/*   Updated: 2025/06/18 17:00:17 by akabbaj          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "fonts.h"

void	init_x(int x[7][5])
{
	init_char(x);
	x[0][0] = 1;
	x[0][4] = 1;
	x[1][0] = 1;
	x[1][4] = 1;
	x[2][1] = 1;
	x[2][3] = 1;
	x[3][2] = 1;
	x[4][1] = 1;
	x[4][3] = 1;
	x[5][0] = 1;
	x[5][4] = 1;
	x[6][0] = 1;
	x[6][4] = 1;
	return ;
}

void	make_x(t_vars *vars, t_letter letter)
{
	int	x;
	int	y;
	int	step;
	int	xl[7][5];

	init_x(xl);
	step = letter.size / 7;
	y = 0;
	while (y < 7)
	{
		x = 0;
		while (x < 5)
		{
			if (xl[y][x] == 1)
				draw_part(vars, letter.i + x * step, letter.j + y * step, step);
			x++;
		}
		y++;
	}
}
