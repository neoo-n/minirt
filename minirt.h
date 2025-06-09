/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvauthey <dvauthey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 14:47:56 by akabbaj           #+#    #+#             */
/*   Updated: 2025/06/09 16:42:57 by dvauthey         ###   ########.fr       */
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

void		drawing(t_vars *vars);
void		creating_window(t_gen *gen);
void		my_mlx_pixel_put(t_dataimg *img, int x, int y, int color);
void		camera(t_vars *vars);
int			get_rgb(t_rgb rgb);

t_coords	vect_normalised(t_coords v);
t_coords	vect_cross(t_coords v1, t_coords v2);
t_coords	vect_y(void);

#endif