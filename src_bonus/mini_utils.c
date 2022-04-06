/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pperea-d <pperea-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 21:58:02 by pperea-d          #+#    #+#             */
/*   Updated: 2021/02/04 15:28:15 by pperea-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int		ft_isblank(int c)
{
	if ((c == ' ') || (c == '\t'))
		return (1);
	else
		return (0);
}

void	skip_string(char **s)
{
	while (ft_isalpha(**s))
		(*s)++;
}

void	skip_blanks(char **s)
{
	while (ft_isblank(**s))
		(*s)++;
}

void	skip_digits(char **s)
{
	while (ft_isdigit(**s))
		(*s)++;
}

void	skip_char(char **s, int c)
{
	if (**s == c)
		(*s)++;
}
