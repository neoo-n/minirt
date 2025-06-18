/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbaj <akabbaj@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 11:21:36 by akabbaj           #+#    #+#             */
/*   Updated: 2025/06/18 11:24:29 by akabbaj          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	flush_buffer(int fd)
{
	char	*flush;

	flush = get_next_line(fd);
	while (flush)
	{
		free(flush);
		flush = get_next_line(fd);
	}
	return ;
}

int	main(int argc, char **argv)
{
	t_gen	*gen;
	int		fd;

	if (argc != 2)
		return (print_error(NO_ARGS, 0, 0));
	if (!ext_check(argv[1]))
		return (print_error(INVALID_EXT, 0, 0));
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (print_error(NO_FILE, 0, 0));
	gen = parse_file(fd, 0);
	flush_buffer(fd);
	close(fd);
	if (!gen)
		return (-1);
	if (gen->a->light == -1 || gen->c->fov == -1 || gen->l->bright == -1)
	{
		free_gen(gen);
		return (print_error(INCOMP_ELEM, 0, 0));
	}
	creating_window(gen);
	free_gen(gen);
	return (0);
}
