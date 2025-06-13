/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbaj <akabbaj@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 11:49:22 by akabbaj           #+#    #+#             */
/*   Updated: 2025/06/13 11:53:42 by akabbaj          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"

static t_cam_screen	screen_calcul(t_vars *vars)
{
	t_cam_screen	screen;

	screen.len_x = tan(deg_to_rad(vars->gen->c->fov / 2.0)) * 2.0;
	screen.len_y = vars->win_sizes.y_height
		/ vars->win_sizes.x_len * screen.len_x;
	screen.len_pix_x = screen.len_x / vars->win_sizes.x_len;
	screen.len_pix_y = screen.len_y / vars->win_sizes.y_height;
	screen.vect_x = vect_normalised(vect_cross(vect_y(), vars->gen->c->vector));
	screen.vect_y = vect_normalised(vect_cross(vars->gen->c->vector,
				screen.vect_x));
	screen.vect_y = vect_mult(screen.vect_y, -1);
	screen.p_mid = vect_add(vars->gen->c->vector, vars->gen->c->coords);
	return (screen);
}

static t_coords	camera_vect(t_vars *vars, int i, int j, t_cam_screen screen)
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

t_inter	find_closest_shape(t_coords ray, t_coords origin, t_shape **shapes, t_shape *check_shape)
{
	int		i;
	t_inter	result;
	t_inter	temp;

	i = 0;
	result.shape = 0;
	result.t = -1;
	while (shapes[i])
	{
		if (shapes[i] == check_shape)
		{
			i++;
			continue ;
		}
		temp.shape = shapes[i];
		if (shapes[i]->shape == CYLINDER)
			temp.t = cyl_intersect(ray, origin, shapes[i], 0);
		if (shapes[i]->shape == SPHERE)
			temp.t = sphere_intersect(ray, origin, shapes[i]);
		if (shapes[i]->shape == PLANE)
			temp.t = plane_intersect(ray, origin, shapes[i]);
		if (temp.t > 0 && (result.t == -1 || temp.t < result.t))
			result = temp;
		i++;
	}
	if (result.shape)
	{
		result.point = vect_add(origin, vect_mult(ray, result.t));
		result.normal = calc_norm(result, ray);
	}
	return (result);
}

void	camera(t_vars *vars)
{
	int				i;
	int				j;
	t_inter			shape;
	t_coords		vect;
	t_cam_screen	screen;
	int				rgb;

	i = 0;
	screen = screen_calcul(vars);
	while (i < vars->win_sizes.x_len)
	{
		j = 0;
		while (j < vars->win_sizes.y_height)
		{
			vect = camera_vect(vars, i, j, screen);
			shape = find_closest_shape(vect, vars->gen->c->coords,
					vars->gen->shapes, 0);
			if (shape.shape)
			{
				if (j % 1 == 0 && i % 1 == 0)
					rgb = get_rgb(shape, vars->gen, vars);
				my_mlx_pixel_put(&(vars->img), i, j, rgb);
			}
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, 0, 0);
}
