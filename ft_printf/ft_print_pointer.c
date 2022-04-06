/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pperea-d <pperea-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/17 16:37:48 by pperea-d          #+#    #+#             */
/*   Updated: 2020/10/22 17:49:49 by pperea-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	zero_flag(t_stprint *data, int width, char *str, int len)
{
	if ((unsigned)(data->printed + width + 2) <= (unsigned)INT_MAX \
	|| (unsigned)(data->printed + len + 2) <= (unsigned)INT_MAX)
	{
		print_str("0x\0", 2, data);
		print_zeros(width - len - 2, data);
		print_str(str, len, data);
	}
	else
		data->error = 1;
	free(str);
}

static void	no_zero_flag(t_stprint *data, int width, char *str, int len)
{
	if ((unsigned)(data->printed + width + 2) <= (unsigned)INT_MAX \
	|| (unsigned)(data->printed + len + 2) <= (unsigned)INT_MAX)
	{
		if (data->dash)
		{
			print_str("0x\0", 2, data);
			print_str(str, len, data);
			print_spaces(width - len - 2, data);
		}
		else
		{
			print_spaces(width - len - 2, data);
			print_str("0x\0", 2, data);
			print_str(str, len, data);
		}
	}
	else
		data->error = 1;
	free(str);
}

static void	analyze_pointer(t_stprint *data, int width, int precision)
{
	unsigned long	var;
	char			*str;
	int				length_str;

	var = va_arg(data->args, unsigned long);
	str = ft_itoa_base(var, "0123456789abcdef\0");
	length_str = 0;
	while (str[length_str] != '\0')
		length_str++;
	if (data->zero && !(data->dot) && !(data->dash))
		zero_flag(data, width, str, length_str);
	else
	{
		if (precision < length_str && data->dot && var == 0)
			length_str = 1;
		else if (precision > length_str)
		{
			str = zeroprecision(precision - length_str, str);
			length_str = 0;
			while (str[length_str] != '\0')
				length_str++;
		}
		no_zero_flag(data, width, str, length_str);
	}
}

void		ft_print_pointer(t_stprint *data)
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
	analyze_pointer(data, width, precision);
}
