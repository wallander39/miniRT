/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pperea-d <pperea-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 20:59:46 by pperea-d          #+#    #+#             */
/*   Updated: 2020/10/18 21:37:55 by pperea-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		get_asterisk(t_stprint *data)
{
	int	i;

	i = va_arg(data->args, int);
	return (i);
}

char	*zeroprecision(int n_zeros, char *str)
{
	char	*s;
	int		i;

	s = ft_strdup("");
	i = 0;
	while (i < n_zeros)
	{
		s = ft_strjoin(s, "0");
		i++;
	}
	s = ft_strjoin(s, str);
	free(str);
	return (s);
}

void	print_spaces(int num_spaces, t_stprint *data)
{
	int	i;

	i = 0;
	while (i < num_spaces)
	{
		ft_putchar_fd(' ', 1);
		(data->printed)++;
		i++;
	}
}

void	print_zeros(int num_spaces, t_stprint *data)
{
	int	i;

	i = 0;
	while (i < num_spaces)
	{
		ft_putchar_fd('0', 1);
		(data->printed)++;
		i++;
	}
}

void	print_str(char *str, int length, t_stprint *data)
{
	int	i;

	i = 0;
	while (i < length)
	{
		ft_putchar_fd(str[i], 1);
		(data->printed)++;
		i++;
	}
}
