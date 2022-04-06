/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pperea-d <pperea-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 20:58:28 by pperea-d          #+#    #+#             */
/*   Updated: 2020/10/22 18:06:00 by pperea-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		fill_flags(t_stprint *data, char *str, int i)
{
	if (str[i] == ' ')
		data->space = 1;
	else if (str[i] == '-')
		data->dash = 1;
	else if (str[i] == '0' && !(ft_strchr(NUMBERS, str[i - 1])) \
	&& !(ft_strchr(SPECIFIER, str[i + 1])) && (data->dot) == 0)
		data->zero = 1;
	else if (str[i] == '*' && data->dot == 0)
		data->asterisk_w = 1;
	else if (ft_strchr(NUMBERS, str[i]) \
	&& data->dot == 0 && data->width == 0)
		data->width = ft_atoi(str + i);
	else if (str[i] == '.' && str[i + 1] != ' ')
		data->dot = 1;
	else if (str[i] == '*' && data->dot != 0)
		data->asterisk_p = 1;
	else if (ft_strchr(NUMBERS, str[i]) \
	&& data->dot != 0 && data->precision == 0)
		data->precision = ft_atoi(str + i);
}

int				flags(char *str, t_stprint *data)
{
	int	i;

	i = 1;
	while ((ft_strchr(FLAGS, str[i]) || ft_strchr(NUMBERS, str[i])) && str[i])
		fill_flags(data, str, i++);
	data->next = i;
	if (ft_strchr(SPECIFIER, str[i]) && str[i] != '\0')
	{
		data->type = str[i];
		return (-1);
	}
	return (data->next);
}
