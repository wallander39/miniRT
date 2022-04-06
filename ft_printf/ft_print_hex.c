/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pperea-d <pperea-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/17 16:36:24 by pperea-d          #+#    #+#             */
/*   Updated: 2020/10/22 18:10:16 by pperea-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	printing_hex(t_stprint *data, char *str, int width, int len)
{
	if ((unsigned)(data->printed + width) <= (unsigned)INT_MAX || \
	(unsigned)(data->printed + len) <= (unsigned)INT_MAX)
	{
		if (data->dash)
		{
			print_str(str, len, data);
			print_spaces(width - len, data);
		}
		else
		{
			if (data->zero && !(data->dot))
				print_zeros(width - len, data);
			else
				print_spaces(width - len, data);
			print_str(str, len, data);
		}
	}
	else
		data->error = 1;
}

static void	analyze_hex(t_stprint *data, int width, int precision)
{
	unsigned	var;
	char		*str;
	int			length;

	var = va_arg(data->args, unsigned);
	if (data->dot && precision == 0 && var == 0)
		str = ft_strdup("");
	else
	{
		str = ft_itoa_base(var, "0123456789abcdef");
		length = 0;
		while (str[length] != '\0')
			length++;
		str = zeroprecision(precision - length, str);
	}
	length = 0;
	while (str[length] != '\0')
		length++;
	if (data->type == 'X')
		str = ft_strupcase(str);
	printing_hex(data, str, width, length);
	free(str);
}

void		ft_print_hex(t_stprint *data)
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
	analyze_hex(data, width, precision);
}
