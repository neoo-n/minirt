/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buttons.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbaj <akabbaj@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 10:24:41 by akabbaj           #+#    #+#             */
/*   Updated: 2025/06/27 10:24:41 by akabbaj          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "buttons.h"

void	display_text(t_vars *vars, t_text text, t_dataimg img)
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
		make_char(vars, letter, img);
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
	if (res.text[0] == '<' || res.text[0] == '>')
		res.x = button.bx + (button.ex - button.bx) * 0.35;
	res.y = button.by + ((button.ey - button.by) * 0.5) - res.size / 2;
	return (res);
}

void	make_menu(t_vars *vars, int line_colour, int i, t_dataimg img)
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
	make_box(vars, button, 0, img);
	length = (button.ex - button.bx) * 0.8;
	button.by = button.ey * 0.25;
	width = button.ey * 0.1;
	button.bx = button.bx + (length / 9);
	button.ex = button.bx + length;
	button.colour = line_colour;
	while (i < 3)
	{
		button.ey = button.by + width;
		make_box(vars, button, 0, img);
		button.by += width * 3;
		i++;
	}
}

void	make_arrows(t_vars *vars, int boxlength, int arrow, t_dataimg img)
{
	t_button	button;
	int			length;

	button.bx = vars->win_sizes.x_len - vars->win_sizes.x_len * 0.07;
	button.ex = vars->win_sizes.x_len - vars->win_sizes.x_len * 0.04;
	button.ey = vars->win_sizes.y_height * (1 - 0.0035);
	button.by = vars->win_sizes.y_height * (1 - 0.035);
	button.type = TEXT;
	button.colour = 0x9c9797;
	button.text = ">";
	if (arrow == 1 || arrow == 0)
		make_box(vars, button, 0, img);
	length = button.ex - button.bx;
	button.bx += -boxlength + length;
	button.ex += -boxlength + length;
	button.text = "<";
	if (arrow == -1 || arrow == 0)
		make_box(vars, button, 0, img);
}

void	make_box(t_vars *vars, t_button button, int text_colour, t_dataimg img)
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
				my_mlx_pixel_put(&(img), x, y, 0x000000);
			else
				my_mlx_pixel_put(&(img), x, y, button.colour);
			x++;
		}
		y++;
	}
	if (button.type == TEXT)
		display_text(vars, make_text(button, text_colour), img);
}
