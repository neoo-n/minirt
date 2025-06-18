/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbaj <akabbaj@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 16:52:57 by akabbaj           #+#    #+#             */
/*   Updated: 2025/06/18 16:52:57 by akabbaj          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "fonts.h"

void	init_r(int r[7][5])
{
	init_char(r);
	r[0][0] = 1;
	r[0][1] = 1;
	r[0][2] = 1;
	r[0][3] = 1;
	r[1][0] = 1;
	r[1][4] = 1;
	r[2][0] = 1;
	r[2][4] = 1;
	r[3][0] = 1;
	r[3][1] = 1;
	r[3][2] = 1;
	r[3][3] = 1;
	r[4][0] = 1;
	r[4][3] = 1;
	r[5][0] = 1;
	r[5][4] = 1;
	r[6][0] = 1;
	r[6][4] = 1;
	return ;
}

void	make_r(t_vars *vars, t_letter letter)
{
	int	x;
	int	y;
	int	step;
	int	r[7][5];

	init_r(r);
	step = letter.size / 7;
	y = 0;
	while (y < 7)
	{
		x = 0;
		while (x < 5)
		{
			if (r[y][x] == 1)
				draw_part(vars, letter.i + x * step, letter.j + y * step, step);
			x++;
		}
		y++;
	}
}
