/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pperea-d <pperea-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 19:09:38 by pperea-d          #+#    #+#             */
/*   Updated: 2020/12/27 17:26:45 by pperea-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	gn_strlcpy(char *dest, const char *src, size_t n)
{
	size_t	length_src;
	int		i;

	length_src = 0;
	while (src[length_src])
		length_src++;
	if (n != 0)
	{
		i = -1;
		if (length_src + 1 < n)
		{
			while (++i < (int)length_src)
				dest[i] = src[i];
		}
		else
		{
			while (++i < (int)n - 1)
				dest[i] = src[i];
		}
		dest[i] = '\0';
	}
	return (length_src);
}

size_t	gn_strlcat(char *dest, const char *src, size_t size)
{
	size_t	dest_length;
	size_t	src_length;
	size_t	count;

	dest_length = 0;
	while (dest[dest_length] != '\0' && dest_length < size)
		dest_length++;
	count = dest_length;
	src_length = 0;
	while (src[src_length] != '\0')
		src_length++;
	while (count + 1 < size && ((char *)src)[count - dest_length] != '\0')
	{
		dest[count] = ((char *)src)[count - dest_length];
		count++;
	}
	if (dest_length < size)
		dest[count] = '\0';
	return (dest_length + src_length);
}

char	*gn_strjoin(char *s1, char *s2)
{
	size_t	size;
	int		s1_length;
	int		s2_length;
	char	*ptr;

	if (!s1 || !s2)
		return (NULL);
	size = 0;
	s1_length = -1;
	while (s1[++s1_length])
		size++;
	s2_length = -1;
	while (s2[++s2_length])
		size++;
	ptr = (char *)malloc(size + 1);
	if (!ptr)
		return (NULL);
	gn_strlcpy(ptr, s1, s1_length + 1);
	gn_strlcat(ptr, s2, size + 1);
	free(s1);
	return (ptr);
}

char	*gn_strchr(const char *s, int c)
{
	int	i;
	int	s_length;

	i = -1;
	s_length = 0;
	while (s[s_length])
		s_length++;
	if (s[0] == c)
		return ((char *)s);
	while (++i <= s_length)
	{
		if (s[i] == c)
			return ((char *)s + i);
	}
	return (NULL);
}

char	*gn_strdup(char *s)
{
	int		length;
	int		i;
	char	*ptr;

	length = 0;
	while (s[length])
		length++;
	ptr = (char *)malloc(length + 1);
	if (!ptr)
		return (NULL);
	i = -1;
	while (++i < length)
		ptr[i] = s[i];
	ptr[i] = '\0';
	return (ptr);
}
