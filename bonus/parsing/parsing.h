/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbaj <akabbaj@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 09:53:58 by akabbaj           #+#    #+#             */
/*   Updated: 2025/06/30 20:31:33 by akabbaj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H
# include "../structures.h"
# include "../gnl/get_next_line.h"
# include "../utils/utils.h"
# include "../buttons/buttons.h"

int		parse_coords(char *line, int i, t_coords *coords);
int		parse_double(char *line, int i, double *value);
int		parse_rgb(char *line, int i, t_rgb *rgb);

int		handle_a(t_gen *gen, char *line);
int		handle_c(t_gen *gen, char *line);
int		handle_l(t_gen *gen, char *line, int i);

int		handle_sp(t_gen *gen, char *line, int i);
int		handle_pl(t_gen *gen, char *line, int i);
int		handle_cts(t_gen *gen, char *line, int i);

int		is_numeric(char *str);
int		arr_len(char **arr);
int		find_end(char *str);
int		next_elem(char *line, int i);
t_shape	**realloc_shape(t_shape **shapes, t_shape *new_shape);
t_light	**realloc_light(t_light	**lights, t_light *new_light);

t_gen	*parse_file(int fd, int i);

void	ins_coords(char *str, t_coords *coords);
void	ins_rgb(char *str, t_rgb *rgb);
t_gen	*copy_gen(t_gen *o_gen);

int		valid_line(char *line);
int		valid_ratio(char *str);
int		valid_rgb(char *str);
int		valid_double(char *str);
int		valid_coords(char *str);

int		shape_len(t_shape **o_shape);
void	check_copy(t_gen *res, int copy);
t_gen	*handle_err(t_errmes mes, char *line, int i, t_gen *res);
int		init_elem(t_gen *gen, char *line);

#endif