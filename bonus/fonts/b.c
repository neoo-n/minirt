/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbaj <akabbaj@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 16:59:02 by akabbaj           #+#    #+#             */
/*   Updated: 2025/06/18 16:59:02 by akabbaj          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */


#include "fonts.h"

void	init_b(int b[7][5])
{
	init_char(b);
	b[0][0] = 1;
	b[0][1] = 1;
	b[0][2] = 1;
	b[0][3] = 1;
	b[1][0] = 1;
	b[1][4] = 1;
	b[2][0] = 1;
	b[2][4] = 1;
	b[3][0] = 1;
	b[3][1] = 1;
	b[3][2] = 1;
	b[3][3] = 1;
	b[3][4] = 1;
	b[4][0] = 1;
	b[4][4] = 1;
	b[5][0] = 1;
	b[5][4] = 1;
	b[6][0] = 1;
	b[6][1] = 1;
	b[6][2] = 1;
	b[6][3] = 1;
	return ;
}

void	make_b(t_vars *vars, t_letter letter)
{
	int	x;
	int	y;
	int	step;
	int	b[7][5];

	init_b(b);
	step = letter.size / 7;
	y = 0;
	while (y < 7)
	{
		x = 0;
		while (x < 5)
		{
			if (b[y][x] == 1)
				draw_part(vars, letter.i + x * step, letter.j + y * step, step);
			x++;
		}
		y++;
	}
}
