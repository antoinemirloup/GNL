/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amirloup <amirloup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 08:55:51 by amirloup          #+#    #+#             */
/*   Updated: 2023/11/14 11:51:28 by amirloup         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static char	*ft_read(char *line)
{
	int		i;
	char	*new_line;

	i = 0;
	if (!line || !line[0])
	{
		free(line);
		return (NULL);
	}
	while (line[i] != '\0' && line[i] != '\n')
		i++;
	// if (line[i] == '\n')
	// 	i++;
	new_line = malloc((i + 2) * sizeof(char));
	if (!new_line)
		return (NULL);
	i = 0;
	while (line[i] != '\0' && line[i] != '\n')
	{
		new_line[i] = line[i];
		i++;
	}
	if (line[i] == '\n')
		new_line[i] = '\n';
	new_line[i + 1] = '\0';
	free(line);
	return (new_line);
}

static void	ft_sort(char *buffer)
{
	int	i;

	i = 0;
	while (buffer[i] != '\0' && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n')
		i++;
	ft_memmove(buffer, buffer + i, (BUFFER_SIZE - i));
	ft_bzero(&buffer[BUFFER_SIZE - i], i);
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
	line = ft_strjoin(line, buffer);
	while (cursor != 0 && ft_strchr(buffer, '\n') == NULL)
	{
		cursor = read(fd, buffer, BUFFER_SIZE);
		if (cursor == -1)
		{
			free(line);
			return (NULL);
		}
		buffer[cursor] = '\0';
		line = ft_strjoin(line, buffer);
	}
	line = ft_read(line);
	ft_sort(buffer);
	return (line);
}

#include <fcntl.h>

int	main(void)
{
	char	*line;
	int		i;
	int		fd;

	fd = open("text.txt", O_RDONLY);
	i = 1;
	while (i <= 7)
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
