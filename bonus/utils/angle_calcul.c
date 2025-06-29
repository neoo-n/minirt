/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   angle_calcul.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvauthey <dvauthey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 15:48:41 by dvauthey          #+#    #+#             */
/*   Updated: 2025/06/29 16:11:40 by dvauthey         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

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
