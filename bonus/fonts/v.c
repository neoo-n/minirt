/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbaj <akabbaj@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 16:56:20 by akabbaj           #+#    #+#             */
/*   Updated: 2025/06/18 16:56:20 by akabbaj          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "fonts.h"

void	init_v(int v[7][5])
{
	init_char(v);
	v[0][0] = 1;
	v[0][4] = 1;
	v[1][0] = 1;
	v[1][4] = 1;
	v[2][0] = 1;
	v[2][4] = 1;
	v[3][0] = 1;
	v[3][4] = 1;
	v[4][1] = 1;
	v[4][3] = 1;
	v[5][1] = 1;
	v[5][3] = 1;
	v[6][2] = 1;
	return ;
}

void	make_v(t_vars *vars, t_letter letter)
{
	int	x;
	int	y;
	int	step;
	int	v[7][5];

	init_v(v);
	step = letter.size / 7;
	y = 0;
	while (y < 7)
	{
		x = 0;
		while (x < 5)
		{
			if (v[y][x] == 1)
				draw_part(vars, letter.i + x * step, letter.j + y * step, step);
			x++;
		}
		y++;
	}
}
