/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbaj <akabbaj@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 09:52:39 by akabbaj           #+#    #+#             */
/*   Updated: 2025/06/20 14:45:45 by akabbaj          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

// void	print_gen(t_gen	*gen)
// {
// 	int	i;

// 	printf("Ambient Lighting\nLighting Ratio: %f\nRGB: %f,%f,%f\n\n", gen->a->light, gen->a->rgb.r, gen->a->rgb.g, gen->a->rgb.b);
// 	printf("Camera\nCoords: %f,%f,%f\nVector: %f,%f,%f\nFOV: %f\n\n", gen->c->coords.x, gen->c->coords.y, gen->c->coords.z, gen->c->vector.x, gen->c->vector.y, gen->c->vector.z, gen->c->fov);
// 	i = 0;
// 	while (gen->l[i])
// 	{
// 		printf("Light %i\nCoords: %f,%f,%f\nBrightness: %f\n", i, gen->l[i]->coords.x, gen->l[i]->coords.y, gen->l[i]->coords.z, gen->l[i]->bright);
// 		if (gen->l[i]->rgb.r != -1)
// 			printf("RGB: %f,%f,%f\n",gen->l[i]->rgb.r, gen->l[i]->rgb.g, gen->l[i]->rgb.b);
// 		i++;
// 	}
// 		printf("\n");
// 	i = 0;
// 	while (gen->shapes[i])
// 	{
// 		printf("ID: %d\nCoords: %f,%f,%f\n", gen->shapes[i]->shape, gen->shapes[i]->coords.x, gen->shapes[i]->coords.y, gen->shapes[i]->coords.z);
// 		if (gen->shapes[i]->shape == SPHERE || gen->shapes[i]->shape == CYLINDER)
// 			printf("Diameter: %f\n", gen->shapes[i]->diam);
// 		if (gen->shapes[i]->shape == CYLINDER)
// 			printf("Height: %f\n", gen->shapes[i]->height);
// 		if (gen->shapes[i]->shape == CYLINDER || gen->shapes[i]->shape == PLANE)
// 			printf("Vector: %f,%f,%f\n", gen->shapes[i]->vector.x, gen->shapes[i]->vector.y, gen->shapes[i]->vector.z);
// 		printf("RGB: %f,%f,%f\n\n", gen->shapes[i]->rgb.r, gen->shapes[i]->rgb.g, gen->shapes[i]->rgb.b);
// 		i++;
// 	}	
// }

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
	if (gen->a->light == -1 || gen->c->fov == -1 || gen->l[0] == NULL)
	{
		free_gen(gen);
		return (print_error(INCOMP_ELEM, 0, 0));
	}
	gen->character = init_characters();
	creating_window(gen);
	free_gen(gen);
	return (0);
}
