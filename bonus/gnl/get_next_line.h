/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbaj <akabbaj@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 11:31:55 by akabbaj           #+#    #+#             */
/*   Updated: 2025/05/27 14:33:41 by akabbaj          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 60
# endif

char	*get_next_line(int fd);
int		in(char c, char	*str);
void	*ft_calloc(unsigned int nmemb, size_t size);
int		ft_strlen(const char *s);
char	*concat(char *s1, char *s2);
void	*free_return(void *tofree);

#endif
