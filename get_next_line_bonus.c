/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amirloup <amirloup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 15:16:54 by amirloup          #+#    #+#             */
/*   Updated: 2023/11/17 16:27:37 by amirloup         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != (unsigned char)c)
	{
		if (s[i] == '\0')
			return ((char *)0);
		i++;
	}
	return ((char *)&s[i]);
}

static char	*ft_line(char *line)
{
	int		i;
	char	*new_line;

	i = 0;
	while (line[i] != '\0' && line[i] != '\n')
		i++;
	new_line = malloc((i + 2) * sizeof(char));
	if (!new_line)
	{
		free(line);
		return (NULL);
	}
	i = 0;
	while (line[i] != '\0' && line[i] != '\n')
	{
		new_line[i] = line[i];
		i++;
	}
	if (line[i] == '\n')
		new_line[i++] = '\n';
	new_line[i] = '\0';
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

static char	*ft_read(int fd, char *line, char *buffer, int cursor)
{
	while (cursor != 0 && !(ft_strchr(buffer, '\n')))
	{
		cursor = read(fd, buffer, BUFFER_SIZE);
		if (cursor == -1)
		{
			ft_bzero(buffer, BUFFER_SIZE);
			free(line);
			return (NULL);
		}
		buffer[cursor] = '\0';
		line = ft_strjoin(line, buffer);
	}
	return (line);
}

char	*get_next_line(int fd)
{
	char		*line;
	int			cursor;
	static char	buffer[1024][BUFFER_SIZE + 1];

	cursor = 1;
	if (fd < 0 || fd > 1024 || BUFFER_SIZE <= 0)
		return (NULL);
	line = NULL;
	if (buffer[fd][0] != '\0')
		line = ft_strjoin(line, buffer[fd]);
	line = ft_read(fd, line, buffer[fd], cursor);
	if (!line || line[0] == '\0')
	{
		free(line);
		return (NULL);
	}
	line = ft_line(line);
	ft_sort(buffer[fd]);
	return (line);
}
