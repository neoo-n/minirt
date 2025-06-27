/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_helper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbaj <akabbaj@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 11:16:47 by akabbaj           #+#    #+#             */
/*   Updated: 2025/06/27 11:18:53 by akabbaj          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "buttons.h"

void	clear_image(t_dataimg *img, int width, int height)
{
	int		x;
	int		y;
	char	*dst;

	y = 0;
	while (y < height)
	{
		x = 0;
		while (x < width)
		{
			dst = img->addr + (y * img->line_length
					+ x * (img->bits_per_pixel / 8));
			*(unsigned int *)dst = 0x000000;
			x++;
		}
		y++;
	}
}

int	count_objs(t_vars *vars)
{
	int	i;

	i = 0;
	while (vars->gen->shapes[i])
		i++;
	return (i + 2);
}

int	count_lights(t_vars *vars)
{
	int	i;

	i = 0;
	while (vars->gen->l[i])
		i++;
	return (i);
}

int	max_for_page(t_vars *vars, int buttons)
{
	int	objs;
	int	max_pages;

	objs = count_objs(vars) + count_lights(vars);
	max_pages = ceil((double) objs / (double) buttons);
	if (vars->page_num < max_pages)
		return (buttons);
	if (objs % buttons == 0)
		return  (buttons - 1);
	return ((objs % buttons) - 1);
}

int	count_buttons(t_vars *vars, int button_start_y, int button_height)
{
	int	buttons;

	buttons = 0;
	while ((button_start_y + button_height) + button_height * 1.05
		< vars->win_sizes.y_height - vars->win_sizes.y_height * 0.035)
	{
		buttons++;
		button_start_y += button_height * 1.05;
	}
	return (buttons);
}
