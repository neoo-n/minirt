/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handling_light.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvauthey <dvauthey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 15:33:22 by dvauthey          #+#    #+#             */
/*   Updated: 2025/07/03 15:43:42 by dvauthey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static int	coords_parse(t_light *light, char *line, int *i)
{
	*i = next_elem(line, 0);
	if (!valid_coords(line + *i))
		return (0);
	ins_coords(line + *i, &light->coords);
	if (!light->coords.valid)
		return (0);
	return (1);
}

static int	bright_parse(t_light *light, char *line, int *i)
{
	*i = next_elem(line, *i);
	if (!(valid_double(line + *i) && ft_atof(line + *i) >= 0
			&& ft_atof(line + *i) <= 1))
		return (0);
	light->bright = ft_atof(line + *i);
	return (1);
}

static int	rgb_parse(t_light *light, char *line, int *i)
{
	*i = next_elem(line, *i);
	light->rgb.r = -1;
	if (!(line[*i] && line[*i] != '\n'))
		return (1);
	if (!valid_rgb(line + *i))
		return (0);
	ins_rgb(line + *i, &light->rgb);
	return (2);
}

int	handle_l(t_gen *gen, char *line, int i)
{
	t_light	*light;
	int		rgb;

	rgb = 0;
	light = malloc(sizeof(t_light));
	if (!light)
		return (0);
	if (!coords_parse(light, line, &i))
		return (0);
	if (!bright_parse(light, line, &i))
		return (0);
	rgb = rgb_parse(light, line, &i);
	if (rgb != 2)
		return (rgb);
	i = next_elem(line, i);
	if (line[i] && line[i] != '\n')
		return (0);
	gen->l = realloc_light(gen->l, light);
	if (!gen->l)
		return (free(light), 0);
	return (1);
}
