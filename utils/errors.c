/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbaj <akabbaj@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 17:22:05 by akabbaj           #+#    #+#             */
/*   Updated: 2025/05/27 17:22:05 by akabbaj          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	print_error(t_errmes mes, char *str, int i)
{
	char	*num;

	if (mes == NO_FILE)
		ft_putstr_fd("Error\nFile not found\n", 2);
	else if (mes == NO_ARGS)
		ft_putstr_fd("Error\nIncorrect amount of arguments\n", 2);
	else if (mes == PARSE_ERR)
	{
		ft_putstr_fd("Error\nParsing error on line: ", 2);
		num = ft_itoa(i);
		ft_putstr_fd(num, 2);
		ft_putstr_fd(": ", 2);
		ft_putstr_fd(str, 2);
		ft_putstr_fd("\n", 2);
		free(num);
	}
	return (-1);
}
