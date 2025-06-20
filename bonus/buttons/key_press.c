/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbaj <akabbaj@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 15:33:08 by akabbaj           #+#    #+#             */
/*   Updated: 2025/06/20 15:42:40 by akabbaj          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "buttons.h"

long	current_time(void)
{
	struct timeval	tv;
	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

int	key_press(int button, t_vars *vars)
{
	int	light_count;

	light_count = count_lights(vars);
	if (current_time() - vars->starttime < 200)
		return (0);
	if (button == ENTER && vars->state == PRERENDER)
	{
		vars->state = RENDERING;
		mlx_put_image_to_window(vars->mlx, vars->win, vars->loading_image.img, 0, 0);
	}
	else if (button == PLUS && (vars->obj == SHAPE || vars->obj == LIGHT))
	{
		clear_image(&(vars->pre_img), vars->win_sizes.x_len, vars->win_sizes.y_height);
		vars->state = PRERENDER;
		if (vars->obj == SHAPE)
			vars->gen->shapes[vars->obj_id - light_count - 1]->diam += 0.2;
		else if (vars->gen->l[vars->obj_id - 1]->bright <= 0.95)
			vars->gen->l[vars->obj_id - 1]->bright += 0.05;
		pre_camera(vars, 0, 0);
	}
	else if (button == MINUS && (vars->obj == SHAPE || vars->obj == LIGHT))
	{
		clear_image(&(vars->pre_img), vars->win_sizes.x_len, vars->win_sizes.y_height);
		vars->state = PRERENDER;
		if (vars->obj == SHAPE && vars->gen->shapes[vars->obj_id - light_count - 1]->diam > 0.2)
			vars->gen->shapes[vars->obj_id - light_count - 1]->diam -= 0.2;
		else if (vars->gen->l[vars->obj_id - 1]->bright >= 0.05)
			vars->gen->l[vars->obj_id - 1]->bright -= 0.05;
		pre_camera(vars, 0, 0);
	}
	else if (button == D && vars->obj != NONE)
	{
		clear_image(&(vars->pre_img), vars->win_sizes.x_len, vars->win_sizes.y_height);
		vars->state = PRERENDER;
		if (vars->obj == CAM)
		{
			vars->gen->c->coords.x += vars->screen.vect_x.x * 0.2;
			vars->gen->c->coords.y += vars->screen.vect_x.y * 0.2;
			vars->gen->c->coords.z += vars->screen.vect_x.z * 0.2;
		}
		else if (vars->obj == SHAPE)
		{
			vars->gen->shapes[vars->obj_id - light_count - 1]->coords.x += vars->screen.vect_x.x * 0.2;
			vars->gen->shapes[vars->obj_id - light_count - 1]->coords.y += vars->screen.vect_x.y * 0.2;
			vars->gen->shapes[vars->obj_id - light_count - 1]->coords.z += vars->screen.vect_x.z * 0.2;
		}
		else
		{
			vars->gen->l[vars->obj_id - 1]->coords.x += vars->screen.vect_x.x * 0.2;
			vars->gen->l[vars->obj_id - 1]->coords.y += vars->screen.vect_x.y * 0.2;
			vars->gen->l[vars->obj_id - 1]->coords.z += vars->screen.vect_x.z * 0.2;
		}
		pre_camera(vars, 0, 0);
	}
	else if (button == A && vars->obj != NONE)
	{
		clear_image(&(vars->pre_img), vars->win_sizes.x_len, vars->win_sizes.y_height);
		vars->state = PRERENDER;
		if (vars->obj == CAM)
		{
			vars->gen->c->coords.x -= vars->screen.vect_x.x * 0.2;
			vars->gen->c->coords.y -= vars->screen.vect_x.y * 0.2;
			vars->gen->c->coords.z -= vars->screen.vect_x.z * 0.2;
		}
		else if (vars->obj == SHAPE)
		{
			vars->gen->shapes[vars->obj_id - light_count - 1]->coords.x -= vars->screen.vect_x.x * 0.2;
			vars->gen->shapes[vars->obj_id - light_count - 1]->coords.y -= vars->screen.vect_x.y * 0.2;
			vars->gen->shapes[vars->obj_id - light_count - 1]->coords.z -= vars->screen.vect_x.z * 0.2;
		}
		else
		{
			vars->gen->l[vars->obj_id - 1]->coords.x -= vars->screen.vect_x.x * 0.2;
			vars->gen->l[vars->obj_id - 1]->coords.y -= vars->screen.vect_x.y * 0.2;
			vars->gen->l[vars->obj_id - 1]->coords.z -= vars->screen.vect_x.z * 0.2;
		}
		pre_camera(vars, 0, 0);
	}
	else if (button == S && vars->obj != NONE)
	{
		clear_image(&(vars->pre_img), vars->win_sizes.x_len, vars->win_sizes.y_height);
		vars->state = PRERENDER;
		if (vars->obj == CAM)
		{
			vars->gen->c->coords.x += vars->screen.vect_y.x * 0.2;
			vars->gen->c->coords.y += vars->screen.vect_y.y * 0.2;
			vars->gen->c->coords.z += vars->screen.vect_y.z * 0.2;
		}
		else if (vars->obj == SHAPE)
		{
			vars->gen->shapes[vars->obj_id - light_count - 1]->coords.x += vars->screen.vect_y.x * 0.2;
			vars->gen->shapes[vars->obj_id - light_count - 1]->coords.y += vars->screen.vect_y.y * 0.2;
			vars->gen->shapes[vars->obj_id - light_count - 1]->coords.z += vars->screen.vect_y.z * 0.2;
		}
		else
		{
			vars->gen->l[vars->obj_id - 1]->coords.x += vars->screen.vect_y.x * 0.2;
			vars->gen->l[vars->obj_id - 1]->coords.y += vars->screen.vect_y.y * 0.2;
			vars->gen->l[vars->obj_id - 1]->coords.z += vars->screen.vect_y.z * 0.2;
		}
		pre_camera(vars, 0, 0);
	}
	else if (button == W && vars->obj != NONE)
	{
		clear_image(&(vars->pre_img), vars->win_sizes.x_len, vars->win_sizes.y_height);
		vars->state = PRERENDER;
		if (vars->obj == CAM)
		{
			vars->gen->c->coords.x -= vars->screen.vect_y.x * 0.2;
			vars->gen->c->coords.y -= vars->screen.vect_y.y * 0.2;
			vars->gen->c->coords.z -= vars->screen.vect_y.z * 0.2;
		}
		else if (vars->obj == SHAPE)
		{
			vars->gen->shapes[vars->obj_id - light_count - 1]->coords.x -= vars->screen.vect_y.x * 0.2;
			vars->gen->shapes[vars->obj_id - light_count - 1]->coords.y -= vars->screen.vect_y.y * 0.2;
			vars->gen->shapes[vars->obj_id - light_count - 1]->coords.z -= vars->screen.vect_y.z * 0.2;
		}
		else
		{
			vars->gen->l[vars->obj_id - 1]->coords.x -= vars->screen.vect_y.x * 0.2;
			vars->gen->l[vars->obj_id - 1]->coords.y -= vars->screen.vect_y.y * 0.2;
			vars->gen->l[vars->obj_id - 1]->coords.z -= vars->screen.vect_y.z * 0.2;
		}
		pre_camera(vars, 0, 0);
	}
	else if (button == E && vars->obj != NONE)
	{
		clear_image(&(vars->pre_img), vars->win_sizes.x_len, vars->win_sizes.y_height);
		vars->state = PRERENDER;
		if (vars->obj == CAM)
		{
			vars->gen->c->coords.x -= vars->gen->c->vector.x * 0.2;
			vars->gen->c->coords.y -= vars->gen->c->vector.y * 0.2;
			vars->gen->c->coords.z -= vars->gen->c->vector.z * 0.2;
		}
		else if (vars->obj == SHAPE)
		{
			vars->gen->shapes[vars->obj_id - light_count - 1]->coords.x -= vars->gen->c->vector.x * 0.2;
			vars->gen->shapes[vars->obj_id - light_count - 1]->coords.y -= vars->gen->c->vector.y * 0.2;
			vars->gen->shapes[vars->obj_id - light_count - 1]->coords.z -= vars->gen->c->vector.z * 0.2;
		}
		else
		{
			vars->gen->l[vars->obj_id - 1]->coords.x -= vars->gen->c->vector.x * 0.2;
			vars->gen->l[vars->obj_id - 1]->coords.y -= vars->gen->c->vector.y * 0.2;
			vars->gen->l[vars->obj_id - 1]->coords.z -= vars->gen->c->vector.z * 0.2;
		}
		pre_camera(vars, 0, 0);
	}
	else if (button == Q && vars->obj != NONE)
	{
		clear_image(&(vars->pre_img), vars->win_sizes.x_len, vars->win_sizes.y_height);
		vars->state = PRERENDER;
		if (vars->obj == CAM)
		{
			vars->gen->c->coords.x += vars->gen->c->vector.x * 0.2;
			vars->gen->c->coords.y += vars->gen->c->vector.y * 0.2;
			vars->gen->c->coords.z += vars->gen->c->vector.z * 0.2;
		}
		else if (vars->obj == SHAPE)
		{
			vars->gen->shapes[vars->obj_id - light_count - 1]->coords.x += vars->gen->c->vector.x * 0.2;
			vars->gen->shapes[vars->obj_id - light_count - 1]->coords.y += vars->gen->c->vector.y * 0.2;
			vars->gen->shapes[vars->obj_id - light_count - 1]->coords.z += vars->gen->c->vector.z * 0.2;
		}
		else
		{
			vars->gen->l[vars->obj_id - 1]->coords.x += vars->gen->c->vector.x * 0.2;
			vars->gen->l[vars->obj_id - 1]->coords.y += vars->gen->c->vector.y * 0.2;
			vars->gen->l[vars->obj_id - 1]->coords.z += vars->gen->c->vector.z * 0.2;
		}
		pre_camera(vars, 0, 0);
	}
	// else if (button == Z && vars->obj != NONE)
	// {
	// 	clear_image(&(vars->pre_img), vars->win_sizes.x_len, vars->win_sizes.y_height);
	// 	vars->state = PRERENDER;
	// 	if (vars->obj == CAM)
	// 	{
	// 		vars->gen->c->vector.x += 0.2;
	// 		vars->gen->c->vector.y += 0.2;
	// 		vars->gen->c->vector.z += 0.2;
	// 	}
	// 	else if (vars->gen->shapes[vars->obj_id - light_count - 1]->shape == PLANE || vars->gen->shapes[vars->obj_id - light_count - 1]->shape == CYLINDER)
	// 	{
	// 		vars->gen->shapes[vars->obj_id - light_count - 1]->vector.x += vars->gen->c->vector.x * 0.2;
	// 		vars->gen->shapes[vars->obj_id - light_count - 1]->vector.y += vars->gen->c->vector.y * 0.2;
	// 		vars->gen->shapes[vars->obj_id - light_count - 1]->vector.z += vars->gen->c->vector.z * 0.2;
	// 	}
	// 	pre_camera(vars, 0, 0);
	// }
	else if (button == H)
	{
		clear_image(&(vars->pre_img), vars->win_sizes.x_len, vars->win_sizes.y_height);
		vars->state = PRERENDER;
		if (vars->ambient == ON)
			vars->ambient = OFF;
		else
			vars->ambient = ON;
		pre_camera(vars, 0, 0);
	}
	else if (button == J)
	{
		clear_image(&(vars->pre_img), vars->win_sizes.x_len, vars->win_sizes.y_height);
		vars->state = PRERENDER;
		if (vars->diffuse == ON)
			vars->diffuse = OFF;
		else
			vars->diffuse = ON;
		pre_camera(vars, 0, 0);
	}
	else if (button == K)
	{
		clear_image(&(vars->pre_img), vars->win_sizes.x_len, vars->win_sizes.y_height);
		vars->state = PRERENDER;
		if (vars->specular == ON)
			vars->specular = OFF;
		else
			vars->specular = ON;
		pre_camera(vars, 0, 0);
	}
	else if (button == L)
	{
		clear_image(&(vars->pre_img), vars->win_sizes.x_len, vars->win_sizes.y_height);
		vars->state = PRERENDER;
		if (vars->shadow == ON)
			vars->shadow = OFF;
		else
			vars->shadow = ON;
		pre_camera(vars, 0, 0);
	}
	return (0);
}

int	render_next_frame(t_vars *vars)
{
	if (vars->state == RENDERING)
	{
		clear_image(&(vars->img), vars->win_sizes.x_len, vars->win_sizes.y_height);
		vars->light_count = 0;
		vars->shape_count = 0;
		vars->page_num = 1;
		vars->obj = NONE;
		camera(vars, 0, 0);
	}
	return (0);
}
