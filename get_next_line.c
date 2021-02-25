/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malatini <malatini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 09:22:55 by malatini          #+#    #+#             */
/*   Updated: 2021/02/25 17:28:38 by malatini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#define BUFFER_SIZE 100

int		get_next_line(int fd, char **line)
{
	//retourner une ligne lue depuis un file descriptor sans le retour a la ligne
	//static int		count;
	char			str[BUFFER_SIZE + 1];
	int				read_ret;
	(void)fd;
	(void)line;
	/*
	if (!(str = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1))))
			return (0);
	*/
	read_ret = read(fd, str, BUFFER_SIZE);
	str[read_ret] = '\0';
	printf("%s\n", str);
	/*
	while ((read_ret = read(fd, str, BUFFER_SIZE) != 0))
	{
		str[read_ret] = '\0';
		//printf("%d\n", read_ret);
		printf("%s\n", str);
	}
	*/
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
