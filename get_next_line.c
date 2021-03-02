/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malatini <malatini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 09:22:55 by malatini          #+#    #+#             */
/*   Updated: 2021/03/02 09:16:50 by malatini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#define BUFFER_SIZE 100000000

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

int		get_next_line(int fd, char **line)
{
	static char save[OPEN_MAX][BUFFER_SIZE + 1];
	int			read_ret;

	*line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0 || fd > OPEN_MAX || !line)
		return (ERROR);
	while (ft_strichr(save[fd], '\n') < 0)
	{
		*line = ft_strnjoin(*line, save[fd]);
		read_ret = read(fd, save[fd], BUFFER_SIZE);
		save[fd][read_ret] = '\0';
	}
	*line = ft_strnjoin(*line, save[fd]);
	save_new(save[fd]);
	return (read_ret);
}

int		main(void)
{
	int		fd;
	char	*line;

	line = NULL;
	fd = open("texte.txt", O_RDONLY);
	get_next_line(fd, &line);
	get_next_line(fd, &line);
	get_next_line(fd, &line);
	get_next_line(fd, &line);
	get_next_line(fd, &line);
	close(fd);
	return (0);
}
