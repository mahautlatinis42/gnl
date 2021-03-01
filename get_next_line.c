/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malatini <malatini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 09:22:55 by malatini          #+#    #+#             */
/*   Updated: 2021/03/01 16:15:24 by malatini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#define BUFFER_SIZE 10

int		get_next_line(int fd, char **line)
{
	static char save[OPEN_MAX][BUFFER_SIZE + 1];
	int			read_ret;
	int			found;
	int			i;

	i = 0;
	line[i] = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0 || fd > OPEN_MAX
			|| read(fd, save[OPEN_MAX], 0) < 0)
		return (ERROR);
	read_ret = read(fd, save, BUFFER_SIZE);
	while ((found = ft_better_strchr(save, '\n')) < 0)
	{
		i++;
		printf("Je cherche %i\n", i);
	}
	printf("Trouve\n");
	return (read_ret);
}

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("texte.txt", O_RDONLY);
	line = NULL;
	get_next_line(fd, &line);
	get_next_line(fd, &line);
	close(fd);
	return (0);
}
