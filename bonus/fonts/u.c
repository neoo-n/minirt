/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbaj <akabbaj@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 17:00:09 by akabbaj           #+#    #+#             */
/*   Updated: 2025/06/18 17:00:09 by akabbaj          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "fonts.h"

void	init_u(int u[7][5])
{
	init_char(u);
	u[0][0] = 1;
	u[0][4] = 1;
	u[1][0] = 1;
	u[1][4] = 1;
	u[2][0] = 1;
	u[2][4] = 1;
	u[3][0] = 1;
	u[3][4] = 1;
	u[4][0] = 1;
	u[4][4] = 1;
	u[5][0] = 1;
	u[5][4] = 1;
	u[6][0] = 1;
	u[6][1] = 1;
	u[6][2] = 1;
	u[6][3] = 1;
	u[6][4] = 1;
	return ;
}

void	make_u(t_vars *vars, t_letter letter)
{
	int	x;
	int	y;
	int	step;
	int	u[7][5];

	init_u(u);
	step = letter.size / 7;
	y = 0;
	while (y < 7)
	{
		x = 0;
		while (x < 5)
		{
			if (u[y][x] == 1)
				draw_part(vars, letter.i + x * step, letter.j + y * step, step);
			x++;
		}
		y++;
	}
}
