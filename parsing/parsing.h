/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbaj <akabbaj@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 16:01:18 by akabbaj           #+#    #+#             */
/*   Updated: 2025/05/27 16:01:24 by akabbaj          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H
# include "../structures.h"
# include "../gnl/get_next_line.h"
# include "../utils/utils.h"

int		handle_a(t_gen *gen, char *line);
int		handle_c(t_gen *gen, char *line);
int		handle_l(t_gen *gen, char *line);

int		handle_sp(t_gen *gen, char *line);
int		handle_pl(t_gen *gen, char *line);
int		handle_cy(t_gen *gen, char *line);

int		find_end(char *str);
int		next_elem(char *line, int i);
t_shape	**realloc_shape(t_shape **shapes, t_shape *new_shape);

t_gen	*parse_file(int fd);

void	ins_coords(char *str, t_coords *coords);
void	ins_rgb(char *str, t_rgb *rgb);

int		valid_line(char *line);
int		valid_ratio(char *str);
int		valid_rgb(char *str);
int		valid_double(char *str);
int		valid_coords(char *str);

#endif