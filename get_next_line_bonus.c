/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amirloup <amirloup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 15:16:54 by amirloup          #+#    #+#             */
/*   Updated: 2023/11/16 15:52:12 by amirloup         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <stdio.h>

static char	*ft_strchr(char *s, int c)
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

char	*get_next_line(int fd)
{
	char		*line;
	static char	buffer[1024][BUFFER_SIZE + 1];
	int			cursor;

	if (fd < 0 || fd > 1024 || BUFFER_SIZE <= 0)
		return (NULL);
	cursor = 1;
	line = NULL;
	line = ft_strjoin(line, buffer[fd]);
	while (cursor != 0 && ft_strchr(buffer[fd], '\n') == NULL)
	{
		cursor = read(fd, buffer[fd], BUFFER_SIZE);
		if (cursor == -1)
		{
			ft_bzero(buffer[fd], BUFFER_SIZE);
			free(line);
			return (NULL);
		}
		buffer[fd][cursor] = '\0';
		line = ft_strjoin(line, buffer[fd]);
	}
	line = ft_read(line);
	ft_sort(buffer[fd]);
	return (line);
}

// #include <fcntl.h>

// int	main(void)
// {
// 	char	*line;
// 	int		i;
// 	int		fd1;
// 	int		fd2;
// 	int		fd3;

// 	fd1 = open("text1.txt", O_RDONLY);
// 	fd2 = open("text2.txt", O_RDONLY);
// 	fd3 = open("text3.txt", O_RDONLY);
// 	i = 1;
// 	while (i <= 5)
// 	{
// 		line = get_next_line(fd1);
// 		printf("%s", line);
// 		free(line);
// 		line = get_next_line(fd2);
// 		printf("%s", line);
// 		free(line);
// 		line = get_next_line(fd3);
// 		printf("%s", line);
// 		free(line);
// 		i++;
// 	}
// 	close(fd1);
// 	close(fd2);
// 	close(fd3);
// 	return (0);
// }
