/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filters.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pperea-d <pperea-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 10:59:15 by pperea-d          #+#    #+#             */
/*   Updated: 2021/02/08 11:26:02 by pperea-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_color	sepia_filter(t_color color)
{
	t_color	sepia;

	sepia.r = 0.393 * color.r + 0.769 * color.g + 0.189 * color.b;
	sepia.g = 0.349 * color.r + 0.686 * color.g + 0.168 * color.b;
	sepia.b = 0.272 * color.r + 0.534 * color.g + 0.131 * color.b;
	return (sepia);
}

t_color	mono_filter(t_color color)
{
	t_color	mono;

	mono.r = 0.3 * color.r + 0.59 * color.g + 0.11 * color.b;
	mono.g = 0.3 * color.r + 0.59 * color.g + 0.11 * color.b;
	mono.b = 0.3 * color.r + 0.59 * color.g + 0.11 * color.b;
	return (mono);
}

t_color	red_filter(t_color color)
{
	t_color	red;

	red.r = color.r;
	red.g = 0;
	red.b = 0;
	return (red);
}

t_color	green_filter(t_color color)
{
	t_color	green;

	green.r = 0;
	green.g = color.g;
	green.b = 0;
	return (green);
}

t_color	blue_filter(t_color color)
{
	t_color	blue;

	blue.r = 0;
	blue.g = 0;
	blue.b = color.b;
	return (blue);
}
