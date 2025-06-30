/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvauthey <dvauthey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 15:08:42 by akabbaj           #+#    #+#             */
/*   Updated: 2025/06/30 16:57:32 by dvauthey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_H
# define CAMERA_H
# include "../structures.h"
# include "../minirt.h"

void		creating_window(t_gen *gen);
void		my_mlx_pixel_put(t_dataimg *img, int x, int y, int color);
void		camera(t_vars *vars, int i, int rgb);
int			get_rgb(t_inter shape, t_gen *gen, t_vars *vars);
t_inter		find_closest_shape(t_coords ray, t_coords origin, t_shape **shapes,
				t_shape *check_shape);

t_coords	calc_norm(t_inter shape, t_coords ray);

t_rgb		init_rgb(void);
t_rgb		rgb_sum(t_rgb l1, t_rgb l2);
t_rgb		norm_rgb(t_rgb rgb);
t_rgb		rgb_mult(t_rgb rgb, double mult);
t_rgb		rgb_final(t_rgb rgb, t_rgb amb, t_rgb dif, t_rgb spec);

#endif