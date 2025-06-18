/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   o.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbaj <akabbaj@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 16:56:01 by akabbaj           #+#    #+#             */
/*   Updated: 2025/06/18 16:56:01 by akabbaj          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "fonts.h"

void	init_o(int o[7][5])
{
	init_char(o);
	o[0][0] = 1;
	o[0][1] = 1;
	o[0][2] = 1;
	o[0][3] = 1;
	o[0][4] = 1;
	o[1][0] = 1;
	o[1][4] = 1;
	o[2][0] = 1;
	o[2][4] = 1;
	o[3][0] = 1;
	o[3][4] = 1;
	o[4][0] = 1;
	o[4][4] = 1;
	o[5][0] = 1;
	o[5][4] = 1;
	o[6][0] = 1;
	o[6][1] = 1;
	o[6][2] = 1;
	o[6][3] = 1;
	o[6][4] = 1;
	return ;
}

void	make_o(t_vars *vars, t_letter letter)
{
	int	x;
	int	y;
	int	step;
	int	o[7][5];

	init_o(o);
	step = letter.size / 7;
	y = 0;
	while (y < 7)
	{
		x = 0;
		while (x < 5)
		{
			if (o[y][x] == 1)
				draw_part(vars, letter.i + x * step, letter.j + y * step, step);
			x++;
		}
		y++;
	}
}
