/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   e.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbaj <akabbaj@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 16:59:25 by akabbaj           #+#    #+#             */
/*   Updated: 2025/06/18 16:59:25 by akabbaj          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "fonts.h"

void	init_e(int e[7][5])
{
	init_char(e);
	e[0][0] = 1;
	e[0][1] = 1;
	e[0][2] = 1;
	e[0][3] = 1;
	e[0][4] = 1;
	e[1][0] = 1;
	e[2][0] = 1;
	e[3][0] = 1;
	e[3][1] = 1;
	e[3][2] = 1;
	e[3][3] = 1;
	e[3][4] = 1;
	e[4][0] = 1;
	e[5][0] = 1;
	e[6][0] = 1;
	e[6][1] = 1;
	e[6][2] = 1;
	e[6][3] = 1;
	e[6][4] = 1;
	return ;
}

void	make_e(t_vars *vars, t_letter letter)
{
	int	x;
	int	y;
	int	step;
	int	e[7][5];

	init_e(e);
	step = letter.size / 7;
	y = 0;
	while (y < 7)
	{
		x = 0;
		while (x < 5)
		{
			if (e[y][x] == 1)
				draw_part(vars, letter.i + x * step, letter.j + y * step, step);
			x++;
		}
		y++;
	}
}
