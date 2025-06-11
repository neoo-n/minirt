/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbaj <akabbaj@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 10:17:29 by akabbaj           #+#    #+#             */
/*   Updated: 2025/06/11 10:17:29 by akabbaj          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_H
# define CAMERA_H
# include "../structures.h"
# include "../minirt.h"

void		creating_window(t_gen *gen);
void		my_mlx_pixel_put(t_dataimg *img, int x, int y, int color);
void		camera(t_vars *vars);
int			get_rgb(t_shape *shape, t_gen *gen, t_coords ray, t_coords origin);
t_shape		*find_closest_shape(t_coords ray, t_coords origin, t_shape **shapes, t_shape *check_shape);

#endif