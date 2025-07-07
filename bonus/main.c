/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbaj <akabbaj@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 16:31:28 by akabbaj           #+#    #+#             */
/*   Updated: 2025/07/07 16:31:31 by akabbaj          ###   ########.ch       */
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

int	handle_startup(int argc, char **argv)
{
	int	fd;

	if (argc != 2)
		return (print_error(NO_ARGS, 0, 0));
	if (!ext_check(argv[1]))
		return (print_error(INVALID_EXT, 0, 0));
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (print_error(NO_FILE, 0, 0));
	return (fd);
}

void	start_gen(t_gen *gen)
{
	gen->character = init_characters();
	gen->c->vector = vect_normalised(gen->c->vector);
	gen->saved_gen = copy_gen(gen);
	return ;
}

int	main(int argc, char **argv)
{
	t_gen	*gen;
	int		fd;

	fd = handle_startup(argc, argv);
	if (fd == -1)
		return (-1);
	gen = parse_file(fd, 0);
	flush_buffer(fd);
	close(fd);
	if (!gen)
		return (-1);
	if (gen->a->light == -1 || gen->c->fov == -1 || gen->l[0] == NULL)
	{
		free_gen(gen);
		return (print_error(INCOMP_ELEM, 0, 0));
	}
	start_gen(gen);
	if (!gen->saved_gen)
	{
		free_gen(gen);
		return (-1);
	}
	creating_window(gen);
	free_gen(gen);
	return (0);
}
