/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbaj <akabbaj@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 11:52:50 by akabbaj           #+#    #+#             */
/*   Updated: 2025/05/28 11:53:53 by akabbaj          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	print_error(t_errmes mes, char *str, int i)
{
	char	*num;

	if (mes == NO_FILE)
		ft_putstr_fd("Error\nFile not found.\n", 2);
	else if (mes == NO_ARGS)
		ft_putstr_fd("Error\nIncorrect amount of arguments.\n", 2);
	else if (mes == INVALID_EXT)
		ft_putstr_fd("Error\nInvalid file extension. Must be '.rt'.\n", 2);
	else if (mes == INCOMP_ELEM)
		ft_putstr_fd("Error\nMissing elements. At least A & C & L required.\n",
			2);
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

int	ext_check(char *argv)
{
	int	i;

	i = 0;
	while (argv[i])
		i++;
	if (i < 3)
		return (0);
	if (argv[i - 3] != '.' || argv[i - 2] != 'r' || argv[i - 1] != 't')
		return (0);
	return (1);
}
