/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbaj <akabbaj@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 16:58:51 by akabbaj           #+#    #+#             */
/*   Updated: 2025/06/18 16:58:51 by akabbaj          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "fonts.h"

void	init_a(int a[7][5])
{
	init_char(a);
	a[0][0] = 1;
	a[0][1] = 1;
	a[0][2] = 1;
	a[0][3] = 1;
	a[0][4] = 1;
	a[1][0] = 1;
	a[1][4] = 1;
	a[2][0] = 1;
	a[2][4] = 1;
	a[3][0] = 1;
	a[3][1] = 1;
	a[3][2] = 1;
	a[3][3] = 1;
	a[3][4] = 1;
	a[4][0] = 1;
	a[4][4] = 1;
	a[5][0] = 1;
	a[5][4] = 1;
	a[6][0] = 1;
	a[6][4] = 1;
	return ;
}

void	make_a(t_vars *vars, t_letter letter)
{
	int	x;
	int	y;
	int	step;
	int	a[7][5];

	init_a(a);
	step = letter.size / 7;
	y = 0;
	while (y < 7)
	{
		x = 0;
		while (x < 5)
		{
			if (a[y][x] == 1)
				draw_part(vars, letter.i + x * step, letter.j + y * step, step);
			x++;
		}
		y++;
	}
}
