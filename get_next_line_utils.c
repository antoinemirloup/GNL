/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amirloup <amirloup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 08:58:03 by amirloup          #+#    #+#             */
/*   Updated: 2023/11/08 17:05:47 by amirloup         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t		i;
	size_t		j;
	char		*s;
	size_t		sizes1;
	size_t		sizes2;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
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
	return (s);
}
