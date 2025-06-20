/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hjkl.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbaj <akabbaj@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 22:32:21 by akabbaj           #+#    #+#             */
/*   Updated: 2025/06/20 22:59:21 by akabbaj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "key_presses.h"

void	h_press(t_vars *vars)
{
	if (vars->ambient == ON)
		vars->ambient = OFF;
	vars->ambient = ON;
}

void	j_press(t_vars *vars)
{
	if (vars->diffuse == ON)
		vars->diffuse = OFF;
	vars->diffuse = ON;
}

void	k_press(t_vars *vars)
{
	if (vars->specular == ON)
		vars->specular = OFF;
	vars->specular = ON;
}

void	l_press(t_vars *vars)
{
	if (vars->shadow == ON)
		vars->shadow = OFF;
	vars->shadow = ON;
}

void	hjkl_handler(t_vars *vars, int button)
{
	vars->state = PRERENDER;
	clear_image(&(vars->pre_img), vars->win_sizes.x_len,
		vars->win_sizes.y_height);
	if (button == H)
		h_press(vars);
	if (button == J)
		j_press(vars);
	if (button == K)
		k_press(vars);
	if (button == L)
		l_press(vars);
	pre_camera(vars, 0, 0);
}
