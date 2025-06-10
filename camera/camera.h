/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbaj <akabbaj@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 13:57:35 by akabbaj           #+#    #+#             */
/*   Updated: 2025/06/10 13:57:35 by akabbaj          ###   ########.ch       */
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

#endif