/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbaj <akabbaj@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 15:59:28 by akabbaj           #+#    #+#             */
/*   Updated: 2025/05/27 15:59:28 by akabbaj          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	ft_putstr_fd(char *s, int fd)
{
	size_t	i;

	if (!s)
		return ;
	i = 0;
	while (s[i])
		i++;
	write (fd, s, i);
}

char	*ft_strdup(const char *s)
{
	int			size;
	int			i;
	char		*result;

	i = 0;
	size = ft_strlen(s);
	if (size == 0)
		return (ft_calloc(1, 1));
	result = malloc(size + 1);
	if (!result)
		return (0);
	while (i < size)
	{
		result[i] = s[i];
		i++;
	}
	result[i] = 0;
	return (result);
}

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	size_t			i;
	unsigned int	x;
	char			*substr;

	i = 0;
	x = ft_strlen(s);
	if (start >= x)
		return (ft_strdup(""));
	while (s[start + i] && i < len)
		i++;
	substr = (char *)malloc(sizeof(char) * (i + 1));
	if (!substr)
		return (NULL);
	i = 0;
	while (s[start + i] && i < len)
	{
		substr[i] = s[start + i];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (s1[i] && i < n && s1[i] == s2[i])
		i++;
	if (i < n)
		return ((unsigned char) s1[i] - (unsigned char) s2[i]);
	return (0);
}
