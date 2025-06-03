/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvauthey <dvauthey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 16:05:06 by akabbaj           #+#    #+#             */
/*   Updated: 2025/06/03 10:42:36 by dvauthey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H
# include "parsing/parsing.h"
# include "utils/utils.h"
# include "minilibx-linux/mlx.h"
# include "minilibx-linux/mlx_int.h"
# include <math.h>
# include <stdio.h>

void	drawing(t_vars *vars);
void	creating_window();
void	my_mlx_pixel_put(t_dataimg *img, int x, int y, int color);
void	camera(t_vars *vars);

#endif