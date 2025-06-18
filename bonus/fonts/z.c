/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   z.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbaj <akabbaj@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 17:00:25 by akabbaj           #+#    #+#             */
/*   Updated: 2025/06/18 17:00:46 by akabbaj          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "fonts.h"

void	init_z(int z[7][5])
{
	init_char(z);
	z[0][0] = 1;
	z[0][1] = 1;
	z[0][2] = 1;
	z[0][3] = 1;
	z[0][4] = 1;
	z[1][4] = 1;
	z[2][3] = 1;
	z[3][2] = 1;
	z[4][1] = 1;
	z[5][0] = 1;
	z[6][0] = 1;
	z[6][1] = 1;
	z[6][2] = 1;
	z[6][3] = 1;
	z[6][4] = 1;
	return ;
}

void	make_z(t_vars *vars, t_letter letter)
{
	int	x;
	int	y;
	int	step;
	int	z[7][5];

	init_z(z);
	step = letter.size / 7;
	y = 0;
	while (y < 7)
	{
		x = 0;
		while (x < 5)
		{
			if (z[y][x] == 1)
				draw_part(vars, letter.i + x * step, letter.j + y * step, step);
			x++;
		}
		y++;
	}
}
