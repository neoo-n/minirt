/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_helper.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbaj <akabbaj@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 21:26:44 by akabbaj           #+#    #+#             */
/*   Updated: 2025/07/03 21:34:46 by akabbaj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"

void	total_failure(t_vars *vars, int i, t_data tdata[8],
			pthread_t threads[8])
{
	int	j;

	j = 0;
	while (j < i)
	{
		thread_failure(tdata[j].vars);
		pthread_join(threads[j++], NULL);
	}
	error_exit_vars(vars, "Error creating threads", 0);
}

int	create_threads(int i, int step, t_vars *vars, t_data tdata[8])
{
	tdata[i].vars = deep_copy(vars);
	if (!tdata[i].vars)
		return (0);
	tdata[i].sx = i * step;
	if (i == 7)
		tdata[i].ex = vars->win_sizes.x_len;
	else
		tdata[i].ex = (i + 1) * step;
	return (1);
}
