/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malatini <malatini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 09:22:55 by malatini          #+#    #+#             */
/*   Updated: 2021/02/25 15:48:28 by malatini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
int		find_next_end(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			break;
		i++;
	}
	return (i);
}
*/

int		get_next_line(int fd, char **line)
{
	//retourner une ligne lue depuis un file descriptor sans le retour a la ligne
	static int		count;
	char			*str;
	int				read_ret;

	(void)fd;
	(void)line;
	read_ret = 0;
	str = NULL;
	if (count == 0)
	{
		if (!(str = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1))))
			return (0);
	}
	else
		read_ret = read(fd, str, BUFFER_SIZE);
	printf("%d\n", read_ret);
	return (fd);
}

int main(void)
{
	int fd = open("texte.txt", O_RDONLY);
	int i = 0;
	char *line = NULL;
	while (i < 4)
	{
		get_next_line(fd, &line);
		i++;
	}
	close(fd);
	return (0);
}
