/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbaj <akabbaj@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 16:59:19 by akabbaj           #+#    #+#             */
/*   Updated: 2025/06/18 16:59:19 by akabbaj          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "fonts.h"

void	init_c(int c[7][5])
{
	init_char(c);
	c[0][0] = 1;
	c[0][1] = 1;
	c[0][2] = 1;
	c[0][3] = 1;
	c[0][4] = 1;
	c[1][0] = 1;
	c[2][0] = 1;
	c[3][0] = 1;
	c[4][0] = 1;
	c[5][0] = 1;
	c[6][0] = 1;
	c[6][1] = 1;
	c[6][2] = 1;
	c[6][3] = 1;
	c[6][4] = 1;
	return ;
}

void	make_c(t_vars *vars, t_letter letter)
{
	int	x;
	int	y;
	int	step;
	int	c[7][5];

	init_c(c);
	step = letter.size / 7;
	y = 0;
	while (y < 7)
	{
		x = 0;
		while (x < 5)
		{
			if (c[y][x] == 1)
				draw_part(vars, letter.i + x * step, letter.j + y * step, step);
			x++;
		}
		y++;
	}
}
