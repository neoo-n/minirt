/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonts.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbaj <akabbaj@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 16:51:41 by akabbaj           #+#    #+#             */
/*   Updated: 2025/06/18 16:51:41 by akabbaj          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FONTS_H
# define FONTS_H
# include "../structures.h"
# include "../minirt.h"
# include "../camera/camera.h"

void	init_char(int chr[7][5]);
void	draw_part(t_vars *vars, int i, int j, int step);
void	handle_let(t_vars *vars, t_letter letter);
void	make_a(t_vars *vars, t_letter letter);
void	make_b(t_vars *vars, t_letter letter);
void	make_c(t_vars *vars, t_letter letter);
void	make_d(t_vars *vars, t_letter letter);
void	make_e(t_vars *vars, t_letter letter);
void	make_f(t_vars *vars, t_letter letter);
void	make_g(t_vars *vars, t_letter letter);
void	make_h(t_vars *vars, t_letter letter);
void	make_i(t_vars *vars, t_letter letter);
void	make_j(t_vars *vars, t_letter letter);
void	make_k(t_vars *vars, t_letter letter);
void	make_l(t_vars *vars, t_letter letter);
void	make_m(t_vars *vars, t_letter letter);
void	make_n(t_vars *vars, t_letter letter);
void	make_o(t_vars *vars, t_letter letter);
void	make_p(t_vars *vars, t_letter letter);
void	make_q(t_vars *vars, t_letter letter);
void	make_r(t_vars *vars, t_letter letter);
void	make_s(t_vars *vars, t_letter letter);
void	make_t(t_vars *vars, t_letter letter);
void	make_u(t_vars *vars, t_letter letter);
void	make_v(t_vars *vars, t_letter letter);
void	make_w(t_vars *vars, t_letter letter);
void	make_x(t_vars *vars, t_letter letter);
void	make_y(t_vars *vars, t_letter letter);
void	make_z(t_vars *vars, t_letter letter);

#endif