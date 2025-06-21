/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbaj <akabbaj@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 14:52:23 by akabbaj           #+#    #+#             */
/*   Updated: 2025/06/21 15:42:33 by akabbaj          ###   ########.fr       */
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

void	copy_pre_image(t_vars *vars)
{
	int	x;
	int	y;
	int	colour;

	y = 0;
	while (y < vars->win_sizes.y_height)
	{
		x = 0;
		while (x < vars->win_sizes.x_len)
		{
			colour = get_colour(&(vars->pre_img), x, y);
			my_mlx_pixel_put(&(vars->pre_img_copy), x, y, colour);
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

	vars->state = RENDER;
	while (i < vars->win_sizes.x_len)
	{
		j = 0;
		while (j < vars->win_sizes.y_height)
		{
			vect = camera_vect(vars, i, j, vars->screen);
			shape = find_closest_shape(vect, vars->gen->c->coords,
					vars->gen->shapes, 0);
			if (shape.shape)
			{
				rgb = get_rgb(shape, vars->gen, vars);
				my_mlx_pixel_put(&(vars->img), i, j, rgb);
			}
			j++;
		}
		i++;
	}
	copy_image(vars);
	make_menu(vars, 0, 0, vars->img_copy);
	vars->mode = HIDDEN;
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img_copy.img, 0, 0);
}

void	pre_camera(t_vars *vars, int i, int rgb)
{
	int				j;
	t_inter			shape;
	t_coords		vect;
	t_button		button;
	int				block;
	int				block2;
	int				pixels;

	pixels = 20;
	vars->state = PRERENDER;
	vars->screen = screen_calcul(vars);
	while (i < vars->win_sizes.x_len)
	{
		j = 0;
		while (j < vars->win_sizes.y_height)
		{
			vect = camera_vect(vars, i, j, vars->screen);
			shape = find_closest_shape(vect, vars->gen->c->coords,
					vars->gen->shapes, 0);
			if (shape.shape)
			{
				rgb = get_rgb(shape, vars->gen, vars);
				block = 0;
				while (block < pixels)
				{
					block2 = 0;
					while (block2 < pixels)
					{
						if (i + block2 < vars->win_sizes.x_len && j + block < vars->win_sizes.y_height)
							my_mlx_pixel_put(&(vars->pre_img), i + block2, j + block, rgb);
						block2++;
					}
					block++;
				}
			}
			j += pixels;
		}
		i += pixels;
	}
	button.colour = 0x9c9797;
	button.text = "press enter to render";
	button.type = TEXT;
	button.bx = (vars->win_sizes.x_len / 2) * 0.8;
	button.ex = (vars->win_sizes.x_len / 2) * 1.2;
	button.ey = vars->win_sizes.y_height;
	button.by = vars->win_sizes.y_height * 0.95;
	make_box(vars, button, 0, vars->pre_img);
	copy_pre_image(vars);
	make_menu(vars, 0, 0, vars->pre_img_copy);
	vars->mode = HIDDEN;
	mlx_put_image_to_window(vars->mlx, vars->win, vars->pre_img_copy.img, 0, 0);
}
