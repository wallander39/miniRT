/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_percent.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pperea-d <pperea-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/17 16:37:09 by pperea-d          #+#    #+#             */
/*   Updated: 2020/10/22 17:54:09 by pperea-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		printing_percent(t_stprint *data, char var, int width)
{
	if (data->dash)
	{
		ft_putchar_fd(var, 1);
		(data->printed)++;
		print_spaces(width - 1, data);
	}
	else
	{
		if (data->zero)
			print_zeros(width - 1, data);
		else
			print_spaces(width - 1, data);
		ft_putchar_fd(var, 1);
		(data->printed)++;
	}
}

static void		no_error_percent(t_stprint *data, int width)
{
	char	var;

	var = data->type;
	if ((unsigned)(data->printed + width) <= (unsigned)INT_MAX)
		printing_percent(data, var, width);
	else
		data->error = 1;
}

void			ft_print_percent(t_stprint *data)
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
	no_error_percent(data, width);
}
