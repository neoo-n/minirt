/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvauthey <dvauthey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 14:31:10 by dvauthey          #+#    #+#             */
/*   Updated: 2025/05/29 16:47:30 by dvauthey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static int	mouse_closing(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	mlx_destroy_image(vars->mlx, vars->img.img);
	mlx_destroy_display(vars->mlx);
	free(vars->mlx);
	exit(EXIT_SUCCESS);
	return (0);
}

static int	closing(int keycode, t_vars *vars)
{
	if (keycode == 65307)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		mlx_destroy_image(vars->mlx, vars->img.img);
		mlx_destroy_display(vars->mlx);
		free(vars->mlx);
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
	if (vars->mlx)
	{
		mlx_destroy_display(vars->mlx);
		free(vars->mlx);
	}
	if (is_perror)
		perror(message);
	else
		write(1, message, ft_strlen(message));
	exit(EXIT_FAILURE);
}

static void	creating_all(t_vars *vars)
{
	vars->win_sizes.x_len = 3520;
	vars->win_sizes.y_height = 1880;
	vars->mlx = mlx_init();
	if (!vars->mlx)
		error_exit_vars(vars, "Error mlx_init\n", 0);
	vars->win = mlx_new_window(vars->mlx, vars->win_sizes.x_len,
			vars->win_sizes.y_height, "FdF");
	if (!vars->win)
		error_exit_vars(vars, "Error mlx win\n", 0);
	vars->img.img = mlx_new_image(vars->mlx, vars->win_sizes.x_len,
			vars->win_sizes.y_height);
	if (!vars->img.img)
		error_exit_vars(vars, "Error mlx img\n", 0);
	vars->img.addr = mlx_get_data_addr(vars->img.img,
			&(vars->img.bits_per_pixel), &(vars->img.line_length),
			&(vars->img.endian));
}

void	creating_window()
{
	t_vars		vars;

	creating_all(&vars);
	vars.epsilon = 1;
	drawing(&vars);
	mlx_hook(vars.win, 2, 1L << 0, closing, &vars);
	mlx_hook(vars.win, 17, 1L << 17, mouse_closing, &vars);
	mlx_loop(vars.mlx);
}
