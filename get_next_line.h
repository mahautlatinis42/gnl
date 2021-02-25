/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malatini <malatini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 09:18:44 by malatini          #+#    #+#             */
/*   Updated: 2021/02/25 10:30:47 by malatini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE__H
# define GET_NEXT_LINE__H
# include <unistd.h>
# include <libc.h>

int		get_next_line(int fd, char **line);
size_t	ft_strlen(char *str);

#endif
