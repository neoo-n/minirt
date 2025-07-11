/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvauthey <dvauthey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 16:27:30 by akabbaj           #+#    #+#             */
/*   Updated: 2025/07/08 10:21:54 by dvauthey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"

t_cam_screen	screen_calcul(t_vars *vars)
{
	t_cam_screen	screen;

	screen.len_x = tan(deg_to_rad(vars->gen->c->fov / 2.0)) * 2.0;
	screen.len_y = vars->win_sizes.y_height
		/ vars->win_sizes.x_len * screen.len_x;
	screen.len_pix_x = screen.len_x / vars->win_sizes.x_len;
	screen.len_pix_y = screen.len_y / vars->win_sizes.y_height;
	if (vars->gen->c->vector.x == 0.0 && vars->gen->c->vector.z == 0.0)
	{
		screen.vect_y = vect_normalised(vect_cross(vars->gen->c->vector,
					vect_x()));
		screen.vect_x = vect_normalised(vect_cross(screen.vect_y,
					vars->gen->c->vector));
	}
	else
	{
		screen.vect_x = vect_normalised(vect_cross(vect_y(),
					vars->gen->c->vector));
		screen.vect_y = vect_normalised(vect_cross(vars->gen->c->vector,
					screen.vect_x));
		screen.vect_y = vect_mult(screen.vect_y, -1);
	}
	screen.p_mid = vect_add(vars->gen->c->vector, vars->gen->c->coords);
	return (screen);
}

t_coords	camera_vect(t_vars *vars, int i, int j, t_cam_screen screen)
{
	t_coords	vect_ij;
	t_coords	p_ij;
	t_coords	temp;

	p_ij = vect_mult(screen.vect_x, (i * screen.len_pix_x)
			- (screen.len_x / 2));
	temp = vect_mult(screen.vect_y, (j * screen.len_pix_y)
			- (screen.len_y / 2));
	p_ij = vect_add(p_ij, temp);
	p_ij = vect_add(p_ij, screen.p_mid);
	vect_ij = vect_sub(p_ij, vars->gen->c->coords);
	vect_ij = vect_normalised(vect_ij);
	return (vect_ij);
}

double	get_intersection(t_coords ray, t_coords origin, t_shape *shape)
{
	if (shape->shape == CYLINDER)
		return (cyl_intersect(ray, origin, shape, 0));
	if (shape->shape == SPHERE)
		return (sphere_intersect(ray, origin, shape));
	if (shape->shape == PLANE)
		return (plane_intersect(ray, origin, shape));
	if (shape->shape == CONE)
		return (cone_intersect(ray, origin, shape, 0));
	return (-1);
}

t_inter	find_closest_shape(t_coords ray, t_coords origin, t_shape **shapes,
		t_shape *check_shape)
{
	int		i;
	t_inter	result;
	t_inter	temp;

	i = -1;
	result.shape = 0;
	result.t = -1;
	while (shapes[++i])
	{
		if (shapes[i] == check_shape)
			continue ;
		temp.shape = shapes[i];
		temp.t = get_intersection(ray, origin, temp.shape);
		if (temp.t >= 0 && (result.t == -1 || ((temp.t < result.t + 1e-6)
					&& temp.shape->shape == SPHERE)))
			result = temp;
		else if (temp.t >= 0 && (result.t == -1 || temp.t < result.t - 1e-6))
			result = temp;
	}
	if (result.shape)
		set_result_closestshape(&result, origin, ray);
	return (result);
}

void	camera(t_vars *vars, int i)
{
	t_data			tdata[8];
	pthread_t		threads[8];
	int				step;

	vars->state = RENDER;
	vars->screen = screen_calcul(vars);
	step = vars->win_sizes.x_len / 8;
	while (++i < 8)
	{
		if (!create_threads(i, step, vars, tdata))
			break ;
		pthread_create(&threads[i], NULL, camera_thread, &tdata[i]);
	}
	if (i != 8)
		total_failure(vars, i, tdata, threads);
	i = 0;
	while (i < 8)
		pthread_join(threads[i++], NULL);
	while (i > 0)
		thread_failure(tdata[--i].vars);
	copy_image(vars);
	make_menu(vars, 0, 0, vars->img_copy);
	vars->mode = HIDDEN;
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img_copy.img, 0, 0);
}
