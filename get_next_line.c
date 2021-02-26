/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malatini <malatini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 09:22:55 by malatini          #+#    #+#             */
/*   Updated: 2021/02/26 14:12:49 by malatini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#define BUFFER_SIZE 10

int		line_is_ok(char *str)
{
	int length;

	length = ft_strlen(str) - 1;
	if (str[length] == '\n')
		return (1);
	return (0);
}


int		get_next_line(int fd, char **line)
{
	char		*buffer;
	char static *save;
	int			read_ret;
	//char		*tmp;

	(void)line;
	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	if (!(buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1))))
			return (-1);
	read_ret = read(fd, buffer, BUFFER_SIZE);
	buffer[read_ret] = '\0';
	save = ft_strjoin(save, buffer);
	free(buffer);
	printf("%s\n", save);
	return (read_ret);
}

int main(void)
{
	int fd = open("texte.txt", O_RDONLY);
	char *line = NULL;
	get_next_line(fd, &line);
	/*
	get_next_line(fd, &line);
	get_next_line(fd, &line);
	get_next_line(fd, &line);
	get_next_line(fd, &line);
	*/
	close(fd);
	return (0);
}
