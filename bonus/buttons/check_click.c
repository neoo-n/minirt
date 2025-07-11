/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbaj <akabbaj@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 14:20:26 by akabbaj           #+#    #+#             */
/*   Updated: 2025/07/04 14:21:10 by akabbaj          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "buttons.h"

t_bool	check_menu_button(t_vars *vars, int x, int y)
{
	double	x_min;
	double	x_max;
	double	y_min;
	double	y_max;

	x_min = vars->win_sizes.x_len - vars->win_sizes.x_len * 0.035;
	x_max = vars->win_sizes.x_len - vars->win_sizes.x_len * 0.005;
	y_min = vars->win_sizes.y_height * 0.0035;
	y_max = vars->win_sizes.y_height * 0.035;
	if (x >= x_min && x <= x_max && y >= y_min && y <= y_max)
		return (True);
	return (False);
}

t_bool	check_select_mode(t_vars *vars)
{
	if (vars->mode == OBJECT_SELECT || vars->mode == OBJECT_SELECT_ARROWS
		|| vars->mode == OBJECT_SELECT_LASTPAGE)
		return (True);
	return (False);
}

t_type	check_arrow_click(t_vars *vars, int x, int y, int button_len)
{
	int	length;
	int	left_edge;
	int	right_edge;
	int	top_edge;
	int	bottom_edge;

	right_edge = vars->win_sizes.x_len - vars->win_sizes.x_len * 0.04;
	left_edge = vars->win_sizes.x_len - vars->win_sizes.x_len * 0.07;
	bottom_edge = vars->win_sizes.y_height * (1 - 0.0035);
	top_edge = vars->win_sizes.y_height * (1 - 0.035);
	length = right_edge - left_edge;
	if (x >= left_edge && x <= right_edge && y <= bottom_edge && y >= top_edge
		&& vars->mode == OBJECT_SELECT_ARROWS)
		return (ARROW_R);
	if (vars->page_num > 1 && x >= left_edge - button_len + length
		&& x <= right_edge - button_len + length && y <= bottom_edge
		&& y >= top_edge && vars->mode)
		return (ARROW_L);
	return (EMPTY);
}

t_bool	obj_click(t_vars *vars, int x, int y, int buttons)
{
	int		but_len;
	int		but_height;
	int		but_sx;
	int		but_sy;
	int		i;

	but_sx = vars->win_sizes.x_len - vars->win_sizes.x_len * 0.3;
	but_len = (vars->win_sizes.x_len - vars->win_sizes.x_len * 0.04) - (but_sx);
	but_sy = vars->win_sizes.y_height * 0.0035;
	but_height = but_len / 5 - but_sy;
	i = 0;
	while ((but_sy + but_height) + but_height * 1.05
		< vars->win_sizes.y_height - vars->win_sizes.y_height * 0.035
		&& i < max_for_page(vars, buttons))
	{
		if (x >= but_sx && x <= but_sx + but_len
			&& y >= but_sy && y <= but_sy + but_height)
		{
			vars->obj_id = i + ((vars->page_num - 1) * buttons);
			return (True);
		}
		but_sy += but_height * 1.05;
		i++;
	}
	return (False);
}
