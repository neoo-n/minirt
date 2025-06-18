/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   y.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbaj <akabbaj@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 16:53:20 by akabbaj           #+#    #+#             */
/*   Updated: 2025/06/18 16:53:20 by akabbaj          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "fonts.h"

void	init_y(int y[7][5])
{
	init_char(y);
	y[0][0] = 1;
	y[0][4] = 1;
	y[1][0] = 1;
	y[1][4] = 1;
	y[2][0] = 1;
	y[2][1] = 1;
	y[2][3] = 1;
	y[2][4] = 1;
	y[3][1] = 1;
	y[3][2] = 1;
	y[3][3] = 1;
	y[4][2] = 1;
	y[5][2] = 1;
	y[6][2] = 1;
	return ;
}

void	make_y(t_vars *vars, t_letter letter)
{
	int	x;
	int	y;
	int	step;
	int	yl[7][5];

	init_y(yl);
	step = letter.size / 7;
	y = 0;
	while (y < 7)
	{
		x = 0;
		while (x < 5)
		{
			if (yl[y][x] == 1)
				draw_part(vars, letter.i + x * step, letter.j + y * step, step);
			x++;
		}
		y++;
	}
}
