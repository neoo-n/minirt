/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   k.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbaj <akabbaj@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 15:56:32 by akabbaj           #+#    #+#             */
/*   Updated: 2025/06/18 15:56:32 by akabbaj          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "fonts.h"

void	init_k(int k[7][5])
{
	init_char(k);
	k[0][0] = 1;
	k[0][4] = 1;
	k[1][0] = 1;
	k[1][3] = 1;
	k[2][0] = 1;
	k[2][2] = 1;
	k[3][0] = 1;
	k[3][1] = 1;
	k[4][0] = 1;
	k[4][2] = 1;
	k[5][0] = 1;
	k[5][3] = 1;
	k[6][0] = 1;
	k[6][4] = 1;
	return ;
}

void	make_k(t_vars *vars, t_letter letter)
{
	int	x;
	int	y;
	int	step;
	int	k[7][5];

	init_k(k);
	step = letter.size / 7;
	y = 0;
	while (y < 7)
	{
		x = 0;
		while (x < 5)
		{
			if (k[y][x] == 1)
				draw_part(vars, letter.i + x * step, letter.j + y * step, step);
			x++;
		}
		y++;
	}
}
