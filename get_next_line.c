/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malatini <malatini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 09:22:55 by malatini          #+#    #+#             */
/*   Updated: 2021/03/02 17:13:05 by malatini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
		save[fd][read_ret] = '\0';
		if (read_ret < BUFFER_SIZE)
			return ((read_ret == 0) ? DONE : SUCCESS);
	}
	if ((*line = ft_strnjoin(*line, save[fd])) == NULL)
		return (ERROR);
	save_new(save[fd]);
	return (SUCCESS);
}
