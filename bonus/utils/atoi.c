/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbaj <akabbaj@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 16/06/2025 13:40:10 by akabbaj           #+#    #+#             */
/*   Updated: 16/06/2025 14:11:20 by akabbaj          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	digs(long n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		i++;
		n *= -1;
	}
	while (n > 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*res;
	int		dig;
	long	x;

	x = n;
	dig = digs(x);
	res = malloc(sizeof(char) * (dig + 1));
	if (!res)
		return (0);
	res[dig--] = 0;
	if (n == 0)
		res[0] = '0';
	if (x < 0)
	{
		res[0] = '-';
		x *= -1;
	}
	while (x > 0)
	{
		res[dig--] = (x % 10) + 48;
		x = x / 10;
	}
	return (res);
}

double	ft_datoi(const char *nptr)
{
	int		i;
	int		neg;
	double	result;

	result = 0;
	neg = 1;
	i = 0;
	while (wspace(nptr[i]))
		i++;
	if (nptr[i] == '-')
		neg = -1;
	if (nptr[i] == '-' || (nptr[i] == '+' && nptr[i + 1] != '-'))
		i++;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		result *= 10;
		result += (nptr[i++] - '0');
	}
	return (result * neg);
}

void	check_neg(char *str, int *i, int *neg)
{
	if (str[*i] == '-')
	{
		(*i)++;
		*neg = -1;
	}
}

double	ft_atof(char *str)
{
	int		i;
	int		j;
	double	n1;
	double	n2;
	int		neg;

	n1 = ft_datoi(str);
	i = 0;
	neg = 1;
	check_neg(str, &i, &neg);
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	if (str[i] != '.')
		return (n1);
	i++;
	j = i;
	n2 = ft_datoi(str + i);
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	if (neg == 1)
		n1 = n1 + (n2 / (pow(10, i - j)));
	else
		n1 = n1 - (n2 / (pow(10, i - j)));
	return (n1);
}
