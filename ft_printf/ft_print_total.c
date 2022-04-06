/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_total.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pperea-d <pperea-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 20:53:59 by pperea-d          #+#    #+#             */
/*   Updated: 2020/10/22 18:06:32 by pperea-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		reset_flags(t_stprint *data)
{
	data->dash = 0;
	data->space = 0;
	data->zero = 0;
	data->dot = 0;
	data->asterisk_w = 0;
	data->asterisk_p = 0;
	data->type = '\0';
	data->width = 0;
	data->precision = 0;
}

void			ft_print_total(t_stprint *data)
{
	int		i;

	i = 0;
	while (data->str[i] != '\0' && data->printed < INT_MAX && !(data->error))
	{
		reset_flags(data);
		if (data->str[i] == '%')
		{
			if (flags((data->str + i), data) == -1)
				print_manager(data);
			i += data->next;
		}
		if (!(data->type) && data->str[i] != '\0')
		{
			ft_putchar_fd(data->str[i], 1);
			(data->printed)++;
		}
		i++;
	}
}
