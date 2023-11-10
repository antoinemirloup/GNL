/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amirloup <amirloup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 08:55:51 by amirloup          #+#    #+#             */
/*   Updated: 2023/11/10 16:28:59 by amirloup         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// static char	*ft_read(char *line, char *buffer)
// {
	
	
// 	return (line);
// }

static void	ft_sort(char *buffer)
{
	int	i;

	i = 0;
	while (buffer[i] != '\0' && buffer[i] != '\n')
		i++;
	ft_memmove(buffer, &buffer[i + 1], (BUFFER_SIZE - i));
	ft_bzero(&buffer[i + 1], i + 1);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	buffer[BUFFER_SIZE + 1];
	int			cursor;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	cursor = 1;
	line = NULL;
	while (cursor != 0 && ft_strchr(buffer, '\n') == NULL)
	{
		cursor = read(fd, buffer, BUFFER_SIZE);
		if (cursor == -1)
			return (NULL);
		buffer[cursor] = '\0';
		line = ft_strjoin(line, buffer);
	}
	ft_sort(buffer);
	return (line);
}

#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	char	*line;
	int		i;
	int		fd;

	fd = open("hello.txt", O_RDONLY);
	i = 1;
	while (i < 7)
	{
		line = get_next_line(fd);
		printf("line [%02d]: %s", i, line);
		free(line);
		i++;
	}
	close(fd);
	return (0);
}
