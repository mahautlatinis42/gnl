/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malatini <malatini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 10:01:26 by malatini          #+#    #+#             */
/*   Updated: 2021/03/02 17:12:04 by malatini         ###   ########.fr       */
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
	j = ft_strichr(s2, '\n') > 0 ? ft_strichr(s2, '\n') : ft_strlen(s2);
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

int		ft_strichr(char *s, char c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

char	*save_new(char *save)
{
	int		i;
	int		j;
	char	*cpy;

	cpy = ft_strdup(save);
	i = 0;
	j = 0;
	while (cpy[i] != '\n')
		i++;
	i++;
	while (cpy[i])
	{
		save[j] = cpy[i];
		i++;
		j++;
	}
	save[j] = '\0';
	free(cpy);
	return (save);
}
