/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbaj <akabbaj@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 16:38:37 by dvauthey          #+#    #+#             */
/*   Updated: 2025/06/30 20:36:10 by akabbaj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"

t_rgb	init_rgb(void)
{
	t_rgb	res;
	res.r = 0;
	res.g = 0;
	res.b = 0;
	return (res);
}

t_rgb	rgb_sum(t_rgb l1, t_rgb l2)
{
	t_rgb res;

	res.r = l1.r + l2.r;
	res.g = l1.g + l2.g;
	res.b = l1.b + l2.b;
	return (res);
}

t_rgb	norm_rgb(t_rgb rgb)
{
	rgb.r = rgb.r / 255;
	rgb.g = rgb.g / 255;
	rgb.b = rgb.b / 255;
	return (rgb);
}

t_rgb	rgb_mult(t_rgb rgb, double mult)
{
	t_rgb	res;

	res.r = rgb.r * mult;
	res.g = rgb.g * mult;
	res.b = rgb.b * mult;
	return (res);
}

t_rgb	rgb_final(t_rgb rgb, t_rgb amb, t_rgb dif, t_rgb spec)
{
	rgb.r = fmin(rgb.r * (amb.r + dif.r) + spec.r, 1);
	rgb.g = fmin(rgb.g * (amb.g + dif.g) + spec.g, 1);
	rgb.b = fmin(rgb.b * (amb.b + dif.b) + spec.b, 1);
	return (rgb);
}
