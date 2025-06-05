/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbaj <akabbaj@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 10:42:54 by akabbaj           #+#    #+#             */
/*   Updated: 2025/06/03 10:44:09 by akabbaj          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H
# include "parsing/parsing.h"
# include "utils/utils.h"
# include "minilibx-linux/mlx.h"
# include "minilibx-linux/mlx_int.h"
# include <math.h>

void	drawing(t_vars *vars);
void	creating_window(void);
void	my_mlx_pixel_put(t_dataimg *img, int x, int y, int color);

#endif