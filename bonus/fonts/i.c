/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   i.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbaj <akabbaj@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 16:59:40 by akabbaj           #+#    #+#             */
/*   Updated: 2025/06/18 16:59:40 by akabbaj          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "fonts.h"

void	init_i(int i[7][5])
{
	init_char(i);
	i[0][0] = 1;
	i[0][1] = 1;
	i[0][2] = 1;
	i[0][3] = 1;
	i[0][4] = 1;
	i[1][2] = 1;
	i[2][2] = 1;
	i[3][2] = 1;
	i[4][2] = 1;
	i[5][2] = 1;
	i[6][0] = 1;
	i[6][1] = 1;
	i[6][2] = 1;
	i[6][3] = 1;
	i[6][4] = 1;
	return ;
}

void	make_i(t_vars *vars, t_letter letter)
{
	int	x;
	int	y;
	int	step;
	int	il[7][5];

	init_i(il);
	step = letter.size / 7;
	y = 0;
	while (y < 7)
	{
		x = 0;
		while (x < 5)
		{
			if (il[y][x] == 1)
				draw_part(vars, letter.i + x * step, letter.j + y * step, step);
			x++;
		}
		y++;
	}
}
