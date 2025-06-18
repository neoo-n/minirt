/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbaj <akabbaj@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 17:00:04 by akabbaj           #+#    #+#             */
/*   Updated: 2025/06/18 17:00:04 by akabbaj          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "fonts.h"

void	init_s(int s[7][5])
{
	init_char(s);
	s[0][0] = 1;
	s[0][1] = 1;
	s[0][2] = 1;
	s[0][3] = 1;
	s[0][4] = 1;
	s[1][0] = 1;
	s[2][0] = 1;
	s[3][0] = 1;
	s[3][1] = 1;
	s[3][2] = 1;
	s[3][3] = 1;
	s[3][4] = 1;
	s[4][4] = 1;
	s[5][4] = 1;
	s[6][0] = 1;
	s[6][1] = 1;
	s[6][2] = 1;
	s[6][3] = 1;
	s[6][4] = 1;
	return ;
}

void	make_s(t_vars *vars, t_letter letter)
{
	int	x;
	int	y;
	int	step;
	int	s[7][5];

	init_s(s);
	step = letter.size / 7;
	y = 0;
	while (y < 7)
	{
		x = 0;
		while (x < 5)
		{
			if (s[y][x] == 1)
				draw_part(vars, letter.i + x * step, letter.j + y * step, step);
			x++;
		}
		y++;
	}
}
