/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pperea-d <pperea-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 20:50:38 by pperea-d          #+#    #+#             */
/*   Updated: 2021/02/01 17:24:15 by pperea-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		set_str(t_stprint *data)
{
	data->str = NULL;
	data->printed = 0;
	data->next = 0;
	data->error = 0;
}

int				ft_printf(const char *format, ...)
{
	t_stprint	*data;

	data = (t_stprint *)malloc(sizeof(t_stprint));
	if (!data)
		return (-1);
	va_start(data->args, format);
	set_str(data);
	data->str = ft_strdup(format);
	if (!(data->str))
		return (-1);
	ft_print_total(data);
	if (data->error)
		data->printed = -1;
	free(data->str);
	va_end(data->args);
	free(data);
	return (data->printed);
}
