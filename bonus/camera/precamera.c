/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precamera.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbaj <akabbaj@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 13:56:48 by akabbaj           #+#    #+#             */
/*   Updated: 2025/07/06 13:56:55 by akabbaj          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"

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

	vars->state = PRERENDER;
	vars->screen = screen_calcul(vars);
	step = vars->win_sizes.x_len / 8;
	while (i < 8)
	{
		if (!create_threads(i, step, vars, tdata))
			break ;
		pthread_create(&threads[i], NULL, pre_camera_thread, &tdata[i]);
		i++;
	}
	if (i != 8)
		total_failure(vars, i, tdata, threads);
	i = 0;
	while (i < 8)
		pthread_join(threads[i++], NULL);
	i = 0;
	while (i < 8)
		thread_failure(tdata[i++].vars);
	info_box(vars);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->pre_img_copy.img, 0, 0);
}
