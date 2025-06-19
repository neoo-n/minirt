/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonts.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbaj <akabbaj@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 09:42:01 by akabbaj           #+#    #+#             */
/*   Updated: 2025/06/19 09:42:01 by akabbaj          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FONTS_H
# define FONTS_H
# include "../structures.h"
# include "../minirt.h"
# include "../camera/camera.h"

void		init_char(int chr[7][5]);
void		draw_part(t_vars *vars, int i, int j, int step);
void		handle_let(int grid[7][5], char c);
void		make_char(t_vars *vars, t_letter letter);
t_character	*init_characters(void);

void		init_a(int grid[7][5]);
void		init_b(int grid[7][5]);
void		init_c(int grid[7][5]);
void		init_d(int grid[7][5]);
void		init_e(int grid[7][5]);
void		init_f(int grid[7][5]);
void		init_g(int grid[7][5]);
void		init_h(int grid[7][5]);
void		init_i(int grid[7][5]);
void		init_j(int grid[7][5]);
void		init_k(int grid[7][5]);
void		init_l(int grid[7][5]);
void		init_m(int grid[7][5]);
void		init_n(int grid[7][5]);
void		init_o(int grid[7][5]);
void		init_p(int grid[7][5]);
void		init_q(int grid[7][5]);
void		init_r(int grid[7][5]);
void		init_s(int grid[7][5]);
void		init_t(int grid[7][5]);
void		init_u(int grid[7][5]);
void		init_v(int grid[7][5]);
void		init_w(int grid[7][5]);
void		init_x(int grid[7][5]);
void		init_y(int grid[7][5]);
void		init_z(int grid[7][5]);

void		init_0(int grid[7][5]);
void		init_1(int grid[7][5]);
void		init_2(int grid[7][5]);
void		init_3(int grid[7][5]);
void		init_4(int grid[7][5]);
void		init_5(int grid[7][5]);
void		init_6(int grid[7][5]);
void		init_7(int grid[7][5]);
void		init_8(int grid[7][5]);
void		init_9(int grid[7][5]);

void		init_l_arrow(int larrow[7][5]);
void		init_r_arrow(int rarrow[7][5]);

#endif