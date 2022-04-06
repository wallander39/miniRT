/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pperea-d <pperea-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/01 22:17:30 by pperea-d          #+#    #+#             */
/*   Updated: 2021/02/04 16:15:05 by pperea-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void			add_square(t_square *square, t_scene *scene)
{
	t_square	*last;

	square->next = NULL;
	if (scene->squares == NULL)
	{
		scene->squares = square;
	}
	else
	{
		last = scene->squares;
		while (last->next != NULL)
			last = last->next;
		last->next = square;
	}
}

t_square		*create_square(char *line, t_scene *scene)
{
	t_square	*square;

	if (!(square = malloc(sizeof(t_square))))
		exit_error_msg(DEF_ERR, scene);
	line += 2;
	square->point = get_vec3(&line, scene);
	square->orientation = get_vec3(&line, scene);
	if (square->orientation.x < -1 || square->orientation.y < -1 ||
	square->orientation.z < -1 || square->orientation.x > 1 ||
	square->orientation.y > 1 || square->orientation.z > 1)
		exit_error_msg(FILE_ERR, scene);
	square->height = get_double(&line, scene);
	square->color = get_color(&line, scene);
	skip_blanks(&line);
	if (*line == '\0')
		return (square);
	else
	{
		exit_error_msg(FILE_ERR, scene);
		return (0);
	}
}

void			read_square(char *line, t_scene *scene)
{
	t_square	*new_square;

	new_square = create_square(line, scene);
	add_square(new_square, scene);
}

void			delete_squares(t_scene *scene)
{
	t_square *p;
	t_square *q;

	p = scene->squares;
	while (p != NULL)
	{
		q = p->next;
		free(p);
		p = q;
	}
	scene->squares = NULL;
}
