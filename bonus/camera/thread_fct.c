/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_fct.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvauthey <dvauthey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 15:56:02 by dvauthey          #+#    #+#             */
/*   Updated: 2025/07/03 15:56:54 by dvauthey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"

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
