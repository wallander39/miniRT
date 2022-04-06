/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pperea-d <pperea-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 20:51:40 by pperea-d          #+#    #+#             */
/*   Updated: 2021/02/04 16:12:02 by pperea-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void			add_sphere(t_sphere *sphere, t_scene *scene)
{
	t_sphere	*last;

	sphere->next = NULL;
	if (scene->spheres == NULL)
	{
		scene->spheres = sphere;
	}
	else
	{
		last = scene->spheres;
		while (last->next != NULL)
			last = last->next;
		last->next = sphere;
	}
}

t_sphere		*create_sphere(char *line, t_scene *scene)
{
	t_sphere	*sphere;

	if (!(sphere = malloc(sizeof(t_sphere))))
		exit_error_msg(DEF_ERR, scene);
	line += 2;
	sphere->center = get_vec3(&line, scene);
	sphere->diameter = get_double(&line, scene);
	sphere->color = get_color(&line, scene);
	skip_blanks(&line);
	if (*line == '\0')
		return (sphere);
	else
	{
		exit_error_msg(FILE_ERR, scene);
		return (0);
	}
}

void			read_sphere(char *line, t_scene *scene)
{
	t_sphere	*new_sphere;

	new_sphere = create_sphere(line, scene);
	add_sphere(new_sphere, scene);
}

void			delete_spheres(t_scene *scene)
{
	t_sphere *p;
	t_sphere *q;

	p = scene->spheres;
	while (p != NULL)
	{
		q = p->next;
		free(p);
		p = q;
	}
	scene->spheres = NULL;
}
