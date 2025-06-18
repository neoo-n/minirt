/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buttons.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbaj <akabbaj@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 21:12:26 by akabbaj           #+#    #+#             */
/*   Updated: 2025/06/18 23:40:40 by akabbaj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "buttons.h"

void	display_text(t_vars *vars, t_text text)
{
	t_letter	letter;
	int			x;

	x = 0;
	letter.colour = text.colour;
	letter.size = text.size;
	letter.i = text.x;
	letter.j = text.y;
	while (text.text[x] && x < text.max_char)
	{
		letter.letter = text.text[x];
		make_char(vars, letter);
		letter.i += letter.size;
		x++;
	}
}

t_text	make_text(t_button button, int text_colour)
{
	t_text	res;

	res.colour = text_colour;
	res.size = (button.ey - button.by) * 0.9;
	res.max_char = (button.ex - button.bx) * 0.99 / res.size;
	while (res.max_char < ft_strlen(button.text))
	{
		res.size -= 1;
		res.max_char = (button.ex - button.bx) * 0.95 / res.size;
	}
	res.text = button.text;
	res.x = button.bx + (button.ex - button.bx) * 0.05;
	res.y = button.by + ((button.ey - button.by) * 0.5) - res.size / 2;
	return (res);
}

void	make_menu(t_vars *vars, int line_colour, int i)
{
	t_button	button;
	int			length;
	int			width;

	button.bx = vars->win_sizes.x_len - vars->win_sizes.x_len * 0.035;
	button.ex = vars->win_sizes.x_len - vars->win_sizes.x_len * 0.005;
	button.ey = vars->win_sizes.y_height * 0.035;
	button.by = vars->win_sizes.y_height * 0.0035;
	button.type = MENU;
	button.colour = 0x9c9797;
	make_box(vars, button, 0);
	length = (button.ex - button.bx) * 0.8;
	button.by = button.ey * 0.25;
	width = button.ey * 0.1;
	button.bx = button.bx + (length / 9);
	button.ex = button.bx + length;
	button.colour = line_colour;
	while (i < 3)
	{
		button.ey = button.by + width;
		make_box(vars, button, 0);
		button.by += width * 3;
		i++;
	}
}

// void	make_arrows(t_vars *vars)
// {
// 	t_button	button;
// 	int			length;
// 	int			width;

// 	button.bx = vars->win_sizes.x_len - vars->win_sizes.x_len * 0.035;
// 	button.ex = vars->win_sizes.x_len - vars->win_sizes.x_len * 0.005;
// 	button.ey = vars->win_sizes.y_height * 0.035;
// 	button.by = vars->win_sizes.y_height * 0.0035;
// 	button.type = TEXT;
// 	button.colour = 0x9c9797;
// 	make_box(vars, button, 0);
// 	length = (button.ex - button.bx) * 0.8;
// 	button.by = button.ey * 0.25;
// 	width = button.ey * 0.1;
// 	button.bx = button.bx + (length / 9);
// 	button.ex = button.bx + length;
// 	button.colour = line_colour;
// 	while (i < 3)
// 	{
// 		button.ey = button.by + width;
// 		make_box(vars, button, 0);
// 		button.by += width * 3;
// 		i++;
// 	}
// }

void	display_all_objs(t_vars *vars)
{
	t_button	button;
	int			height;
	int			i;

	button.ex = vars->win_sizes.x_len - vars->win_sizes.x_len * 0.04;
	button.bx = vars->win_sizes.x_len - vars->win_sizes.x_len * 0.3;
	button.type = TEXT;
	button.colour = 0x9c9797;
	button.ey = (button.ex - button.bx) / 5;
	if (button.ey > vars->win_sizes.y_height)
		button.ey = vars->win_sizes.y_height;
	button.by = vars->win_sizes.y_height * 0.0035;
	height = button.ey - button.by;
	if (vars->shape_count == 0 && vars->light_count == 0)
	{
		button.text = "camera";
		make_box(vars, button, 0);
	}
	while (vars->gen->shapes[vars->shape_count] && button.ey + height * 1.05 < vars->win_sizes.y_height - vars->win_sizes.y_height * 0.035)
	{
		button.text = "shape";
		button.by += height * 1.05;
		button.ey += height * 1.05;
		make_box(vars, button, 0);
		vars->shape_count;
	}
	if (!vars->gen->shapes[vars->shape_count])
	{
		vars->mode = OBJECT_SELECT_ARROWS;
		make_arrows(vars);
	}
	else
		vars->mode = OBJECT_SELECT;
}

void	make_obj_button(t_vars *vars)
{
	t_button	button;

	button.ex = vars->win_sizes.x_len - vars->win_sizes.x_len * 0.04;
	button.bx = vars->win_sizes.x_len - vars->win_sizes.x_len * 0.3;
	button.ey = (button.ex - button.bx) / 5;
	button.by = vars->win_sizes.y_height * 0.0035;
	if (button.ey > vars->win_sizes.y_height)
		button.ey = vars->win_sizes.y_height;
	button.type = TEXT;
	button.colour = 0x9c9797;
	if (vars->obj == NONE)
		button.text = "no obj selected";
	else if (vars->obj == CAM)
		button.text = "cam selected";
	else if (vars->obj == LIGHT)
		button.text = "light selected";
	else if (vars->obj == SHAPE)
		button.text = "shape selected";
	make_box(vars, button, 0);
}

void	make_box(t_vars *vars, t_button button, int text_colour)
{
	int	x;
	int	y;

	y = button.by;
	while (y < button.ey)
	{
		x = button.bx;
		while (x < button.ex)
		{
			if (x == button.bx || y == button.by || x == button.ex - 1
				|| y == button.ey - 1)
				my_mlx_pixel_put(&(vars->img_copy), x, y, 0x000000);
			else
				my_mlx_pixel_put(&(vars->img_copy), x, y, button.colour);
			x++;
		}
		y++;
	}
	if (button.type == TEXT)
		display_text(vars, make_text(button, text_colour));
}
