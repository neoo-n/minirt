/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbaj <akabbaj@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 16:59:34 by akabbaj           #+#    #+#             */
/*   Updated: 2025/06/18 16:59:34 by akabbaj          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "fonts.h"

void	init_g(int g[7][5])
{
	init_char(g);
	g[0][0] = 1;
	g[0][1] = 1;
	g[0][2] = 1;
	g[0][3] = 1;
	g[0][4] = 1;
	g[1][0] = 1;
	g[2][0] = 1;
	g[3][0] = 1;
	g[3][3] = 1;
	g[3][4] = 1;
	g[4][0] = 1;
	g[4][4] = 1;
	g[5][0] = 1;
	g[5][4] = 1;
	g[6][0] = 1;
	g[6][1] = 1;
	g[6][2] = 1;
	g[6][3] = 1;
	g[6][4] = 1;
	return ;
}

void	make_g(t_vars *vars, t_letter letter)
{
	int	x;
	int	y;
	int	step;
	int	g[7][5];

	init_g(g);
	step = letter.size / 7;
	y = 0;
	while (y < 7)
	{
		x = 0;
		while (x < 5)
		{
			if (g[y][x] == 1)
				draw_part(vars, letter.i + x * step, letter.j + y * step, step);
			x++;
		}
		y++;
	}
}
