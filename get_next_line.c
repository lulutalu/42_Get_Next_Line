/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduboulo <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 16:04:32 by lduboulo          #+#    #+#             */
/*   Updated: 2021/11/12 23:50:53 by lduboulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*line;
	char		buffer[BUFFER_SIZE + 1];
	int			nbread;
	int			iline;
	
	while (1)
	{
		ft_bzero(buffer, (BUFFER_SIZE + 1 * sizeof(char)));
		nbread = read(fd, buffer, BUFFER_SIZE);
		if (nbread == BUFFER_SIZE)
		{
			line = ft_strjoin(line, buffer);
			iline = 0;
			while (line[iline] != '\0')
			{
				while (line[iline] && line[iline] != '\n')
					iline++;
				if (line[iline] == '\n')
					return (ft_substr(line, 0, iline));
			}
			get_next_line(fd);
		}
		else
			return (NULL);
	}
}

int	main()
{
	printf("Res : %s\n", get_next_line(open("test.txt", O_RDONLY)));
}
