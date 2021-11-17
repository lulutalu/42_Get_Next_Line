/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduboulo <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 16:04:32 by lduboulo          #+#    #+#             */
/*   Updated: 2021/11/17 21:34:29 by lduboulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*line_return(char **str, int i)
{
	char	*res;

	res = ft_substr(*str, 0, ++i);
	*str = ft_strdup(&(*str), i);
	return (res);
}

char	*no_read(char **str)
{
	free(*str);
	*str = NULL;
	return (NULL);
}

char	*buffer_not_empty(char **str, int i)
{
	char	*res;

	while ((*str)[i] && (*str)[i] != '\n')
		i++;
	if ((*str)[i] == '\n')
		return (line_return(&(*str), i));
	if ((*str)[i] == '\0')
	{
		res = ft_substr(*str, 0, ++i);
		free(*str);
		*str = NULL;
		return (res);
	}
	return (NULL);
}

char	*read_loop(int fd, char **str)
{
	int		i;
	int		nbread;
	char	buffer[BUFFER_SIZE + 1];

	i = 0;
	while (1)
	{
		ft_bzero(buffer, (BUFFER_SIZE + 1) * sizeof(char));
		nbread = read(fd, buffer, BUFFER_SIZE);
		*str = ft_strjoin(&(*str), buffer);
		if (nbread > 0)
		{
			while ((*str)[i] && (*str)[i] != '\n')
				i++;
			if ((*str)[i] == '\n')
				return (line_return(&(*str), i));
		}
		else if ((*str)[0] == '\0')
			return (no_read(&(*str)));
		else
			return (buffer_not_empty(&(*str), i));
	}
}

char	*get_next_line(int fd)
{
	static char	*str;

	if (fd < 0)
		return (NULL);
	if (!str)
	{
		str = malloc(1 * sizeof(char));
		ft_bzero(str, 1 * sizeof(char));
	}
	return (read_loop(fd, &str));
}
