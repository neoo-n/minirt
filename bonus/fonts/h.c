/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   h.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbaj <akabbaj@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 17:05:13 by akabbaj           #+#    #+#             */
/*   Updated: 2025/06/18 17:05:18 by akabbaj          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "fonts.h"

void	init_h(int h[7][5])
{
	init_char(h);
	h[0][0] = 1;
	h[0][4] = 1;
	h[1][0] = 1;
	h[1][4] = 1;
	h[2][0] = 1;
	h[2][4] = 1;
	h[3][0] = 1;
	h[3][1] = 1;
	h[3][2] = 1;
	h[3][3] = 1;
	h[3][4] = 1;
	h[4][0] = 1;
	h[4][4] = 1;
	h[5][0] = 1;
	h[5][4] = 1;
	h[6][0] = 1;
	h[6][4] = 1;
	return ;
}

void	make_h(t_vars *vars, t_letter letter)
{
	int	x;
	int	y;
	int	step;
	int	h[7][5];

	init_h(h);
	step = letter.size / 7;
	y = 0;
	while (y < 7)
	{
		x = 0;
		while (x < 5)
		{
			if (h[y][x] == 1)
				draw_part(vars, letter.i + x * step, letter.j + y * step, step);
			x++;
		}
		y++;
	}
}
