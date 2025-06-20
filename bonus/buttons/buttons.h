/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buttons.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbaj <akabbaj@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 10:07:47 by akabbaj           #+#    #+#             */
/*   Updated: 2025/06/20 10:07:47 by akabbaj          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUTTONS_H
# define BUTTONS_H
# include "../structures.h"
# include "../minirt.h"
# include <sys/time.h>

void	make_box(t_vars *vars, t_button button, int text_colour, t_dataimg img);
void	make_menu(t_vars *vars, int line_colour, int i, t_dataimg img);
void	make_obj_button(t_vars *vars, t_dataimg img);
void	display_all_objs(t_vars *vars, t_dataimg img);
int		mouse_click(int button, int x, int y, t_vars *vars);
int		key_press(int button, t_vars *vars);
int 	render_next_frame(t_vars *vars);
void	clear_image(t_dataimg *img, int width, int height);
long	current_time(void);

#endif