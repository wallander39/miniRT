/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pperea-d <pperea-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/01 22:26:39 by pperea-d          #+#    #+#             */
/*   Updated: 2021/02/04 16:17:02 by pperea-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void			add_triangle(t_triangle *triangle, t_scene *scene)
{
	t_triangle	*last;

	triangle->next = NULL;
	if (scene->triangles == NULL)
	{
		scene->triangles = triangle;
	}
	else
	{
		last = scene->triangles;
		while (last->next != NULL)
			last = last->next;
		last->next = triangle;
	}
}

t_triangle		*create_triangle(char *line, t_scene *scene)
{
	t_triangle	*triangle;

	if (!(triangle = malloc(sizeof(t_triangle))))
		exit_error_msg(DEF_ERR, scene);
	line += 2;
	triangle->p1 = get_vec3(&line, scene);
	triangle->p2 = get_vec3(&line, scene);
	triangle->p3 = get_vec3(&line, scene);
	triangle->color = get_color(&line, scene);
	skip_blanks(&line);
	if (*line == '\0')
		return (triangle);
	else
	{
		exit_error_msg(FILE_ERR, scene);
		return (0);
	}
}

void			read_triangle(char *line, t_scene *scene)
{
	t_triangle	*new_triangle;

	new_triangle = create_triangle(line, scene);
	add_triangle(new_triangle, scene);
}

void			delete_triangles(t_scene *scene)
{
	t_triangle *p;
	t_triangle *q;

	p = scene->triangles;
	while (p != NULL)
	{
		q = p->next;
		free(p);
		p = q;
	}
	scene->triangles = NULL;
}
