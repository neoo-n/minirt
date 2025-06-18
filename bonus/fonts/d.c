/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbaj <akabbaj@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 16:59:22 by akabbaj           #+#    #+#             */
/*   Updated: 2025/06/18 16:59:22 by akabbaj          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */


#include "fonts.h"

void	init_d(int d[7][5])
{
	init_char(d);
	d[0][0] = 1;
	d[0][1] = 1;
	d[0][2] = 1;
	d[0][3] = 1;
	d[1][0] = 1;
	d[1][4] = 1;
	d[2][0] = 1;
	d[2][4] = 1;
	d[3][0] = 1;
	d[3][4] = 1;
	d[4][0] = 1;
	d[4][4] = 1;
	d[5][0] = 1;
	d[5][4] = 1;
	d[6][0] = 1;
	d[6][1] = 1;
	d[6][2] = 1;
	d[6][3] = 1;
	return ;
}

void	make_d(t_vars *vars, t_letter letter)
{
	int	x;
	int	y;
	int	step;
	int	d[7][5];

	init_d(d);
	step = letter.size / 7;
	y = 0;
	while (y < 7)
	{
		x = 0;
		while (x < 5)
		{
			if (d[y][x] == 1)
				draw_part(vars, letter.i + x * step, letter.j + y * step, step);
			x++;
		}
		y++;
	}
}
