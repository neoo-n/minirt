/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   w.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbaj <akabbaj@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 17:00:14 by akabbaj           #+#    #+#             */
/*   Updated: 2025/06/18 17:00:14 by akabbaj          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "fonts.h"

void	init_w(int w[7][5])
{
	init_char(w);
	w[0][0] = 1;
	w[0][2] = 1;
	w[0][4] = 1;
	w[1][0] = 1;
	w[1][2] = 1;
	w[1][4] = 1;
	w[2][0] = 1;
	w[2][2] = 1;
	w[2][4] = 1;
	w[3][0] = 1;
	w[3][2] = 1;
	w[3][4] = 1;
	w[4][0] = 1;
	w[4][2] = 1;
	w[4][4] = 1;
	w[5][0] = 1;
	w[5][2] = 1;
	w[5][4] = 1;
	w[6][0] = 1;
	w[6][1] = 1;
	w[6][2] = 1;
	w[6][3] = 1;
	w[6][4] = 1;
	return ;
}

void	make_w(t_vars *vars, t_letter letter)
{
	int	x;
	int	y;
	int	step;
	int	w[7][5];

	init_w(w);
	step = letter.size / 7;
	y = 0;
	while (y < 7)
	{
		x = 0;
		while (x < 5)
		{
			if (w[y][x] == 1)
				draw_part(vars, letter.i + x * step, letter.j + y * step, step);
			x++;
		}
		y++;
	}
}
