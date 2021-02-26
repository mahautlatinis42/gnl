/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malatini <malatini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 10:01:26 by malatini          #+#    #+#             */
/*   Updated: 2021/02/26 14:14:36 by malatini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#define BUFFER_SIZE 10

size_t	ft_strlen(char *str)
{
	size_t i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*single;
	size_t		i;
	size_t		j;
	int		total_length;

	total_length = ft_strlen(s1) + ft_strlen(s2);
	if (!(single = (char *)malloc(sizeof(char) * (total_length + 1))))
		return (NULL);
	i = 0;
	j = 0;
	while (i < ft_strlen(s1))
	{
		single[i] = s1[i];
		i++;
	}
	while (j < ft_strlen(s2))
	{
		single[i + j] = s2[j];
		j++;
	}
	single[i + j] = '\0';
	return (single);
}

void	*ft_memmove(void *dst, void *src, size_t len)
{
	const char	*s;
	char		*d;
	size_t		i;

	s = (const char *)src;
	d = (char *)dst;
	if (!d && !s)
		return (NULL);
	i = 0;
	if (d < s)
		while (len--)
		{
			d[i] = s[i];
			i++;
		}
	else
		while (len--)
			d[len] = s[len];
	return ((void *)dst);
}