/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_presses.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbaj <akabbaj@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 10:19:06 by akabbaj           #+#    #+#             */
/*   Updated: 2025/06/27 10:19:06 by akabbaj          ###   ########.ch       */
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

#endif