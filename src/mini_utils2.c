/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pperea-d <pperea-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 15:27:36 by pperea-d          #+#    #+#             */
/*   Updated: 2021/02/04 16:22:24 by pperea-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int		get_int(char **line, t_scene *scene)
{
	int	a;

	a = 0;
	skip_blanks(line);
	if (ft_isdigit(**line) || **line == '-')
	{
		a = ft_atoi(*line);
		skip_char(line, '-');
		skip_digits(line);
	}
	else
		exit_error_msg(FILE_ERR, scene);
	return (a);
}

double	get_double(char **line, t_scene *scene)
{
	double	a;

	a = 0;
	skip_blanks(line);
	if (**line == '-' || **line == '.' || ft_isdigit(**line))
	{
		a = ft_atod(*line);
		skip_char(line, '-');
		skip_digits(line);
		skip_char(line, '.');
		skip_digits(line);
	}
	else
		exit_error_msg(FILE_ERR, scene);
	return (a);
}

t_vec3	get_vec3(char **line, t_scene *scene)
{
	t_vec3		vec3;

	skip_blanks(line);
	vec3.x = get_double(line, scene);
	skip_blanks(line);
	skip_char(line, ',');
	vec3.y = get_double(line, scene);
	skip_blanks(line);
	skip_char(line, ',');
	vec3.z = get_double(line, scene);
	return (vec3);
}

t_color	get_color(char **line, t_scene *scene)
{
	t_color		color;

	skip_blanks(line);
	color.r = get_double(line, scene);
	skip_blanks(line);
	skip_char(line, ',');
	color.g = get_double(line, scene);
	skip_blanks(line);
	skip_char(line, ',');
	color.b = get_double(line, scene);
	if (color.r < 0 || color.g < 0 || color.b < 0 ||
	color.r > 255 || color.g > 255 || color.b > 255)
		exit_error_msg(RGB_RANGE_ERR, scene);
	return (color);
}
