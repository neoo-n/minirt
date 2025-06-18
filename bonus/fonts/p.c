/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbaj <akabbaj@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 16:59:57 by akabbaj           #+#    #+#             */
/*   Updated: 2025/06/18 16:59:57 by akabbaj          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "fonts.h"

void	init_p(int p[7][5])
{
	init_char(p);
	p[0][0] = 1;
	p[0][1] = 1;
	p[0][2] = 1;
	p[0][3] = 1;
	p[0][4] = 1;
	p[1][0] = 1;
	p[1][4] = 1;
	p[2][0] = 1;
	p[2][4] = 1;
	p[3][0] = 1;
	p[3][1] = 1;
	p[3][2] = 1;
	p[3][3] = 1;
	p[3][4] = 1;
	p[4][0] = 1;
	p[5][0] = 1;
	p[6][0] = 1;
	return ;
}

void	make_p(t_vars *vars, t_letter letter)
{
	int	x;
	int	y;
	int	step;
	int	p[7][5];

	init_p(p);
	step = letter.size / 7;
	y = 0;
	while (y < 7)
	{
		x = 0;
		while (x < 5)
		{
			if (p[y][x] == 1)
				draw_part(vars, letter.i + x * step, letter.j + y * step, step);
			x++;
		}
		y++;
	}
}
