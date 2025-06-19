/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   z0123.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbaj <akabbaj@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 17:00:25 by akabbaj           #+#    #+#             */
/*   Updated: 2025/06/18 20:44:07 by akabbaj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fonts.h"

void	init_z(int z[7][5])
{
	init_char(z);
	z[0][0] = 1;
	z[0][1] = 1;
	z[0][2] = 1;
	z[0][3] = 1;
	z[0][4] = 1;
	z[1][4] = 1;
	z[2][3] = 1;
	z[3][2] = 1;
	z[4][1] = 1;
	z[5][0] = 1;
	z[6][0] = 1;
	z[6][1] = 1;
	z[6][2] = 1;
	z[6][3] = 1;
	z[6][4] = 1;
	return ;
}

void	init_0(int zero[7][5])
{
	init_char(zero);
	zero[0][0] = 1;
	zero[0][1] = 1;
	zero[0][2] = 1;
	zero[0][3] = 1;
	zero[0][4] = 1;
	zero[1][0] = 1;
	zero[1][4] = 1;
	zero[2][0] = 1;
	zero[2][4] = 1;
	zero[3][0] = 1;
	zero[3][4] = 1;
	zero[4][0] = 1;
	zero[4][4] = 1;
	zero[5][0] = 1;
	zero[5][4] = 1;
	zero[6][0] = 1;
	zero[6][1] = 1;
	zero[6][2] = 1;
	zero[6][3] = 1;
	zero[6][4] = 1;
	return ;
}

void	init_1(int one[7][5])
{
	init_char(one);
	one[0][2] = 1;
	one[1][1] = 1;
	one[1][2] = 1;
	one[2][0] = 1;
	one[2][2] = 1;
	one[3][2] = 1;
	one[4][2] = 1;
	one[5][2] = 1;
	one[6][0] = 1;
	one[6][1] = 1;
	one[6][2] = 1;
	one[6][3] = 1;
	one[6][4] = 1;
	return ;
}

void	init_2(int two[7][5])
{
	init_char(two);
	two[0][0] = 1;
	two[0][1] = 1;
	two[0][2] = 1;
	two[0][3] = 1;
	two[0][4] = 1;
	two[1][4] = 1;
	two[2][4] = 1;
	two[3][1] = 1;
	two[3][2] = 1;
	two[3][3] = 1;
	two[3][4] = 1;
	two[4][0] = 1;
	two[5][0] = 1;
	two[6][0] = 1;
	two[6][1] = 1;
	two[6][2] = 1;
	two[6][3] = 1;
	two[6][4] = 1;
	return ;
}

void	init_3(int three[7][5])
{
	init_char(three);
	three[0][0] = 1;
	three[0][1] = 1;
	three[0][2] = 1;
	three[0][3] = 1;
	three[0][4] = 1;
	three[1][4] = 1;
	three[2][4] = 1;
	three[3][0] = 1;
	three[3][1] = 1;
	three[3][2] = 1;
	three[3][3] = 1;
	three[3][4] = 1;
	three[4][4] = 1;
	three[5][4] = 1;
	three[6][0] = 1;
	three[6][1] = 1;
	three[6][2] = 1;
	three[6][3] = 1;
	three[6][4] = 1;
	return ;
}
