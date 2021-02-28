/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malatini <malatini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 09:22:55 by malatini          #+#    #+#             */
/*   Updated: 2021/02/28 11:47:56 by malatini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#define BUFFER_SIZE 25

void red() {
  printf("\033[1;31m");
}

void yellow() {
  printf("\033[1;33m");
}

void green()
{
	printf("\033[0;32m");
}

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
	int length;
	int i;

	if (!found_n(str))
		return ;
	i = found_n(str);
	length = ft_strlen(str);
	while (length-- > i)
		str[length] = '\0';
}

int		get_next_line(int fd, char **line)
{
	char		*buffer;
	char static *save;
	int			read_ret;

	(void)line;
	if (!(buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (ERROR);
	if (fd < 0 || !line || BUFFER_SIZE <= 0 || read(fd, buffer, 0) < 0)
		return (ERROR);
	while ((read_ret = read(fd, buffer, BUFFER_SIZE)) > 0)//!(found_n(save))
	{
		buffer[read_ret] = '\0';
		red();
		printf("Static : %s\n", save);
		yellow();
		printf("Buffer : %s\n", buffer);
		if (!(found_n(save)))
		{
			save = ft_strjoin(save, buffer);
			//red();
			//printf("Static update : %s\n", save);
		}
		else 
		{
			save = ft_better_strchr(save, '\n');
			green();
			printf("Static update n : %s\n", save);
			save = ft_strjoin(save, buffer);
			printf("Static update re joined : %s\n", save);
		}
	}
	free(buffer);
	return (read_ret);
}

int main(void)
{
	int fd = open("texte.txt", O_RDONLY);
	char *line = NULL;
	/* printf("%i\n", get_next_line(fd, &line));
	printf("%i\n", get_next_line(fd, &line)); */
	get_next_line(fd, &line);
	get_next_line(fd, &line);
	get_next_line(fd, &line);
	get_next_line(fd, &line);
	get_next_line(fd, &line);
	get_next_line(fd, &line);
	get_next_line(fd, &line);
	get_next_line(fd, &line);
	close(fd);
	return (0);
}
