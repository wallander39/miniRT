/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pperea-d <pperea-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/17 16:33:49 by pperea-d          #+#    #+#             */
/*   Updated: 2021/02/01 17:26:15 by pperea-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*analyze_precision(t_stprint *data, char *str, int prcs, int var)
{
	int	length;

	if (data->dot && prcs == 0 && var == 0)
		str = ft_strdup("");
	else
	{
		str = ft_itoa_base((long)var, "0123456789");
		length = 0;
		while (str[length] != '\0')
			length++;
		str = zeroprecision(prcs - length, str);
	}
	return (str);
}

static void	zero_flag(t_stprint *data, char *str, int var, int width)
{
	int len_str;

	len_str = 0;
	while (str[len_str] != '\0')
		len_str++;
	if ((unsigned)(data->printed + width) <= (unsigned)INT_MAX || \
	(unsigned)(data->printed + len_str + data->space) <= (unsigned)INT_MAX)
	{
		print_spaces(data->space, data);
		if (var < 0)
		{
			print_str("-", 1, data);
			width--;
		}
		print_zeros(width - len_str - data->space, data);
		print_str(str, len_str, data);
	}
	else
		data->error = 1;
}

static void	no_zero_flag(t_stprint *data, char *str, int width, int len_str)
{
	if ((unsigned)(data->printed + width) <= (unsigned)INT_MAX || \
	(unsigned)(data->printed + len_str + data->space) <= (unsigned)INT_MAX)
	{
		print_spaces(data->space, data);
		if (data->dash && !(data->space))
		{
			print_str(str, len_str, data);
			print_spaces(width - len_str, data);
		}
		else
		{
			print_spaces(width - len_str - data->space, data);
			print_str(str, len_str, data);
		}
	}
	else
		data->error = 1;
}

static void	analyze_int(t_stprint *data, int width, int precision)
{
	int		var;
	char	*str;
	int		length;

	str = NULL;
	var = va_arg(data->args, int);
	if (var < 0)
		data->space = 0;
	str = analyze_precision(data, str, precision, var);
	if (data->zero && !(data->dot) && !(data->dash))
		zero_flag(data, str, var, width);
	else
	{
		if (var < 0)
			str = ft_strsjoin("-", str, 0, 1);
		length = 0;
		while (str[length] != '\0')
			length++;
		no_zero_flag(data, str, width, length);
	}
	free(str);
}

void		ft_print_int(t_stprint *data)
{
	int		width;
	int		precision;

	width = 0;
	precision = 0;
	if (data->asterisk_w)
		width = get_asterisk(data);
	else if (data->width)
		width = data->width;
	if (data->asterisk_p)
		precision = get_asterisk(data);
	else if (data->precision)
		precision = data->precision;
	if (width < 0)
	{
		data->dash = 1;
		width *= -1;
	}
	analyze_int(data, width, precision);
}
