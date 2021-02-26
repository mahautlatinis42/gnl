/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malatini <malatini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 09:18:44 by malatini          #+#    #+#             */
/*   Updated: 2021/02/26 10:33:38 by malatini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE__H
# define GET_NEXT_LINE__H
# include <unistd.h>
# include <libc.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h> 
# include <fcntl.h>

int		get_next_line(int fd, char **line);
size_t	ft_strlen(char *str);
char	*ft_strjoin(char *s1, char *s2);
void	*ft_memmove(void *dst, void *src, size_t len);

#endif
