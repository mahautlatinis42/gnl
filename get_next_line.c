/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malatini <malatini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 09:22:55 by malatini          #+#    #+#             */
/*   Updated: 2021/03/01 17:14:53 by malatini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#define BUFFER_SIZE 5

int		found_n(char *str)
{
	int i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (0);
}

char	*save_new(char *save)
{
	char *new;
	int i;
	int j;

	i = 0;
	j = 0;
	new = NULL;
	while (save[i] && save[i] != '\n')
		i++;
	if (save[i] == '\0')
	{
		i++;
		while (save[i])
		{
			new[j] = save[i];
			i++;
			j++;
		}
		new[j] = '\0';
	}
	return (new);
}

int		get_next_line(int fd, char **line)
{
	static char save[OPEN_MAX][BUFFER_SIZE + 1];
	int			read_ret;
	int			found;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > OPEN_MAX || !line)
		return (ERROR);
	//line = NULL;
	while ((found = found_n(save[fd])) <= 0)
	{
		read_ret = read(fd, save[fd], BUFFER_SIZE);
		save[fd][read_ret] = '\0';
		//printf("%s\n", save[fd]);
		*line = ft_strnjoin(*line, save[fd]);
		printf("%s\n", *line);
		if (found_n(save[fd]))
		{
			save_new(save[fd]);
			//Pas bon, a revoir
			printf("Test : %s\n", save[fd]);
		}

		//meme au premier appel je fais un join
		//tant que je n ai pas de \n
		//je vais concatener dans line
		//quand j en trouve je conccatene jusqu au \n
		// je vais nettoyer ma static pour enlever ce que je ne veux pas garder
		//je vais faire une copie a partir du cara
	}
	return (read_ret);
}

int	main(void)
{
	int		fd;
	char	*line;

	line = NULL;
	fd = open("texte.txt", O_RDONLY);
	get_next_line(fd, &line);
	//get_next_line(fd, &line);
	close(fd);
	return (0);
}
