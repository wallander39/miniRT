/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pperea-d <pperea-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 20:57:45 by pperea-d          #+#    #+#             */
/*   Updated: 2020/10/19 17:49:40 by pperea-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_manager(t_stprint *data)
{
	if (data->type == 'c')
		ft_print_char(data);
	else if (data->type == 's')
		ft_print_string(data);
	else if (data->type == 'p')
		ft_print_pointer(data);
	else if (data->type == 'd' || data->type == 'i')
		ft_print_int(data);
	else if (data->type == 'u')
		ft_print_unsigned(data);
	else if (data->type == 'x' || data->type == 'X')
		ft_print_hex(data);
	else if (data->type == '%')
		ft_print_percent(data);
}
