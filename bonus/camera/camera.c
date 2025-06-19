/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbaj <akabbaj@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 14:33:28 by akabbaj           #+#    #+#             */
/*   Updated: 2025/06/19 14:33:49 by akabbaj          ###   ########.ch       */
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

double	get_intersection(t_coords ray, t_coords origin, t_shape *shape)
{
	if (shape->shape == CYLINDER)
		return (cyl_intersect(ray, origin, shape, 0));
	if (shape->shape == SPHERE)
		return (sphere_intersect(ray, origin, shape));
	if (shape->shape == PLANE)
		return (plane_intersect(ray, origin, shape));
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
		if (temp.t > 1e-6 && (result.t == -1 || temp.t < result.t))
			result = temp;
	}
	if (result.shape)
	{
		result.point = vect_add(origin, vect_mult(ray, result.t));
		result.normal = calc_norm(result, ray);
		result.ray = ray;
	}
	return (result);
}

int	get_colour(t_dataimg *img, int x, int y)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	return (*(unsigned int *)dst);
}

void	copy_image(t_vars *vars)
{
	int	x;
	int	y;
	int	colour;

	vars->img_copy.img = mlx_new_image(vars->mlx, vars->win_sizes.x_len,
			vars->win_sizes.y_height);
	if (!vars->img_copy.img)
		error_exit_vars(vars, "Error mlx img\n", 0);
	vars->img_copy.addr = mlx_get_data_addr(vars->img_copy.img,
			&(vars->img_copy.bits_per_pixel), &(vars->img_copy.line_length),
			&(vars->img_copy.endian));
	y = 0;
	while (y < vars->win_sizes.y_height)
	{
		x = 0;
		while (x < vars->win_sizes.x_len)
		{
			colour = get_colour(&(vars->img), x, y);
			my_mlx_pixel_put(&(vars->img_copy), x, y, colour);
			x++;
		}
		y++;
	}
}

void	camera(t_vars *vars, int i, int rgb)
{
	int				j;
	t_inter			shape;
	t_coords		vect;
	t_cam_screen	screen;

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
					rgb = get_rgb(shape, vars->gen, vars, 0);
				my_mlx_pixel_put(&(vars->img), i, j, rgb);
			}
			j++;
		}
		i++;
	}
	copy_image(vars);
	make_menu(vars, 0, 0);
	vars->mode = HIDDEN;
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img_copy.img, 0, 0);
}
