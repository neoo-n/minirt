/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvauthey <dvauthey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 15:40:38 by dvauthey          #+#    #+#             */
/*   Updated: 2025/06/03 10:53:47 by dvauthey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static int	get_rgb(t_rgb rgb)
{
	return ((rgb.r << 16 | rgb.g << 8 | rgb.b));
}

static double	vector_norm(double x, double y)
{
	return (sqrt(x * x + y * y));
}

void	disc(t_vars *vars)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < vars->win_sizes.x_len)
	{
		while (j < vars->win_sizes.y_height)
		{
			if (vector_norm(i - vars->gen->shapes[1]->coords.x, j - vars->gen->shapes[1]->coords.y) <= vars->gen->shapes[1]->diam / 2 + vars->epsilon)
			{
				my_mlx_pixel_put(&(vars->img), i, j, get_rgb(vars->gen->shapes[1]->rgb));
			}
			j++;
		}
		j = 0;
		i++;
	}
}

void	drawing(t_vars *vars)
{
	disc(vars);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, 0, 0);
	camera(vars);
}