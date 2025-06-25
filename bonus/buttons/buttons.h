/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buttons.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbaj <akabbaj@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 15:20:50 by akabbaj           #+#    #+#             */
/*   Updated: 2025/06/24 14:51:44 by akabbaj          ###   ########.fr       */
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
int		render_next_frame(t_vars *vars);
void	clear_image(t_dataimg *img, int width, int height);
long	current_time(void);
int		count_lights(t_vars *vars);
char	*ft_strjoin(char const *s1, char const*s2);
int		get_shapenum(t_vars *vars, t_id shape, int caller);
int		count_objs(t_vars *vars);
int		max_for_page(t_vars *vars, int buttons);
int		count_buttons(t_vars *vars, int button_start_y, int button_height);
t_type	click_in_button(t_vars *vars, int x, int y);
void	menu_click(t_vars *vars, t_dataimg img);
int		button_fit(t_vars *vars);
void	select_click(t_vars *vars, t_dataimg img);
void	right_arrow_click(t_vars *vars, t_dataimg img);
void	left_arrow_click(t_vars *vars, t_dataimg img);
Bool	check_select_mode(t_vars *vars);
void	make_arrows(t_vars *vars, int boxlength, int arrow, t_dataimg img);

#endif