/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   j.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbaj <akabbaj@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 16:55:44 by akabbaj           #+#    #+#             */
/*   Updated: 2025/06/18 16:55:44 by akabbaj          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "fonts.h"

void	init_j(int j[7][5])
{
	init_char(j);
	j[0][0] = 1;
	j[0][1] = 1;
	j[0][2] = 1;
	j[0][3] = 1;
	j[0][4] = 1;
	j[1][3] = 1;
	j[2][3] = 1;
	j[3][3] = 1;
	j[4][3] = 1;
	j[5][3] = 1;
	j[6][0] = 1;
	j[6][1] = 1;
	j[6][2] = 1;
	j[6][3] = 1;
	return ;
}

void	make_j(t_vars *vars, t_letter letter)
{
	int	x;
	int	y;
	int	step;
	int	jl[7][5];

	init_j(jl);
	step = letter.size / 7;
	y = 0;
	while (y < 7)
	{
		x = 0;
		while (x < 5)
		{
			if (jl[y][x] == 1)
				draw_part(vars, letter.i + x * step, letter.j + y * step, step);
			x++;
		}
		y++;
	}
}
