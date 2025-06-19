/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buttons.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbaj <akabbaj@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 10:58:05 by akabbaj           #+#    #+#             */
/*   Updated: 2025/06/19 10:58:05 by akabbaj          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUTTONS_H
# define BUTTONS_H
# include "../structures.h"
# include "../minirt.h"

void	make_box(t_vars *vars, t_button button, int text_colour);
void	make_menu(t_vars *vars, int line_colour, int i);
void	make_obj_button(t_vars *vars);
void	display_all_objs(t_vars *vars);
int		mouse_click(int button, int x, int y, t_vars *vars);

#endif