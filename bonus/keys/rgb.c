/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbaj <akabbaj@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 14:14:47 by akabbaj           #+#    #+#             */
/*   Updated: 2025/07/04 14:15:41 by akabbaj          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "key_presses.h"

t_rgb	*get_rgb_ptr(t_vars *vars, int light_id, int shape_id)
{
	if (vars->obj == LIGHT)
		return (&(vars->gen->l[light_id]->rgb));
	else if (vars->obj == SHAPE)
		return (&(vars->gen->shapes[shape_id]->rgb));
	else if (vars->obj == SETT)
		return (&(vars->gen->a->rgb));
	return (0);
}

void	minus_rgb(t_vars *vars, int light_id, int shape_id)
{
	t_rgb	*rgb;

	rgb = get_rgb_ptr(vars, light_id, shape_id);
	if (vars->mode == RED && rgb->r > 0)
		rgb->r--;
	else if (vars->mode == GREEN && rgb->g > 0)
		rgb->g--;
	else if (vars->mode == BLUE && rgb->b > 0)
		rgb->b--;
	printf("RGB: %.f,%.f,%.f\n", rgb->r, rgb->g, rgb->b);
}

void	plus_rgb(t_vars *vars, int light_id, int shape_id)
{
	t_rgb	*rgb;

	rgb = get_rgb_ptr(vars, light_id, shape_id);
	if (vars->mode == RED && rgb->r < 255)
		rgb->r++;
	else if (vars->mode == GREEN && rgb->g < 255)
		rgb->g++;
	else if (vars->mode == BLUE && rgb->b < 255)
		rgb->b++;
	printf("RGB: %.f,%.f,%.f\n", rgb->r, rgb->g, rgb->b);
}

void	rgb_handler(int button, t_vars *vars)
{
	if (vars->obj == LIGHT || vars->obj == SHAPE || vars->obj == SETT)
	{
		if (button == R && vars->mode != RED)
			vars->mode = RED;
		else if (button == R)
			vars->mode = HIDDEN;
		else if (button == G && vars->mode != GREEN)
			vars->mode = GREEN;
		else if (button == G)
			vars->mode = HIDDEN;
		else if (button == B && vars->mode != BLUE)
			vars->mode = BLUE;
		else
			vars->mode = HIDDEN;
		pre_camera(vars, 0);
	}
}
