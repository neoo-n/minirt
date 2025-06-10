/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lighting.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbaj <akabbaj@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 13:57:49 by akabbaj           #+#    #+#             */
/*   Updated: 2025/06/10 13:57:49 by akabbaj          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"

double	calc_dif_int(t_shape *shape, t_gen *gen, t_coords ray, t_coords origin)
{
	t_coords	n;

	n = calc_norm(shape, ray, origin);
}

int	get_rgb(t_shape *shape, t_gen *gen, t_coords ray, t_coords origin)
{
	double	dif_int;

	dif_int = calc_dif_int(shape, gen, ray, origin);
	return (shape->rgb.r << 16 | shape->rgb.g << 8 | shape->rgb.b);
}
