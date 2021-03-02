/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malatini <malatini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 09:22:55 by malatini          #+#    #+#             */
/*   Updated: 2021/03/02 12:31:26 by malatini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

//a revoir
char	*clean_end(char *save, char **line)
{
	int i;
	int j;

	i = ft_strichr(save, '\n') + 1;
	j = 0;
	while (save[i])
		j++;
	if (!(*line = (char *)malloc(sizeof(char) * (j + 1))))
		return (NULL);
	j = 0;
	while (save[i])
	{
		*line[j] = save[i];
		i++;
		j++;
	}
	*line[j] = '\0';
	return (*line);
}

int		get_next_line(int fd, char **line)
{
	static char save[OPEN_MAX][BUFFER_SIZE + 1];
	int			read_ret;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > OPEN_MAX || !line)
		return (ERROR);
	*line = NULL;
	while (ft_strichr(save[fd], '\n') < 0)
	{
		if ((*line = ft_strnjoin(*line, save[fd])) == NULL)
			return (ERROR);
		if ((read_ret = read(fd, save[fd], BUFFER_SIZE)) < 0)
			return (ERROR);
		if (read_ret < BUFFER_SIZE )
		{
			//a revoir
			clean_end(save[fd], line);
			printf("Dernier buffer: %s\n", save[fd]);
			printf("Derniere ligne: %s\n-fin", *line);
			return (DONE);
		}
		save[fd][read_ret] = '\0';
	}
	if ((*line = ft_strnjoin(*line, save[fd])) == NULL)
		return (ERROR);
	save_new(save[fd]);
	return (SUCCESS);
}

int     main(void)
{
    int     fd;
    char    *line;

    line = NULL;
    fd = open("alphabet.txt", O_RDONLY);
    get_next_line(fd, &line);
    get_next_line(fd, &line);
    get_next_line(fd, &line);
    get_next_line(fd, &line);
    printf("%i\n", get_next_line(fd, &line));
    close(fd);
    return (0);
}
