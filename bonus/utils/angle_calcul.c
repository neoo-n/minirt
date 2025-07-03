/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   angle_calcul.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbaj <akabbaj@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 03/07/2025 14:46:51 by akabbaj           #+#    #+#             */
/*   Updated: 03/07/2025 15:04:03 by akabbaj          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "math.h"

double	deg_to_rad(double angle)
{
	double	res;

	res = angle * PI / 180;
	return (res);
}

double	rad_to_deg(double angle)
{
	double	res;

	res = angle * 180 / PI;
	return (res);
}
