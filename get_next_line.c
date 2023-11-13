/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amirloup <amirloup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 08:55:51 by amirloup          #+#    #+#             */
/*   Updated: 2023/11/13 11:31:57 by amirloup         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_read(char *prev_line)
{
	int		i;
	char	*line;

	i = 1;
	if (!prev_line)
	{
		free(prev_line);
		return (NULL);
	}
	while (prev_line[i] != '\0' && prev_line[i - 1] != '\n')
		i++;
	line = malloc((i + 1) * sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (prev_line[i] != '\0' && prev_line[i] != '\n')
	{
		line[i] = prev_line[i];
		i++;
	}
	if (prev_line[i] == '\n')
		line[i] = '\n';
	i = i + 1;
	line[i] = '\0';
	free(prev_line);
	return (line);
}

static void	ft_sort(char *buffer)
{
	int	i;

	i = 0;
	while (buffer[i] != '\0' && buffer[i] != '\n')
		i++;
	ft_memmove(buffer, &buffer[i + 1], (BUFFER_SIZE - i - 1));
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
	line = ft_read(line);
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

	fd = open("text.txt", O_RDONLY);
	i = 1;
	while (i < 7)
	{
		line = get_next_line(fd);
		printf("line [%02d]: %s", i, line);
		free(line);
		i++;
	}
	write (1, "\n", 1);
	close(fd);
	return (0);
}
