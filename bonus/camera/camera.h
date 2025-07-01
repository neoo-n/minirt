/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbaj <akabbaj@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 14:35:31 by akabbaj           #+#    #+#             */
/*   Updated: 2025/07/01 14:35:31 by akabbaj          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_H
# define CAMERA_H
# include "../structures.h"
# include "../minirt.h"
# include "../parsing/parsing.h"
# include "../features/features.h"

void			creating_window(t_gen *gen);
void			my_mlx_pixel_put(t_dataimg *img, int x, int y, int color);
void			camera(t_vars *vars, int i, int rgb);
void			pre_camera(t_vars *vars, int i);
int				get_rgb(t_inter shape, t_gen *gen, t_vars *vars);
t_inter			find_closest_shape(t_coords ray, t_coords origin,
					t_shape **shapes, t_shape *check_shape);

t_coords		cyl_n(t_inter shape);
t_coords		calc_norm(t_inter shape, t_coords ray);

t_rgb			init_rgb(void);
t_rgb			rgb_sum(t_rgb l1, t_rgb l2);
t_rgb			norm_rgb(t_rgb rgb);
t_coords		co_n(t_inter shape);
t_rgb			rgb_mult(t_rgb rgb, double mult);
t_rgb			rgb_final(t_rgb rgb, t_rgb amb, t_rgb dif, t_rgb spec);
void			copy_image(t_vars *vars);
void			copy_pre_image(t_vars *vars);
void			error_exit_vars(t_vars *vars, char *message, int is_perror);

t_cam_screen	screen_calcul(t_vars *vars);

#endif