/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amirloup <amirloup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 15:06:23 by amirloup          #+#    #+#             */
/*   Updated: 2023/11/14 09:51:38 by amirloup         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

char	*get_next_line(int fd);
char	*ft_strjoin(char *s1, char *s2);
void	*ft_memmove(char *dest, char *src, size_t n);
char	*ft_strchr(char *s, int c);
void	ft_bzero(void *s, size_t n);
size_t	ft_strlen(char *s);
char	*ft_strdup(char *s);

#endif