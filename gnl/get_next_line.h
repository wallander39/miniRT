/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pperea-d <pperea-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 19:04:36 by pperea-d          #+#    #+#             */
/*   Updated: 2020/12/27 17:24:26 by pperea-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 11
# endif

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>

int		get_next_line(int fd, char **line);
size_t	gn_strlcpy(char *dest, const char *src, size_t n);
size_t	gn_strlcat(char *dest, const char *src, size_t n);
char	*gn_strjoin(char *s1, char *s2);
char	*gn_strchr(const char *s, int c);
char	*gn_strdup(char *s);


#endif
