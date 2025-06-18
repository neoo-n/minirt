/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   n.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbaj <akabbaj@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 16:59:52 by akabbaj           #+#    #+#             */
/*   Updated: 2025/06/18 16:59:52 by akabbaj          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "fonts.h"

void	init_n(int n[7][5])
{
	init_char(n);
	n[0][0] = 1;
	n[0][4] = 1;
	n[1][0] = 1;
	n[1][1] = 1;
	n[1][4] = 1;
	n[2][0] = 1;
	n[2][2] = 1;
	n[2][4] = 1;
	n[3][0] = 1;
	n[3][2] = 1;
	n[3][4] = 1;
	n[4][0] = 1;
	n[4][2] = 1;
	n[4][4] = 1;
	n[5][0] = 1;
	n[5][3] = 1;
	n[5][4] = 1;
	n[6][0] = 1;
	n[6][4] = 1;
	return ;
}

void	make_n(t_vars *vars, t_letter letter)
{
	int	x;
	int	y;
	int	step;
	int	n[7][5];

	init_n(n);
	step = letter.size / 7;
	y = 0;
	while (y < 7)
	{
		x = 0;
		while (x < 5)
		{
			if (n[y][x] == 1)
				draw_part(vars, letter.i + x * step, letter.j + y * step, step);
			x++;
		}
		y++;
	}
}
