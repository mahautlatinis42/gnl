/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malatini <malatini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 09:18:44 by malatini          #+#    #+#             */
/*   Updated: 2021/03/01 16:53:45 by malatini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE__H
# define GET_NEXT_LINE__H
# define ERROR -1
# define SUCCESS 1
# define DONE 0

# include <unistd.h>
# include <libc.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <limits.h>

int		get_next_line(int fd, char **line);
int		ft_strlen(char *str);
char	*ft_strnjoin(char *s1, char *s2);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strdup(const char *s1);
int		ft_eol(char *str);
void	ft_bzero(void *s, size_t n);
char	*ft_better_strchr(char *s, int c);
int		found_n(char *str);

#endif
