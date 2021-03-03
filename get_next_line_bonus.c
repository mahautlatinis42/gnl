/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malatini <malatini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 15:33:42 by malatini          #+#    #+#             */
/*   Updated: 2021/03/03 15:44:34 by malatini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int		ft_hasnewline(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*ft_newline(char *s)
{
	char	*new_line;
	int		i;

	if (!s)
		return (NULL);
	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	if (!(new_line = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	i = 0;
	while (s[i] && s[i] != '\n')
	{
		new_line[i] = s[i];
		i++;
	}
	new_line[i] = '\0';
	return (new_line);
}

char	*ft_prep_s(char *s)
{
	int		i;
	int		j;
	char	*clean_s;

	if (!s)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i] != '\n' && s[i])
		i++;
	if (!s[i])
	{
		free(s);
		return (NULL);
	}
	if (!(clean_s = (char *)malloc(sizeof(char) * (ft_strlen(s) - i + 1))))
		return (NULL);
	i++;
	while (s[i])
		clean_s[j++] = s[i++];
	clean_s[j] = '\0';
	free(s);
	return (clean_s);
}

int		get_next_line(int fd, char **line)
{
	static char *s[OPEN_MAX];
	int			b_read;
	char		*buffer;

	if (fd < 0 || BUFFER_SIZE < 1 || fd > OPEN_MAX || !line)
		return (ERROR);
	if (!(buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (ERROR);
	b_read = BUFFER_SIZE;
	while (b_read != 0 && !(ft_hasnewline(s[fd])))
	{
		if ((b_read = read(fd, buffer, BUFFER_SIZE)) == -1)
		{
			free(buffer);
			return (ERROR);
		}
		buffer[b_read] = '\0';
		s[fd] = gnl_strjoin(s[fd], buffer);
	}
	free(buffer);
	*line = ft_newline(s[fd]);
	s[fd] = ft_prep_s(s[fd]);
	if (b_read == 0)
		return (DONE);
	return (SUCCESS);
}