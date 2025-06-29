/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbaj <akabbaj@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 15:17:28 by akabbaj           #+#    #+#             */
/*   Updated: 2025/06/29 15:53:48 by akabbaj          ###   ########.ch       */
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
		if (temp.t > 1e-8 && (result.t == -1 || temp.t < result.t))
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

// void	*camera_thread(void *data)
// {
// 	t_data		*info;
// 	int			j;
// 	int			i;
// 	t_coords	vect;
// 	int			rgb;
// 	t_inter		shape;

// 	info = data;
// 	i = info->sx;
// 	while (i < info->ex)
// 	{
// 		j = 0;
// 		while (j < info->vars->win_sizes.y_height)
// 		{
// 			vect = camera_vect(info->vars, i, j, info->vars->screen);
// 			shape = find_closest_shape(vect, info->vars->gen->c->coords,
// 					info->vars->gen->shapes, 0);
// 			if (shape.shape)
// 			{
// 				rgb = get_rgb(shape, info->vars->gen, info->vars);
// 				my_mlx_pixel_put(&(info->vars->img), i, j, rgb);
// 			}
// 			j++;
// 		}
// 		i++;
// 	}
// 	return (0);
// }

// void	camera(t_vars *vars, int i, int rgb)
// {
// 	t_data			tdata[8];
// 	pthread_t		threads[8];
// 	int				step;

// 	(void) rgb;
// 	vars->state = RENDER;
// 	vars->screen = screen_calcul(vars);
// 	step = vars->win_sizes.x_len / 8;
// 	while (i < 8)
// 	{
// 		tdata[i].vars = vars;
// 		tdata[i].sx = i * step;
// 		if (i == 7)
// 			tdata[i].ex = vars->win_sizes.x_len;
// 		else
// 			tdata[i].ex = (i + 1) * step;
// 		pthread_create(&threads[i], NULL, camera_thread, &tdata[i]);
// 		i++;
// 	}
// 	i = 0;
// 	while (i < 8)
// 		pthread_join(threads[i++], NULL);
// 	copy_image(vars);
// 	make_menu(vars, 0, 0, vars->img_copy);
// 	vars->mode = HIDDEN;
// 	mlx_put_image_to_window(vars->mlx, vars->win, vars->img_copy.img, 0, 0);
// }

void	camera(t_vars *vars, int i, int rgb)
{
	int				j;
	t_inter			shape;
	t_coords		vect;

	vars->state = RENDER;
	vars->screen = screen_calcul(vars);
	while (++i < vars->win_sizes.x_len)
	{
		j = -1;
		while (++j < vars->win_sizes.y_height)
		{
			vect = camera_vect(vars, i, j, vars->screen);
			shape = find_closest_shape(vect, vars->gen->c->coords,
					vars->gen->shapes, 0);
			if (shape.shape)
			{
				rgb = get_rgb(shape, vars->gen, vars);
				my_mlx_pixel_put(&(vars->img), i, j, rgb);
			}
		}
	}
	copy_image(vars);
	make_menu(vars, 0, 0, vars->img_copy);
	vars->mode = HIDDEN;
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img_copy.img, 0, 0);
}

void	info_box(t_vars *vars)
{
	t_button	button;

	button.colour = 0x9c9797;
	if (vars->mode == RED)
		button.text = "press r or menu to exit rgb mode";
	else if (vars->mode == GREEN)
		button.text = "press g or menu to exit rgb mode";
	else if (vars->mode == BLUE)
		button.text = "press b or menu to exit rgb mode";
	else
		button.text = "press enter to render";
	button.type = TEXT;
	button.bx = (vars->win_sizes.x_len / 2) * 0.8;
	button.ex = (vars->win_sizes.x_len / 2) * 1.2;
	button.ey = vars->win_sizes.y_height;
	button.by = vars->win_sizes.y_height * 0.95;
	make_box(vars, button, 0, vars->pre_img);
	copy_pre_image(vars);
	make_menu(vars, 0, 0, vars->pre_img_copy);
	if (vars->mode != RED && vars->mode != GREEN && vars->mode != BLUE)
		vars->mode = HIDDEN;
}

void	draw_pixel_block(t_vars *vars, t_inter shape, int i, int j)
{
	int	block;
	int	block2;
	int	rgb;

	rgb = get_rgb(shape, vars->gen, vars);
	block = 0;
	while (block < PIXELS)
	{
		block2 = 0;
		while (block2 < PIXELS)
		{
			if (i + block2 < vars->win_sizes.x_len && j + block
				< vars->win_sizes.y_height)
				my_mlx_pixel_put(&(vars->pre_img), i + block2, j + block, rgb);
			block2++;
		}
		block++;
	}
}

void	pre_camera(t_vars *vars, int i)
{
	int				j;
	t_inter			shape;
	t_coords		vect;

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
				draw_pixel_block(vars, shape, i, j);
			j += PIXELS;
		}
		i += PIXELS;
	}
	info_box(vars);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->pre_img_copy.img, 0, 0);
}
