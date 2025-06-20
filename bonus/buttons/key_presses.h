/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_presses.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbaj <akabbaj@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 22:02:35 by akabbaj           #+#    #+#             */
/*   Updated: 2025/06/20 22:34:15 by akabbaj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEY_PRESSES_H
# define KEY_PRESSES_H
# include "../structures.h"
# include "../minirt.h"
# include <sys/time.h>
# include "buttons.h"

void	wasd_handler(int button, t_vars *vars, int light_count);
void	mod_handler(int button, t_vars *vars, int light_count);
void	zaxis_handler(int button, t_vars *vars, int light_count);
void	hjkl_handler(t_vars *vars, int button);

#endif