/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   closing_window.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvauthey <dvauthey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 16:11:31 by dvauthey          #+#    #+#             */
/*   Updated: 2025/07/03 16:14:44 by dvauthey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"

int	mouse_closing(t_vars *vars)
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

int	closing(int keycode, t_vars *vars)
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
