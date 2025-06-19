/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_letters.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbaj <akabbaj@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 09:42:26 by akabbaj           #+#    #+#             */
/*   Updated: 2025/06/19 09:42:26 by akabbaj          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "fonts.h"

void	handle_let_plus_plus_plus(int grid[7][5], char c)
{
	if (c == '7')
		init_7(grid);
	else if (c == '8')
		init_8(grid);
	else if (c == '9')
		init_9(grid);
	else if (c == '<')
		init_l_arrow(grid);
	else if (c == '>')
		init_r_arrow(grid);
}

void	handle_let_plus_plus(int grid[7][5], char c)
{
	if (c == 'w')
		init_w(grid);
	else if (c == 'x')
		init_x(grid);
	else if (c == 'y')
		init_y(grid);
	else if (c == 'z')
		init_z(grid);
	else if (c == '0')
		init_0(grid);
	else if (c == '1')
		init_1(grid);
	else if (c == '2')
		init_2(grid);
	else if (c == '3')
		init_3(grid);
	else if (c == '4')
		init_4(grid);
	else if (c == '5')
		init_5(grid);
	else if (c == '6')
		init_6(grid);
	else
		handle_let_plus_plus_plus(grid, c);
}

void	handle_let_plus(int grid[7][5], char c)
{
	if (c == 'l')
		init_l(grid);
	else if (c == 'm')
		init_m(grid);
	else if (c == 'n')
		init_n(grid);
	else if (c == 'o')
		init_o(grid);
	else if (c == 'p')
		init_p(grid);
	else if (c == 'q')
		init_q(grid);
	else if (c == 'r')
		init_r(grid);
	else if (c == 's')
		init_s(grid);
	else if (c == 't')
		init_t(grid);
	else if (c == 'u')
		init_u(grid);
	else if (c == 'v')
		init_v(grid);
	else
		handle_let_plus_plus(grid, c);
}

void	handle_let(int grid[7][5], char c)
{
	if (c == 'a')
		init_a(grid);
	else if (c == 'b')
		init_b(grid);
	else if (c == 'c')
		init_c(grid);
	else if (c == 'd')
		init_d(grid);
	else if (c == 'e')
		init_e(grid);
	else if (c == 'f')
		init_f(grid);
	else if (c == 'g')
		init_g(grid);
	else if (c == 'h')
		init_h(grid);
	else if (c == 'i')
		init_i(grid);
	else if (c == 'j')
		init_j(grid);
	else if (c == 'k')
		init_k(grid);
	else
		handle_let_plus(grid, c);
}
