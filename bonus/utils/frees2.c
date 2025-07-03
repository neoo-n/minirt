/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frees2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvauthey <dvauthey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 15:07:19 by dvauthey          #+#    #+#             */
/*   Updated: 2025/07/03 15:08:01 by dvauthey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	free_characters(t_character *character)
{
	t_character	*next;

	while (character)
	{
		next = character->next;
		free(character);
		character = next;
	}
}
