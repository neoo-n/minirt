/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvauthey <dvauthey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
<<<<<<< HEAD
/*   Created: 2025/06/26 09:54:09 by akabbaj           #+#    #+#             */
/*   Updated: 2025/06/26 09:54:09 by akabbaj          ###   ########.ch       */
=======
/*   Created: 2025/06/09 14:33:56 by akabbaj           #+#    #+#             */
/*   Updated: 2025/06/29 16:11:47 by dvauthey         ###   ########.fr       */
>>>>>>> new_forms
/*                                                                            */
/******************************************************************************/

#ifndef UTILS_H
# define UTILS_H
# include "gnl/get_next_line.h"
# include "../structures.h"
# include <math.h>
# define PI 3.14159265358979323846

double	deg_to_rad(double angle);
double	rad_to_deg(double angle);

double	ft_atof(char *str);
double	ft_datoi(const char *nptr);
char	*ft_itoa(int n);

int		print_error(t_errmes mes, char *str, int i);
int		ext_check(char *argv);

void	free_gen(t_gen *gen);
char	**free_strarr_char(char **tofree);
int		free_strarr(char **tofree);
int		free_strarr_str(char **tofree, char *strtofree, int i);
void	free_characters(t_character *character);

void	ft_putstr_fd(char *s, int fd);
char	*ft_strdup(const char *s);
char	*ft_substr(const char *s, unsigned int start, size_t len);
int		ft_strncmp(const char *s1, const char *s2, size_t n);

int		wspace(char c);
char	**ft_split(char *s, char *set);

#endif