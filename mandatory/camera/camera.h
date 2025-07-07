/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbaj <akabbaj@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 16:17:45 by akabbaj           #+#    #+#             */
/*   Updated: 2025/07/07 16:17:49 by akabbaj          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_H
# define CAMERA_H
# include "../structures.h"
# include "../minirt.h"
# include "../vector/vector.h"

void		creating_window(t_gen *gen);
void		my_mlx_pixel_put(t_dataimg *img, int x, int y, int color);
void		camera(t_vars *vars, int i, int rgb);
int			get_rgb(t_inter shape, t_gen *gen, double angle);
t_inter		find_closest_shape(t_coords ray, t_coords origin, t_shape **shapes,
				t_shape *check_shape);
t_coords	calc_norm(t_inter shape, t_coords ray);
t_rgb		norm_rgb(t_rgb rgb);
t_coords	cyl_n(t_inter shape);
t_rgb		rgb_mult(t_rgb rgb, double mult);
t_rgb		rgb_final(t_rgb rgb, t_rgb amb, t_rgb dif);

#endif