/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduboulo <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 15:58:08 by lduboulo          #+#    #+#             */
/*   Updated: 2021/11/19 12:27:44 by lduboulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "get_next_line.h"
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <fcntl.h>

char	*get_next_line(int fd);
char	*line_return(char **str, int i);
char	*no_read(char **str);
char	*buffer_not_empty(char **str, int i);
char	*read_loop(int fd, char **str);
void	*ft_bzero(void *s, size_t n);
size_t	ft_strlen(const char *str);
char	*ft_strjoin(char **s1, char const *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strdup(char **s1, int istr);

#endif
