/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pperea-d <pperea-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/17 16:39:05 by pperea-d          #+#    #+#             */
/*   Updated: 2020/10/22 17:53:50 by pperea-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		printing_u(t_stprint *data, char *str, int width, int length)
{
	if ((unsigned)(data->printed + width) <= (unsigned)INT_MAX || \
	(unsigned)(data->printed + length <= (unsigned)INT_MAX))
	{
		if (data->dash)
		{
			print_str(str, length, data);
			print_spaces(width - length, data);
		}
		else
		{
			if (data->zero && !(data->dot))
				print_zeros(width - length, data);
			else
				print_spaces(width - length, data);
			print_str(str, length, data);
		}
	}
	else
		data->error = 1;
}

static void		length_unsigned(t_stprint *data, int width, int precision)
{
	unsigned	v;
	char		*s;
	int			length;

	v = va_arg(data->args, unsigned);
	if (data->dot && precision == 0 && v == 0)
		s = ft_strdup("");
	else if (data->dot && precision < 0 && v == 0)
		s = ft_strdup("0");
	else
	{
		s = ft_itoa_base(v, "0123456789");
		length = 0;
		while (s[length] != '\0')
			length++;
		s = zeroprecision(precision - length, s);
	}
	length = 0;
	while (s[length] != '\0')
		length++;
	printing_u(data, s, width, length);
	free(s);
}

void			ft_print_unsigned(t_stprint *data)
{
	int			w;
	int			p;

	w = 0;
	p = 0;
	if (data->asterisk_w)
		w = get_asterisk(data);
	else if (data->width)
		w = data->width;
	if (data->asterisk_p)
		p = get_asterisk(data);
	else if (data->precision)
		p = data->precision;
	if (w < 0)
	{
		data->dash = 1;
		w *= -1;
	}
	length_unsigned(data, w, p);
}
