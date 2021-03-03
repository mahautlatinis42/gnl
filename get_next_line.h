/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malatini <malatini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 09:18:44 by malatini          #+#    #+#             */
/*   Updated: 2021/03/03 11:50:56 by malatini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE__H
# define GET_NEXT_LINE__H
# define ERROR -1
# define SUCCESS 1
# define DONE 0

# ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
# endif

# include <unistd.h>
# include <libc.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <limits.h>

size_t	ft_strlen(const char *s);
char	*gnl_strjoin(char *s1, char *s2);
char	*create_line(char *tmp, char *buffer);
int		get_next_line(int fd, char **line);

#endif
