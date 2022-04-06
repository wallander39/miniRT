/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pperea-d <pperea-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/31 18:29:13 by pperea-d          #+#    #+#             */
/*   Updated: 2021/02/04 15:54:51 by pperea-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void		add_plane(t_plane *plane, t_scene *scene)
{
	t_plane	*last;

	plane->next = NULL;
	if (scene->planes == NULL)
	{
		scene->planes = plane;
	}
	else
	{
		last = scene->planes;
		while (last->next != NULL)
			last = last->next;
		last->next = plane;
	}
}

t_plane		*create_plane(char *line, t_scene *scene)
{
	t_plane	*plane;

	if (!(plane = malloc(sizeof(t_plane))))
		exit_error_msg(DEF_ERR, scene);
	line += 2;
	plane->point = get_vec3(&line, scene);
	plane->normal = get_vec3(&line, scene);
	if (plane->normal.x < -1 || plane->normal.y < -1 || plane->normal.z < -1 ||
	plane->normal.x > 1 || plane->normal.y > 1 || plane->normal.z > 1)
		exit_error_msg(FILE_ERR, scene);
	plane->color = get_color(&line, scene);
	skip_blanks(&line);
	if (*line == '\0')
		return (plane);
	else
	{
		exit_error_msg(FILE_ERR, scene);
		return (0);
	}
}

void		read_plane(char *line, t_scene *scene)
{
	t_plane	*new_plane;

	new_plane = create_plane(line, scene);
	add_plane(new_plane, scene);
}

void		delete_planes(t_scene *scene)
{
	t_plane *p;
	t_plane *q;

	p = scene->planes;
	while (p != NULL)
	{
		q = p->next;
		free(p);
		p = q;
	}
	scene->planes = NULL;
}
