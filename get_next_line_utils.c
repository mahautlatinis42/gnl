/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malatini <malatini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 10:01:26 by malatini          #+#    #+#             */
/*   Updated: 2021/02/25 19:55:24 by malatini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#define BUFFER_SIZE 10

size_t	ft_strlen(char *str)
{
	size_t i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_str_clean_dup(const char *s1)
{
	int		i;
	char	*cpy;

	i = 0;
	while (s1[i] && s1[i] != '\n')
		i++;
	if (!(cpy = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	i = 0;
	while (s1[i] && s1[i] != '\n')
	{
		cpy[i] = s1[i];
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*single;
	int		i;
	int		j;
	int		total_length;

	total_length = ft_strlen(s1) + ft_strlen(s2);
	if (!(single = (char *)malloc(sizeof(char) * (total_length + 1))))
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
	{
		single[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		single[i + j] = s2[j];
		j++;
	}
	single[i + j] = '\0';
	return (single);
}

//On ne veut pas faire de copie on veut modifier directement 
/*
char	*clean(char *buffer)
{
	char *clean_cpy;
	int length;
	int i;

	i = 0;
	length = 0;
	clean_cpy = NULL;
	while (buffer[length] && length < BUFFER_SIZE && buffer[length] != '\n')
		length++;
	if (!(clean_cpy = (char *)malloc(sizeof(char) * (length + 1))))
		return (NULL);
	while (i < length)
	{
		clean_cpy[i] = buffer[i];
		i++;
	}
	clean_cpy[i] = '\0';
	return (clean_cpy);
}
*/ 

/*
char	*excluded(char *str, char *clean)
{
	char *excluded;
	int length;
	int i;

	excluded = NULL;
	if (!(excluded = (char *)malloc(sizeof(char) * (ft_strlen(str) - ft_strlen(clean) + 1))))
		return (NULL);
	length = ft_strlen(clean);
	i = 0;
	while (str[length] && length < BUFFER_SIZE)
		excluded[i++] = str[length++];
	excluded[i++] = '\0';
	return (excluded);
}
*/