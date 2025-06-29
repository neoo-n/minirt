/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_presses.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbaj <akabbaj@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 13:21:20 by akabbaj           #+#    #+#             */
/*   Updated: 2025/06/29 13:21:33 by akabbaj          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEY_PRESSES_H
# define KEY_PRESSES_H
# include "../structures.h"
# include "../minirt.h"
# include <sys/time.h>

void	wasd_handler(int button, t_vars *vars, int light_count);
void	mod_handler(int button, t_vars *vars, int light_count);
void	zaxis_handler(int button, t_vars *vars, int light_count);
void	hjkl_handler(t_vars *vars, int button);
void	arrow_handler(int button, t_vars *vars, int light_count);
int		key_press(int button, t_vars *vars);
int		render_next_frame(t_vars *vars);
long	current_time(void);
void	plus_rgb(t_vars *vars, int light_id, int shape_id);
void	minus_rgb(t_vars *vars, int light_id, int shape_id);
void	rgb_handler(int button, t_vars *vars);

#endif