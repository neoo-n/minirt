/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvauthey <dvauthey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 16:04:28 by dvauthey          #+#    #+#             */
/*   Updated: 2025/07/03 16:13:51 by dvauthey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"

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

t_vars	*deep_copy(t_vars	*vars)
{
	t_vars	*copy;

	copy = malloc(sizeof(t_vars));
	if (!copy)
		return (0);
	copy->mlx = vars->mlx;
	copy->win = vars->win;
	copy->win_sizes = vars->win_sizes;
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
