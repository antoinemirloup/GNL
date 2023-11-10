/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amirloup <amirloup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 08:55:51 by amirloup          #+#    #+#             */
/*   Updated: 2023/11/08 17:21:06 by amirloup         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*str;
	char		*line;
	static char	*stach;
	int			i;
	int			j;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stach = malloc(BUFFER_SIZE * sizeof(char));
	if (!stach)
		return (NULL);
	read(fd, stach, BUFFER_SIZE);
	i = 0;
	j = 0;
	while (stach[i])
	{
		while (stach[i] != '\n')
		{
			line[i] = stach[i];
			i++;
		}
		if (stach[i] == '\n')
		{
			stach[j] = stach[i + 1];
			i++;
			j++;
		}
	}
}

#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	int	fd = open("hello.txt", O_RDONLY);
	printf("%s\n", fd);
	close(fd);
}