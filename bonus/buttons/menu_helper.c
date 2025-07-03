/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_helper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbaj <akabbaj@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 14:52:33 by akabbaj           #+#    #+#             */
/*   Updated: 2025/07/03 14:52:33 by akabbaj          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "buttons.h"

int	get_shapenum(t_vars *vars, t_id shape, int caller)
{
	int	i;
	int	count;

	i = 0;
	count = 1;
	if (caller)
	{
		while (i < vars->shape_count)
		{
			if (vars->gen->shapes[i]->shape == shape)
				count++;
			i++;
		}
	}
	else
	{
		while (i < vars->obj_id - count_lights(vars) - 1)
		{
			if (vars->gen->shapes[i]->shape == shape)
				count++;
			i++;
		}
	}
	return (count);
}

char	*ft_strjoin(char const *s1, char const*s2)
{
	int		l1;
	int		l2;
	char	*result;
	int		i;
	int		j;

	l1 = ft_strlen(s1);
	l2 = ft_strlen(s2);
	result = malloc(sizeof(char) * (l1 + l2 + 1));
	if (!result)
		return (NULL);
	i = -1;
	j = -1;
	while (s1[++i])
		result[i] = s1[i];
	while (s2[++j])
		result[i++] = s2[j];
	result[i] = 0;
	return (result);
}

void	shape_text(t_vars *vars, t_button *button, char **num)
{
	char		*text;

	(*num) = ft_itoa(get_shapenum(vars,
				vars->gen->shapes[vars->obj_id
				- count_lights(vars) - 1]->shape, 0));
	if (vars->gen->shapes[vars->obj_id - count_lights(vars) - 1]->shape
		== CYLINDER)
		text = ft_strjoin("cylinder ", (*num));
	else if (vars->gen->shapes[vars->obj_id - count_lights(vars) - 1]->shape
		== SPHERE)
		text = ft_strjoin("sphere ", (*num));
	else if (vars->gen->shapes[vars->obj_id - count_lights(vars) - 1]->shape
		== PLANE)
		text = ft_strjoin("plane ", (*num));
	else if (vars->gen->shapes[vars->obj_id - count_lights(vars) - 1]->shape
		== CONE)
		text = ft_strjoin("cone ", (*num));
	free((*num));
	(*num) = ft_strjoin(text, " selected");
	(*button).text = (*num);
	free(text);
}

void	light_text(t_vars *vars, t_button *button, char **num)
{
	char	*text;

	(*num) = ft_itoa(vars->obj_id);
	text = ft_strjoin("light ", (*num));
	free((*num));
	(*num) = ft_strjoin(text, " selected");
	free(text);
	(*button).text = (*num);
}
