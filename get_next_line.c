/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malatini <malatini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 09:22:55 by malatini          #+#    #+#             */
/*   Updated: 2021/02/25 20:06:08 by malatini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#define BUFFER_SIZE 10

char	*save_stock(char *buf)
{
	int		i;
	int		j;
	int		beg;
	char	*s;

	i = 0;
	while (buf[i] && buf[i] != '\n')
		i++;
	beg = i;
	while (buf[i])
		i++;
	if (!(s = (char *)malloc(sizeof(char) * (i - beg + 1))))
		return (NULL);
	j = 0;
	while (buf[beg])
	{
		s[j] = buf[beg];
		j++;
		beg++;
	}
	s[j] = '\0';
	return (s);
}

int		get_next_line(int fd, char **line)
{
	char	*buf;
	int		read_ret;
	int		i;
	static int count;
	char	*stock;

	i = 0;
	if (!(buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1))))
			return (0);
	read_ret = read(fd, buf, BUFFER_SIZE);
	printf("%s\n", buf);
	buf[read_ret] = '\0';
	//la première fois c est vide
	printf("%s\n", line[count] = ft_str_clean_dup(buf));
	//la deuxieme fois je dois boucler en concaténant
	count++;
	printf("Stock: %s\n", stock = save_stock(buf));
	read_ret = read(fd, buf, BUFFER_SIZE);
	buf[read_ret] = '\0';
	//printf("%s\n", line[count] = ft_str_clean_dup(buf));
	return (fd);
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
	*/
	close(fd);
	return (0);
}
