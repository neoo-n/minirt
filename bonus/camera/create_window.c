/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvauthey <dvauthey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 15:21:54 by akabbaj           #+#    #+#             */
/*   Updated: 2025/07/03 16:11:59 by dvauthey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"

void	init_img(t_vars *vars, t_dataimg *img)
{
	img->img = mlx_new_image(vars->mlx, vars->win_sizes.x_len,
			vars->win_sizes.y_height);
	if (!img->img)
		error_exit_vars(vars, "Error mlx img\n", 0);
	img->addr = mlx_get_data_addr(img->img,
			&(img->bits_per_pixel), &(img->line_length),
			&(img->endian));
}

static void	creating_all(t_vars *vars)
{
	vars->win_sizes.x_len = X_LEN;
	vars->win_sizes.y_height = Y_HEIGHT;
	vars->mlx = mlx_init();
	if (!vars->mlx)
		error_exit_vars(vars, "Error mlx_init\n", 0);
	vars->win = mlx_new_window(vars->mlx, vars->win_sizes.x_len,
			vars->win_sizes.y_height, "minirt");
	if (!vars->win)
		error_exit_vars(vars, "Error mlx win\n", 0);
	init_img(vars, &(vars->img));
	init_img(vars, &(vars->img_copy));
	init_img(vars, &(vars->pre_img));
	init_img(vars, &(vars->pre_img_copy));
	init_img(vars, &(vars->loading_image));
}

void	init_vars(t_vars *vars, t_gen *gen)
{
	vars->obj = NONE;
	vars->obj_id = 0;
	vars->light_count = 0;
	vars->shape_count = 0;
	vars->page_num = 1;
	vars->gen = gen;
	vars->ambient = ON;
	vars->specular = ON;
	vars->diffuse = ON;
	vars->shadow = ON;
	vars->starttime = current_time();
}

void	creating_window(t_gen *gen)
{
	t_vars		vars;
	t_button	button;

	creating_all(&vars);
	init_vars(&vars, gen);
	button.colour = 0x9c9797;
	button.text = "rendering";
	button.type = TEXT;
	button.bx = (vars.win_sizes.x_len / 2) * 0.8;
	button.ex = (vars.win_sizes.x_len / 2) * 1.2;
	button.by = vars.win_sizes.y_height / 2 * 0.9;
	button.ey = vars.win_sizes.y_height / 2 * 1.1;
	make_box(&vars, button, 0, vars.loading_image);
	mlx_put_image_to_window(vars.mlx, vars.win, vars.loading_image.img, 0, 0);
	camera(&vars, -1, 0);
	mlx_hook(vars.win, 2, 1L << 0, closing, &vars);
	mlx_hook(vars.win, 17, 1L << 17, mouse_closing, &vars);
	mlx_mouse_hook(vars.win, &mouse_click, &vars);
	mlx_key_hook(vars.win, &key_press, &vars);
	mlx_loop_hook(vars.mlx, render_next_frame, &vars);
	mlx_loop(vars.mlx);
}
