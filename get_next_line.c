/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malatini <malatini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 09:22:55 by malatini          #+#    #+#             */
/*   Updated: 2021/02/25 18:39:23 by malatini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#define BUFFER_SIZE 10

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

int		get_next_line(int fd, char **line)
{
	char			*str;
	char 			*store_excluded;
	int				read_ret;
	(void)fd;
	(void)line;
	if (!(str = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1))))
			return (0);
	read_ret = read(fd, str, BUFFER_SIZE);
	str[read_ret] = '\0';
	read_ret = read(fd, str, BUFFER_SIZE);
	str[read_ret] = '\0';
	return (fd);
}

int main(void)
{
	int fd = open("texte.txt", O_RDONLY);
	char *line = NULL;
	get_next_line(fd, &line);
	close(fd);
	return (0);
}
