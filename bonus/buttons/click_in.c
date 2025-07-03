/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   click_in.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbaj <akabbaj@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 15:31:11 by akabbaj           #+#    #+#             */
/*   Updated: 2025/07/03 15:31:11 by akabbaj          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "buttons.h"

t_button	measure_button(t_vars *vars)
{
	t_button	res;

	res.bx = vars->win_sizes.x_len - vars->win_sizes.x_len * 0.3;
	res.by = vars->win_sizes.y_height * 0.0035;
	res.ex = (vars->win_sizes.x_len - vars->win_sizes.x_len * 0.04) - (res.bx);
	res.ey = res.ex / 5 - res.by;
	return (res);
}

t_type	click_in_shape(t_vars *vars, int x, int y, t_button meas)
{
	if (vars->mode == OBJ_ADD && x >= meas.bx && x <= meas.bx + meas.ex
		&& y >= meas.by && y <= meas.by + meas.ey)
		return (LIGHT_ADD);
	else if (vars->mode == OBJ_ADD && x >= meas.bx && x <= meas.bx + meas.ex
		&& y >= meas.by + (meas.ey * 1.05)
		&& y <= (meas.by + meas.ey + (meas.ey * 1.05)))
		return (SPHERE_ADD);
	else if (vars->mode == OBJ_ADD && x >= meas.bx && x <= meas.bx + meas.ex
		&& y >= meas.by + (meas.ey * 2.1)
		&& y <= (meas.by + meas.ey + (meas.ey * 2.1)))
		return (PLANE_ADD);
	else if (vars->mode == OBJ_ADD && x >= meas.bx && x <= meas.bx + meas.ex
		&& y >= meas.by + (meas.ey * 3.15)
		&& y <= (meas.by + meas.ey + (meas.ey * 3.15)))
		return (CYL_ADD);
	else if (vars->mode == OBJ_ADD && x >= meas.bx && x <= meas.bx + meas.ex
		&& y >= meas.by + (meas.ey * 4.2)
		&& y <= (meas.by + meas.ey + (meas.ey * 4.2)))
		return (CONE_ADD);
	else
		return (EMPTY);
}

t_type	click_in_basic(t_vars *vars, int x, int y, t_button meas)
{
	if (vars->mode == BASIC && x >= meas.bx && x <= meas.bx + meas.ex
		&& y >= meas.by && y <= meas.by + meas.ey)
		return (TEXT);
	else if (vars->mode == BASIC && x >= meas.bx && x <= meas.bx + meas.ex
		&& y >= meas.by + (meas.ey * 1.05)
		&& y <= (meas.by + meas.ey + (meas.ey * 1.05)))
		return (SETTINGS);
	else if (vars->mode == BASIC && x >= meas.bx && x <= meas.bx + meas.ex
		&& y >= meas.by + (meas.ey * 2.1)
		&& y <= (meas.by + meas.ey + (meas.ey * 2.1)))
		return (PRINT);
	else if (vars->mode == BASIC && x >= meas.bx && x <= meas.bx + meas.ex
		&& y >= meas.by + (meas.ey * 3.15)
		&& y <= (meas.by + meas.ey + (meas.ey * 3.15)))
		return (RESET);
	else if (vars->mode == BASIC && x >= meas.bx && x <= meas.bx + meas.ex
		&& y >= meas.by + (meas.ey * 4.2)
		&& y <= (meas.by + meas.ey + (meas.ey * 4.2)))
		return (ADD_OBJ);
	else
		return (EMPTY);
}

t_type	click_in_button(t_vars *vars, int x, int y)
{
	t_button	meas;

	meas = measure_button(vars);
	if (check_menu_button(vars, x, y))
		return (MENU);
	else if (vars->mode == BASIC)
		return (click_in_basic(vars, x, y, meas));
	else if (vars->mode == OBJ_ADD)
		return (click_in_shape(vars, x, y, meas));
	else if (check_select_mode(vars))
	{
		if (vars->mode != OBJECT_SELECT
			&& (check_arrow_click(vars, x, y, meas.ex) == ARROW_L
				|| check_arrow_click(vars, x, y, meas.ex) == ARROW_R))
			return (check_arrow_click(vars, x, y, meas.ex));
		if (obj_click(vars, x, y, count_buttons(vars, meas.by, meas.ey)))
			return (TEXT);
	}
	return (EMPTY);
}
