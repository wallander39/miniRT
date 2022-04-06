/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pperea-d <pperea-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/17 16:35:26 by pperea-d          #+#    #+#             */
/*   Updated: 2021/02/01 17:24:49 by pperea-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	number_digit(long n, int number_base)
{
	if (n < number_base)
		return (1);
	else
		return (1 + (number_digit(n / number_base, number_base)));
}

static char	*build_str(long number, char *str, char *base, int n_digit)
{
	int		i;
	size_t	divider;

	divider = ft_strlen(base);
	i = n_digit - 1;
	while (number >= (long)divider)
	{
		str[i--] = base[number % divider];
		number /= divider;
	}
	str[i] = base[number];
	str[n_digit] = '\0';
	return (str);
}

char		*ft_itoa_base(long number, char *base)
{
	char	*str;
	size_t	size_base;
	int		n_digit;

	str = NULL;
	size_base = ft_strlen(base);
	if (!size_base)
		return (str);
	if (number < 0)
		number *= -1;
	n_digit = number_digit(number, size_base);
	str = (char *)malloc(n_digit + 1);
	if (!str)
		return (NULL);
	str = build_str(number, str, base, n_digit);
	return (str);
}
