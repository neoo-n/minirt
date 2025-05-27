/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbaj <akabbaj@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 16:04:44 by akabbaj           #+#    #+#             */
/*   Updated: 2025/05/27 16:04:44 by akabbaj          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H
# include "gnl/get_next_line.h"
# include "../structures.h"

double	ft_atof(char *str);
double	ft_datoi(const char *nptr);
char	*ft_itoa(int n);

int		print_error(t_errmes mes, char *str, int i);

void	free_gen(t_gen *gen);
char	**free_strarr_char(char **tofree);
int		free_strarr(char **tofree);

void	ft_putstr_fd(char *s, int fd);
char	*ft_strdup(const char *s);
char	*ft_substr(const char *s, unsigned int start, size_t len);
int		ft_strncmp(const char *s1, const char *s2, size_t n);

int		wspace(char c);
char	**ft_split(char *s, char *set);

#endif