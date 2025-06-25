/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbaj <akabbaj@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 14:23:57 by akabbaj           #+#    #+#             */
/*   Updated: 2025/06/24 14:32:41 by akabbaj          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"

static int	mouse_closing(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	mlx_destroy_image(vars->mlx, vars->img.img);
	if (vars->img_copy.img)
		mlx_destroy_image(vars->mlx, vars->img_copy.img);
	if (vars->loading_image.img)
		mlx_destroy_image(vars->mlx, vars->loading_image.img);
	if (vars->pre_img_copy.img)
		mlx_destroy_image(vars->mlx, vars->pre_img_copy.img);
	if (vars->pre_img.img)
		mlx_destroy_image(vars->mlx, vars->pre_img.img);
	mlx_destroy_display(vars->mlx);
	free(vars->mlx);
	free_gen(vars->gen);
	exit(EXIT_SUCCESS);
	return (0);
}

static int	closing(int keycode, t_vars *vars)
{
	if (keycode == 65307)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		mlx_destroy_image(vars->mlx, vars->img.img);
		if (vars->img_copy.img)
			mlx_destroy_image(vars->mlx, vars->img_copy.img);
		if (vars->loading_image.img)
			mlx_destroy_image(vars->mlx, vars->loading_image.img);
		if (vars->pre_img_copy.img)
			mlx_destroy_image(vars->mlx, vars->pre_img_copy.img);
		if (vars->pre_img.img)
			mlx_destroy_image(vars->mlx, vars->pre_img.img);
		mlx_destroy_display(vars->mlx);
		free(vars->mlx);
		free_gen(vars->gen);
		exit(EXIT_SUCCESS);
	}
	return (0);
}

void	error_exit_vars(t_vars *vars, char *message, int is_perror)
{
	if (vars->win)
		mlx_destroy_window(vars->mlx, vars->win);
	if (vars->img.img)
		mlx_destroy_image(vars->mlx, vars->img.img);
	if (vars->img_copy.img)
		mlx_destroy_image(vars->mlx, vars->img_copy.img);
	if (vars->pre_img_copy.img)
		mlx_destroy_image(vars->mlx, vars->pre_img_copy.img);
	if (vars->pre_img.img)
		mlx_destroy_image(vars->mlx, vars->pre_img.img);
	if (vars->loading_image.img)
		mlx_destroy_image(vars->mlx, vars->loading_image.img);
	if (vars->mlx)
	{
		mlx_destroy_display(vars->mlx);
		free(vars->mlx);
	}
	if (vars->gen)
		free_gen(vars->gen);
	if (is_perror)
		perror(message);
	else
		write(1, message, ft_strlen(message));
	exit(EXIT_FAILURE);
}

static void	creating_all(t_vars *vars)
{
	vars->win_sizes.x_len = 1000.0;
	vars->win_sizes.y_height = 600.0;
	vars->mlx = mlx_init();
	if (!vars->mlx)
		error_exit_vars(vars, "Error mlx_init\n", 0);
	vars->win = mlx_new_window(vars->mlx, vars->win_sizes.x_len,
			vars->win_sizes.y_height, "minirt");
	if (!vars->win)
		error_exit_vars(vars, "Error mlx win\n", 0);
	vars->img.img = mlx_new_image(vars->mlx, vars->win_sizes.x_len,
			vars->win_sizes.y_height);
	if (!vars->img.img)
		error_exit_vars(vars, "Error mlx img\n", 0);
	vars->img.addr = mlx_get_data_addr(vars->img.img,
			&(vars->img.bits_per_pixel), &(vars->img.line_length),
			&(vars->img.endian));
	vars->img_copy.img = mlx_new_image(vars->mlx, vars->win_sizes.x_len,
			vars->win_sizes.y_height);
	if (!vars->img_copy.img)
		error_exit_vars(vars, "Error mlx img\n", 0);
	vars->img_copy.addr = mlx_get_data_addr(vars->img_copy.img,
			&(vars->img_copy.bits_per_pixel), &(vars->img_copy.line_length),
			&(vars->img_copy.endian));
	vars->pre_img.img = mlx_new_image(vars->mlx, vars->win_sizes.x_len,
			vars->win_sizes.y_height);
	if (!vars->pre_img.img)
		error_exit_vars(vars, "Error mlx img\n", 0);
	vars->pre_img.addr = mlx_get_data_addr(vars->pre_img.img,
			&(vars->pre_img.bits_per_pixel), &(vars->pre_img.line_length),
			&(vars->pre_img.endian));
	vars->pre_img_copy.img = mlx_new_image(vars->mlx, vars->win_sizes.x_len,
			vars->win_sizes.y_height);
	if (!vars->pre_img_copy.img)
		error_exit_vars(vars, "Error mlx img\n", 0);
	vars->pre_img_copy.addr = mlx_get_data_addr(vars->pre_img_copy.img,
			&(vars->pre_img_copy.bits_per_pixel), &(vars->pre_img_copy.line_length),
			&(vars->pre_img_copy.endian));
	vars->loading_image.img = mlx_new_image(vars->mlx, vars->win_sizes.x_len,
			vars->win_sizes.y_height);
	if (!vars->loading_image.img)
		error_exit_vars(vars, "Error mlx img\n", 0);
	vars->loading_image.addr = mlx_get_data_addr(vars->loading_image.img,
			&(vars->loading_image.bits_per_pixel), &(vars->loading_image.line_length),
			&(vars->loading_image.endian));
}

void	creating_window(t_gen *gen)
{
	t_vars		vars;
	t_button	button;

	creating_all(&vars);
	vars.obj = NONE;
	vars.obj_id = 0;
	vars.light_count = 0;
	vars.shape_count = 0;
	vars.page_num = 1;
	vars.epsilon = 1;
	vars.gen = gen;
	vars.ambient = ON;
	vars.specular = ON;
	vars.diffuse = ON;
	vars.shadow = ON;
	vars.starttime = current_time();
	button.colour = 0x9c9797;
	button.text = "rendering";
	button.type = TEXT;
	button.bx = (vars.win_sizes.x_len / 2) * 0.8;
	button.ex = (vars.win_sizes.x_len / 2) * 1.2;
	button.by = vars.win_sizes.y_height / 2 * 0.9;
	button.ey = vars.win_sizes.y_height / 2 * 1.1;
	make_box(&vars, button, 0, vars.loading_image);
	pre_camera(&vars, 0, 0);
	mlx_hook(vars.win, 2, 1L << 0, closing, &vars);
	mlx_hook(vars.win, 17, 1L << 17, mouse_closing, &vars);
	mlx_mouse_hook(vars.win, &mouse_click, &vars);
	mlx_key_hook(vars.win, &key_press, &vars);
	mlx_loop_hook(vars.mlx, render_next_frame, &vars);
	mlx_loop(vars.mlx);
}
