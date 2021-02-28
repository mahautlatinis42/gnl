/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malatini <malatini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 10:01:26 by malatini          #+#    #+#             */
/*   Updated: 2021/02/28 11:30:36 by malatini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

void	*ft_calloc(size_t count, size_t size)
{
	void *memory;

	if (!(memory = (void *)malloc(sizeof(size) * count)))
		return (NULL);
	ft_bzero(memory, count * size);
	return (memory);
}

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*cpy;

	i = 0;
	while (s1[i])
		i++;
	if (!(cpy = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	i = 0;
	while (s1[i])
	{
		cpy[i] = s1[i];
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}

int		ft_eol(char *str)
{
	int i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (0);
}

void	ft_bzero(void *s, size_t n)
{
	size_t i;

	i = 0;
	if (n == 0)
		return ;
	while (i < n)
		((char *)s)[i++] = '\0';
}

char	*ft_better_strchr(const char *s, int c)
{
	int i;
	char *str;

	i = 0;
	str = NULL;
	while (s[i] && s[i] != c)
		i++;
	if (c == s[i] || c == '\0')
		return (ft_strdup((char *)&s[i + 1]));
	return (NULL);
}