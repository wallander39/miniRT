/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pperea-d <pperea-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 17:53:45 by pperea-d          #+#    #+#             */
/*   Updated: 2020/10/22 18:15:44 by pperea-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strsjoin(char *s1, char *s2, int free_s1, int free_s2)
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
	ft_strlcpy(ptr, s1, s1_length + 1);
	ft_strlcat(ptr, s2, size + 1);
	if (free_s1)
		free(s1);
	if (free_s2)
		free(s2);
	return (ptr);
}

char	*ft_strupcase(char *str)
{
	int i;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i] != '\0')
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] = str[i] - 32;
		i++;
	}
	return (str);
}
