/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbaj <akabbaj@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 16:55:55 by akabbaj           #+#    #+#             */
/*   Updated: 2025/06/18 16:55:55 by akabbaj          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "fonts.h"

void	init_m(int m[7][5])
{
	init_char(m);
	m[0][0] = 1;
	m[0][1] = 1;
	m[0][2] = 1;
	m[0][3] = 1;
	m[0][4] = 1;
	m[1][0] = 1;
	m[1][2] = 1;
	m[1][4] = 1;
	m[2][0] = 1;
	m[2][2] = 1;
	m[2][4] = 1;
	m[3][0] = 1;
	m[3][2] = 1;
	m[3][4] = 1;
	m[4][0] = 1;
	m[4][2] = 1;
	m[4][4] = 1;
	m[5][0] = 1;
	m[5][2] = 1;
	m[5][4] = 1;
	m[6][0] = 1;
	m[6][2] = 1;
	m[6][4] = 1;
	return ;
}

void	make_m(t_vars *vars, t_letter letter)
{
	int	x;
	int	y;
	int	step;
	int	m[7][5];

	init_m(m);
	step = letter.size / 7;
	y = 0;
	while (y < 7)
	{
		x = 0;
		while (x < 5)
		{
			if (m[y][x] == 1)
				draw_part(vars, letter.i + x * step, letter.j + y * step, step);
			x++;
		}
		y++;
	}
}
