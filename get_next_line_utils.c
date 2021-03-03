/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malatini <malatini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 10:01:26 by malatini          #+#    #+#             */
/*   Updated: 2021/03/03 13:37:53 by malatini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*gnl_strjoin(char *s1, char *s2)
{
	char	*single;
	size_t	i;
	size_t	j;
	size_t	total_length;

	if (!s1 && !s2)
		return (NULL);
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
	free(s1);
	return (single);
}
