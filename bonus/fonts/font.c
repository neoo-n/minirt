/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   font.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbaj <akabbaj@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 17:06:35 by akabbaj           #+#    #+#             */
/*   Updated: 2025/06/18 17:06:35 by akabbaj          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "fonts.h"

void	init_char(int chr[7][5])
{
	int	i;
	int	j;

	i = 0;
	while (i < 5)
	{
		j = 0;
		while (j < 7)
		{
			chr[j][i] = 0;
			j++;
		}
		i++;
	}
	return ;
}

void	draw_part(t_vars *vars, int i, int j, int step)
{
	int	x;
	int	y;

	y = j;
	while (y < j + step)
	{
		x = i;
		while (x < i + step)
		{
			my_mlx_pixel_put(&(vars->img), x, y, vars->colour);
			x++;
		}
		y++;
	}
}

void	handle_let_plus_plus(t_vars *vars, t_letter letter)
{
	if (letter.letter == 'w')
		make_w(vars, letter);
	else if (letter.letter == 'x')
		make_x(vars, letter);
	else if (letter.letter == 'y')
		make_y(vars, letter);
	else if (letter.letter == 'z')
		make_z(vars, letter);
}

void	handle_let_plus(t_vars *vars, t_letter letter)
{
	if (letter.letter == 'l')
		make_l(vars, letter);
	else if (letter.letter == 'm')
		make_m(vars, letter);
	else if (letter.letter == 'n')
		make_n(vars, letter);
	else if (letter.letter == 'o')
		make_o(vars, letter);
	else if (letter.letter == 'p')
		make_p(vars, letter);
	else if (letter.letter == 'q')
		make_q(vars, letter);
	else if (letter.letter == 'r')
		make_r(vars, letter);
	else if (letter.letter == 's')
		make_s(vars, letter);
	else if (letter.letter == 't')
		make_t(vars, letter);
	else if (letter.letter == 'u')
		make_u(vars, letter);
	else if (letter.letter == 'v')
		make_v(vars, letter);
	else
		handle_let_plus_plus(vars, letter);
}

void	handle_let(t_vars *vars, t_letter letter)
{
	vars->colour = letter.colour;
	if (letter.letter == 'a')
		make_a(vars, letter);
	else if (letter.letter == 'b')
		make_b(vars, letter);
	else if (letter.letter == 'c')
		make_c(vars, letter);
	else if (letter.letter == 'd')
		make_d(vars, letter);
	else if (letter.letter == 'e')
		make_e(vars, letter);
	else if (letter.letter == 'f')
		make_f(vars, letter);
	else if (letter.letter == 'g')
		make_g(vars, letter);
	else if (letter.letter == 'h')
		make_h(vars, letter);
	else if (letter.letter == 'i')
		make_i(vars, letter);
	else if (letter.letter == 'j')
		make_j(vars, letter);
	else if (letter.letter == 'k')
		make_k(vars, letter);
	else
		handle_let_plus(vars, letter);
}
