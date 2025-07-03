/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbaj <akabbaj@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 14:35:47 by akabbaj           #+#    #+#             */
/*   Updated: 2025/07/01 15:25:10 by akabbaj          ###   ########.ch       */
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

double	get_intersection(t_coords ray, t_coords origin, t_shape *shape,
	t_inter *temp)
{
	if (shape->shape == CYLINDER)
		return (cyl_intersect(ray, origin, shape, 0));
	if (shape->shape == SPHERE)
		return (sphere_intersect(ray, origin, shape));
	if (shape->shape == PLANE)
		return (plane_intersect(ray, origin, shape));
	if (shape->shape == CONE)
		return (cone_intersect(ray, origin, shape, 0));
	if (shape->shape == TORUS)
		return (torus_intersect(ray, origin, shape, temp));
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
		temp.t = get_intersection(ray, origin, temp.shape, &temp);
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

void	*camera_thread(void *data)
{
	t_data		*info;
	int			j;
	int			i;
	t_coords	vect;
	int			rgb;
	t_inter		shape;

	info = data;
	i = info->sx;
	while (i < info->ex)
	{
		j = 0;
		while (j < info->vars->win_sizes.y_height)
		{
			vect = camera_vect(info->vars, i, j, info->vars->screen);
			shape = find_closest_shape(vect, info->vars->gen->c->coords,
					info->vars->gen->shapes, 0);
			if (shape.shape)
			{
				rgb = get_rgb(shape, info->vars->gen, info->vars);
				my_mlx_pixel_put(&(info->vars->img), i, j, rgb);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	thread_init_img(t_vars *vars, t_dataimg *img)
{
	img->img = mlx_new_image(vars->mlx, vars->win_sizes.x_len,
			vars->win_sizes.y_height);
	if (!img->img)
		return (0);
	img->addr = mlx_get_data_addr(img->img,
			&(img->bits_per_pixel), &(img->line_length),
			&(img->endian));
	return (1);
}

void	thread_failure(t_vars *vars)
{
	if (vars->gen)
		free_gen(vars->gen);
	free(vars);
}

t_vars	*deep_copy(t_vars	*vars)
{
	t_vars	*copy;

	copy = malloc(sizeof(t_vars));
	if (!copy)
		return (0);
	copy->mlx = vars->mlx;
	copy->win = vars->win;
	copy->win_sizes = vars->win_sizes;
	copy->epsilon = vars->epsilon;
	copy->colour = vars->colour;
	copy->mode = vars->mode;
	copy->obj = vars->obj;
	copy->obj_id = vars->obj_id;
	copy->light_count = vars->light_count;
	copy->shape_count = vars->shape_count;
	copy->page_num = vars->page_num;
	copy->state = vars->state;
	copy->starttime = vars->starttime;
	copy->shadow = vars->shadow;
	copy->specular = vars->specular;
	copy->ambient = vars->ambient;
	copy->diffuse = vars->diffuse;
	copy->screen = vars->screen;
	copy->img = vars->img;
	copy->pre_img = vars->pre_img;
	copy->gen = copy_gen(vars->gen);
	if (!copy->gen)
	{
		thread_failure(copy);
		return (0);
	}
	copy->gen->character = 0;
	copy->gen->saved_gen = copy_gen(copy->gen);
	if (!copy->gen->saved_gen)
	{
		thread_failure(copy);
		return (0);
	}
	return (copy);
}

// void	merge_image(t_dataimg *dst, t_dataimg *src, int sx, int ex, int height)
// {
// 	int	x;
// 	int	y;
// 	int	colour;

// 	x = sx;
// 	while (x < ex)
// 	{
// 		y = 0;
// 		while (y < height)
// 		{
// 			colour = get_colour(src, x, y);
// 			my_mlx_pixel_put(dst, x, y, colour);
// 			y++;
// 		}
// 		x++;
// 	}
// }

void	camera(t_vars *vars, int i, int rgb)
{
	t_data			tdata[8];
	pthread_t		threads[8];
	int				step;
	int				j;

	(void) rgb;
	vars->state = RENDER;
	vars->screen = screen_calcul(vars);
	step = vars->win_sizes.x_len / 8;
	while (++i < 8)
	{
		tdata[i].vars = deep_copy(vars);
		if (!tdata[i].vars)
			break ;
		tdata[i].sx = i * step;
		if (i == 7)
			tdata[i].ex = vars->win_sizes.x_len;
		else
			tdata[i].ex = (i + 1) * step;
		pthread_create(&threads[i], NULL, camera_thread, &tdata[i]);
	}
	if (i != 8)
	{
		j = 0;
		while (j < i)
		{
			thread_failure(tdata[j].vars);
			pthread_join(threads[j], NULL);
			j++;
		}
		error_exit_vars(vars, "fucking hell", 0);
	}
	i = 0;
	while (i < 8)
		pthread_join(threads[i++], NULL);
	i = 0;
	while (i < 8)
	{
		thread_failure(tdata[i].vars);
		i++;
	}
	copy_image(vars);
	make_menu(vars, 0, 0, vars->img_copy);
	vars->mode = HIDDEN;
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img_copy.img, 0, 0);
}

// void	camera(t_vars *vars, int i, int rgb)
// {
// 	int				j;
// 	t_inter			shape;
// 	t_coords		vect;

// 	vars->state = RENDER;
// 	vars->screen = screen_calcul(vars);
// 	while (++i < vars->win_sizes.x_len)
// 	{
// 		j = -1;
// 		while (++j < vars->win_sizes.y_height)
// 		{
// 			vect = camera_vect(vars, i, j, vars->screen);
// 			shape = find_closest_shape(vect, vars->gen->c->coords,
// 					vars->gen->shapes, 0);
// 			if (shape.shape)
// 			{
// 				rgb = get_rgb(shape, vars->gen, vars);
// 				my_mlx_pixel_put(&(vars->img), i, j, rgb);
// 			}
// 		}
// 	}
// 	copy_image(vars);
// 	make_menu(vars, 0, 0, vars->img_copy);
// 	vars->mode = HIDDEN;
// 	mlx_put_image_to_window(vars->mlx, vars->win, vars->img_copy.img, 0, 0);
// 	printf("end: %ld\n", current_time());
// }

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

// void	pre_camera(t_vars *vars, int i)
// {
// 	int				j;
// 	t_inter			shape;
// 	t_coords		vect;
// 	long			start;
// 	long			end;

// 	start = current_time();
// 	vars->state = PRERENDER;
// 	vars->screen = screen_calcul(vars);
// 	while (i < vars->win_sizes.x_len)
// 	{
// 		j = 0;
// 		while (j < vars->win_sizes.y_height)
// 		{
// 			vect = camera_vect(vars, i, j, vars->screen);
// 			shape = find_closest_shape(vect, vars->gen->c->coords,
// 					vars->gen->shapes, 0);
// 			if (shape.shape)
// 				draw_pixel_block(vars, shape, i, j);
// 			j += PIXELS;
// 		}
// 		i += PIXELS;
// 	}
// 	info_box(vars);
// 	mlx_put_image_to_window(vars->mlx, vars->win, vars->pre_img_copy.img, 0, 0);
// 	end = current_time();
// 	printf("%ld\n", end - start);
// }

void	*pre_camera_thread(void *data)
{
	t_data		*info;
	int			j;
	int			i;
	t_coords	vect;
	t_inter		shape;

	info = data;
	i = info->sx;
	while (i < info->ex)
	{
		j = 0;
		while (j < info->vars->win_sizes.y_height)
		{
			vect = camera_vect(info->vars, i, j, info->vars->screen);
			shape = find_closest_shape(vect, info->vars->gen->c->coords,
					info->vars->gen->shapes, 0);
			if (shape.shape)
				draw_pixel_block(info->vars, shape, i, j);
			j += PIXELS;
		}
		i += PIXELS;
	}
	return (0);
}

void	pre_camera(t_vars *vars, int i)
{
	t_data			tdata[8];
	pthread_t		threads[8];
	int				step;
	int				j;

	vars->state = PRERENDER;
	vars->screen = screen_calcul(vars);
	step = vars->win_sizes.x_len / 8;
	while (i < 8)
	{
		tdata[i].vars = deep_copy(vars);
		if (!tdata[i].vars)
			break ;
		tdata[i].sx = i * step;
		if (i == 7)
			tdata[i].ex = vars->win_sizes.x_len;
		else
			tdata[i].ex = (i + 1) * step;
		pthread_create(&threads[i], NULL, pre_camera_thread, &tdata[i]);
		i++;
	}
	if (i != 8)
	{
		j = 0;
		while (j < i)
		{
			thread_failure(tdata[j].vars);
			pthread_join(threads[j], NULL);
			j++;
		}
		error_exit_vars(vars, "fucking hell", 0);
	}
	i = 0;
	while (i < 8)
		pthread_join(threads[i++], NULL);
	i = 0;
	while (i < 8)
	{
		thread_failure(tdata[i].vars);
		i++;
	}
 	info_box(vars);
 	mlx_put_image_to_window(vars->mlx, vars->win, vars->pre_img_copy.img, 0, 0);
}
