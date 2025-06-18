/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   q.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbaj <akabbaj@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 16:56:07 by akabbaj           #+#    #+#             */
/*   Updated: 2025/06/18 16:56:07 by akabbaj          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "fonts.h"

void	init_q(int q[7][5])
{
	init_char(q);
	q[0][0] = 1;
	q[0][1] = 1;
	q[0][2] = 1;
	q[0][3] = 1;
	q[0][4] = 1;
	q[1][0] = 1;
	q[1][4] = 1;
	q[2][0] = 1;
	q[2][4] = 1;
	q[3][0] = 1;
	q[3][4] = 1;
	q[4][0] = 1;
	q[4][4] = 1;
	q[5][0] = 1;
	q[5][1] = 1;
	q[5][2] = 1;
	q[5][3] = 1;
	q[5][4] = 1;
	q[6][3] = 1;
	return ;
}

void	make_q(t_vars *vars, t_letter letter)
{
	int	x;
	int	y;
	int	step;
	int	q[7][5];

	init_q(q);
	step = letter.size / 7;
	y = 0;
	while (y < 7)
	{
		x = 0;
		while (x < 5)
		{
			if (q[y][x] == 1)
				draw_part(vars, letter.i + x * step, letter.j + y * step, step);
			x++;
		}
		y++;
	}
}
