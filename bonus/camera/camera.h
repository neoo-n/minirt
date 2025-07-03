/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvauthey <dvauthey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 14:35:31 by akabbaj           #+#    #+#             */
/*   Updated: 2025/07/03 16:17:28 by dvauthey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_H
# define CAMERA_H
# include "../structures.h"
# include "../minirt.h"
# include "../parsing/parsing.h"
# include "../features/features.h"

int				mouse_closing(t_vars *vars);
int				closing(int keycode, t_vars *vars);

void			creating_window(t_gen *gen);

void			my_mlx_pixel_put(t_dataimg *img, int x, int y, int color);

t_coords		camera_vect(t_vars *vars, int i, int j, t_cam_screen screen);
int				get_rgb(t_inter shape, t_gen *gen, t_vars *vars);
t_inter			find_closest_shape(t_coords ray, t_coords origin,
					t_shape **shapes, t_shape *check_shape);
void			camera(t_vars *vars, int i, int rgb);

void			pre_camera(t_vars *vars, int i);

void			*camera_thread(void *data);
void			thread_failure(t_vars *vars);

t_vars			*deep_copy(t_vars	*vars);

t_coords		calc_norm(t_inter shape, t_coords ray);
t_coords		cyl_n(t_inter shape);
double			calc_fog(double t);
t_coords		co_n(t_inter shape);

t_rgb			init_rgb(void);
t_rgb			rgb_sum(t_rgb l1, t_rgb l2);
t_rgb			norm_rgb(t_rgb rgb);
t_rgb			rgb_mult(t_rgb rgb, double mult);
t_rgb			rgb_final(t_rgb rgb, t_rgb amb, t_rgb dif, t_rgb spec);

void			copy_image(t_vars *vars);
void			copy_pre_image(t_vars *vars);
void			error_exit_vars(t_vars *vars, char *message, int is_perror);

t_cam_screen	screen_calcul(t_vars *vars);

#endif