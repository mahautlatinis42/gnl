/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malatini <malatini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 09:22:55 by malatini          #+#    #+#             */
/*   Updated: 2021/02/26 15:48:09 by malatini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#define BUFFER_SIZE 100

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

void	erase_after_n(char *str)
{
	//Je ne modifie pas la string
	int length;
	int i;

	if (!found_n(str))
		return ;
	i = found_n(str);
	length = ft_strlen(str);
	while (length-- > i)
		str[length] = '\0';
}

//Maintenant je veux que ma save s arrete au \n sinon je veux passer a la ligne suivante.
//Je dois boucler en lisant sur le file descriptor pour arriver a la fin de ma liste.
int		get_next_line(int fd, char **line)
{
	char		*buffer;
	char static *save;
	int			read_ret;

	(void)line;
	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	if (!(buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1))))
			return (-1);
	while (!found_n(save))
	{
		read_ret = read(fd, buffer, BUFFER_SIZE);
		buffer[read_ret] = '\0';
		save = ft_strjoin(save, buffer);	
	}
	printf("Pas propre : %s\n", save);
	erase_after_n(save);
	free(buffer);
	printf("Propre : %s\n", save);
	//Comment je retiens pour la suivante du coup ?
	return (read_ret);
}

int main(void)
{
	int fd = open("texte.txt", O_RDONLY);
	char *line = NULL;
	get_next_line(fd, &line);
	/*
	Je reste bloquee sur une seul ligne
	get_next_line(fd, &line);
	get_next_line(fd, &line);
	get_next_line(fd, &line);
	get_next_line(fd, &line);
	*/
	close(fd);
	return (0);
}
