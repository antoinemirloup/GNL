/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amirloup <amirloup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 15:17:00 by amirloup          #+#    #+#             */
/*   Updated: 2023/11/17 16:13:41 by amirloup         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup(char *s)
{
	int		i;
	int		j;
	char	*d;

	i = 0;
	j = 0;
	while (s[i])
		i++;
	d = malloc((i + 1) * sizeof(char));
	if (d == NULL)
		return (NULL);
	while (s[j] && j < i)
	{
		d[j] = s[j];
		j++;
	}
	d[j] = '\0';
	return (d);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t		i;
	size_t		j;
	char		*s;
	size_t		sizes1;
	size_t		sizes2;

	i = 0;
	j = 0;
	if (!s1)
		return (ft_strdup(s2));
	sizes1 = ft_strlen(s1);
	sizes2 = ft_strlen(s2);
	s = (char *)malloc((sizes1 + sizes2 + 1) * sizeof(char));
	if (!s)
		return (NULL);
	while (s1[i])
		s[j++] = s1[i++];
	i = 0;
	while (s2[i])
		s[j++] = s2[i++];
	s[j] = '\0';
	free(s1);
	return (s);
}

void	*ft_memmove(char *dest, char *src, size_t n)
{
	size_t	i;

	i = 0;
	if (!dest && !src)
		return (0);
	if (dest > src)
	{
		while (n > 0)
		{
			dest[n - 1] = src[n - 1];
			n--;
		}
	}
	else
	{
		while (i < n)
		{
			dest[i] = src[i];
			i++;
		}
	}
	return (dest);
}

void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*ptr;

	ptr = (char *)s;
	i = 0;
	while (i < n)
	{
		ptr[i] = '\0';
		i++;
	}
}
