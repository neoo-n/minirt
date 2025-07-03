/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handling.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvauthey <dvauthey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 16:13:00 by akabbaj           #+#    #+#             */
/*   Updated: 2025/07/03 15:33:50 by dvauthey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	handle_a(t_gen *gen, char *line)
{
	int	i;

	if (gen->a->light != -1)
		return (0);
	i = next_elem(line, 0);
	if (!(valid_ratio(line + i) && ft_atof(line + i) >= 0
			&& ft_atof(line + i) <= 1))
		return (0);
	gen->a->light = ft_atof(line + i);
	i = next_elem(line, i);
	if (!valid_rgb(line + i))
		return (0);
	ins_rgb(line + i, &gen->a->rgb);
	if (gen->a->rgb.r == -1)
		return (0);
	i = next_elem(line, i);
	if (line[i] && line[i] != '\n')
		return (0);
	return (1);
}

int	handle_c(t_gen *gen, char *line)
{
	int	i;

	if (gen->c->fov != -1)
		return (0);
	i = next_elem(line, 0);
	if (!valid_coords(line + i))
		return (0);
	ins_coords(line + i, &gen->c->coords);
	if (!gen->c->coords.valid)
		return (0);
	i = next_elem(line, i);
	if (!valid_coords(line + i))
		return (0);
	ins_coords(line + i, &gen->c->vector);
	if (gen->c->vector.valid != 1)
		return (0);
	i = next_elem(line, i);
	if (!(valid_double(line + i) && ft_atof(line + i) >= 0
			&& ft_atof(line + i) <= 180))
		return (0);
	gen->c->fov = ft_atof(line + i);
	i = next_elem(line, i);
	if (line[i] && line[i] != '\n')
		return (0);
	return (1);
}
