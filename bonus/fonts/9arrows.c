/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   9arrows.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbaj <akabbaj@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 15:14:01 by akabbaj           #+#    #+#             */
/*   Updated: 2025/06/29 12:55:31 by akabbaj          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "fonts.h"

void	init_9(int nine[7][5])
{
	init_char(nine);
	nine[0][0] = 1;
	nine[0][1] = 1;
	nine[0][2] = 1;
	nine[0][3] = 1;
	nine[0][4] = 1;
	nine[1][0] = 1;
	nine[1][4] = 1;
	nine[2][0] = 1;
	nine[2][4] = 1;
	nine[3][0] = 1;
	nine[3][1] = 1;
	nine[3][2] = 1;
	nine[3][3] = 1;
	nine[3][4] = 1;
	nine[4][4] = 1;
	nine[5][4] = 1;
	nine[6][0] = 1;
	nine[6][1] = 1;
	nine[6][2] = 1;
	nine[6][3] = 1;
	nine[6][4] = 1;
	return ;
}

void	init_l_arrow(int larrow[7][5])
{
	init_char(larrow);
	larrow[1][2] = 1;
	larrow[2][1] = 1;
	larrow[3][0] = 1;
	larrow[3][1] = 1;
	larrow[3][2] = 1;
	larrow[3][3] = 1;
	larrow[3][4] = 1;
	larrow[4][1] = 1;
	larrow[5][2] = 1;
	return ;
}

void	init_r_arrow(int rarrow[7][5])
{
	init_char(rarrow);
	rarrow[1][2] = 1;
	rarrow[2][3] = 1;
	rarrow[3][0] = 1;
	rarrow[3][1] = 1;
	rarrow[3][2] = 1;
	rarrow[3][3] = 1;
	rarrow[3][4] = 1;
	rarrow[4][3] = 1;
	rarrow[5][2] = 1;
	return ;
}