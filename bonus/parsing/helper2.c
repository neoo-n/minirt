/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvauthey <dvauthey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 15:13:23 by dvauthey          #+#    #+#             */
/*   Updated: 2025/06/19 15:15:23 by dvauthey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

t_light	**realloc_light(t_light	**lights, t_light *new_light)
{
	int		len;
	int		i;
	t_light	**res;

	len = 0;
	while (lights[len])
		len++;
	res = ft_calloc(len + 2, sizeof(t_light *));
	if (!res)
		return (0);
	i = 0;
	while (lights[i])
	{
		res[i] = lights[i];
		i++;
	}
	res[i++] = new_light;
	res[i] = 0;
	free(lights);
	return (res);
}
