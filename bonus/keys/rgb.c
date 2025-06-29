/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbaj <akabbaj@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 16:07:02 by akabbaj           #+#    #+#             */
/*   Updated: 2025/06/29 16:07:53 by akabbaj          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "key_presses.h"

void	minus_rgb(t_vars *vars, int light_id, int shape_id)
{
	t_rgb	rgb;

	if (vars->obj == LIGHT)
	{
		if (vars->mode == RED && vars->gen->l[light_id]->rgb.r > 0)
			vars->gen->l[light_id]->rgb.r--;
		else if (vars->mode == GREEN && vars->gen->l[light_id]->rgb.g > 0)
			vars->gen->l[light_id]->rgb.g--;
		else if (vars->mode == BLUE && vars->gen->l[light_id]->rgb.b > 0)
			vars->gen->l[light_id]->rgb.b--;
		rgb = vars->gen->l[light_id]->rgb;
		printf("RGB: %.f,%.f,%.f\n", rgb.r, rgb.g, rgb.b);
	}
	else if (vars->obj == SHAPE)
	{
		if (vars->mode == RED && vars->gen->shapes[shape_id]->rgb.r > 0)
			vars->gen->shapes[shape_id]->rgb.r--;
		else if (vars->mode == GREEN && vars->gen->shapes[shape_id]->rgb.g > 0)
			vars->gen->shapes[shape_id]->rgb.g--;
		else if (vars->mode == BLUE && vars->gen->shapes[shape_id]->rgb.b > 0)
			vars->gen->shapes[shape_id]->rgb.b--;
		rgb = vars->gen->l[light_id]->rgb;
		printf("RGB: %.f,%.f,%.f\n", rgb.r, rgb.g, rgb.b);
	}
}

void	plus_rgb(t_vars *vars, int light_id, int shape_id)
{
	t_rgb	rgb;

	if (vars->obj == LIGHT)
	{
		if (vars->mode == RED && vars->gen->l[light_id]->rgb.r < 255)
			vars->gen->l[light_id]->rgb.r++;
		else if (vars->mode == GREEN && vars->gen->l[light_id]->rgb.g < 255)
			vars->gen->l[light_id]->rgb.g++;
		else if (vars->mode == BLUE && vars->gen->l[light_id]->rgb.b < 255)
			vars->gen->l[light_id]->rgb.b++;
		rgb = vars->gen->l[light_id]->rgb;
		printf("RGB: %.f,%.f,%.f\n", rgb.r, rgb.g, rgb.b);
	}
	else if (vars->obj == SHAPE)
	{
		if (vars->mode == RED && vars->gen->shapes[shape_id]->rgb.r < 255)
			vars->gen->shapes[shape_id]->rgb.r++;
		else if (vars->mode == GREEN
			&& vars->gen->shapes[shape_id]->rgb.g < 255)
			vars->gen->shapes[shape_id]->rgb.g++;
		else if (vars->mode == BLUE && vars->gen->shapes[shape_id]->rgb.b < 255)
			vars->gen->shapes[shape_id]->rgb.b++;
		rgb = vars->gen->l[light_id]->rgb;
		printf("RGB: %.f,%.f,%.f\n", rgb.r, rgb.g, rgb.b);
	}
}

void	rgb_handler(int button, t_vars *vars)
{
	if (vars->obj == LIGHT || vars->obj == SHAPE)
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
