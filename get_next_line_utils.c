/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malatini <malatini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 10:01:26 by malatini          #+#    #+#             */
/*   Updated: 2021/03/01 17:04:54 by malatini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_strlen(char *str)
{
	int i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strnjoin(char *s1, char *s2)
{
	char		*single;
	int			i;
	int			j;
	int			total_length;
	int			k;

	i = 0;
	k = 0;
	j = found_n(s2) > 0 ? found_n(s2) : ft_strlen(s2);
	total_length = ft_strlen(s1) + j;
	if (!(single = (char *)malloc(sizeof(char) * (total_length + 1))))
		return (NULL);
	while (i < ft_strlen(s1))
	{
		single[i] = s1[i];
		i++;
	}
	while (k < j)
	{
		single[i + k] = s2[k];
		k++;
	}
	single[i + k] = '\0';
	free(s1);
	return (single);
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

void	ft_bzero(void *s, size_t n)
{
	size_t i;

	i = 0;
	if (n == 0)
		return ;
	while (i < n)
		((char *)s)[i++] = '\0';
}

/*
char	*ft_better_strchr(char *s, int c)
{
	int		i;
	char	*str;

	i = 0;
	str = NULL;
	while (s[i] && s[i] != c)
		i++;
	if (c == s[i] || c == '\0')
		return (ft_strdup((char *)&s[i + 1]));
	return (NULL);
}
*/
