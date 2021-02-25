/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malatini <malatini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 09:22:55 by malatini          #+#    #+#             */
/*   Updated: 2021/02/25 10:33:02 by malatini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(int fd, char **line)
{
	int 	i;
	//void	*buf;

	i = 0;
	if (fd > 0 && !line && !(*line))
		return (0);
	while (i < 3)
	{	
		printf("%s\n", line[i]);
		i++;
	}
	//read(fd, buf, BUFFER_SIZE);
	return (fd);
}

int main(void)
{
	//Pour ouvrir un fichier on va declarer un pointeur vers un flux 
	fopen("./texte.txt", r);
	//get_next_line(1, str);
	fclose();
	return (0);
}
