/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pperea-d <pperea-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/17 16:38:29 by pperea-d          #+#    #+#             */
/*   Updated: 2020/10/22 18:15:29 by pperea-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		printing_str(t_stprint *data, char *str, int width, int length)
{
	if ((unsigned)(data->printed + width) <= (unsigned)INT_MAX \
	|| (unsigned)(data->printed + length) <= (unsigned)INT_MAX)
	{
		if (data->dash)
		{
			print_str(str, length, data);
			print_spaces(width - length, data);
		}
		else
		{
			if (data->zero)
				print_zeros(width - length, data);
			else
				print_spaces(width - length, data);
			print_str(str, length, data);
		}
	}
	else
		data->error = 1;
}

static void		length_str(t_stprint *data, int width, int precision)
{
	char	*v;
	char	*s;
	int		length;

	v = va_arg(data->args, char *);
	length = 0;
	if (!v)
		s = ft_strdup("(null)");
	else
		s = ft_strdup(v);
	while (s[length] != '\0')
		length++;
	if (precision < length && data->dot && precision >= 0)
		length = precision;
	printing_str(data, s, width, length);
	free(s);
}

void			ft_print_string(t_stprint *data)
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
	length_str(data, width, precision);
}
