/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pperea-d <pperea-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/01 20:01:53 by pperea-d          #+#    #+#             */
/*   Updated: 2021/02/04 15:39:01 by pperea-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void			add_cylinder(t_cylinder *cylinder, t_scene *scene)
{
	t_cylinder	*last;

	cylinder->next = NULL;
	if (scene->cylinders == NULL)
	{
		scene->cylinders = cylinder;
	}
	else
	{
		last = scene->cylinders;
		while (last->next != NULL)
			last = last->next;
		last->next = cylinder;
	}
}

t_cylinder		*create_cylinder(char *line, t_scene *scene)
{
	t_cylinder	*cylinder;

	if (!(cylinder = malloc(sizeof(t_cylinder))))
		exit_error_msg(DEF_ERR, scene);
	line += 2;
	cylinder->point = get_vec3(&line, scene);
	cylinder->orientation = get_vec3(&line, scene);
	if (cylinder->orientation.x < -1 || cylinder->orientation.y < -1 ||
	cylinder->orientation.z < -1 || cylinder->orientation.x > 1 ||
	cylinder->orientation.y > 1 || cylinder->orientation.z > 1)
		exit_error_msg(FILE_ERR, scene);
	cylinder->diameter = get_double(&line, scene);
	cylinder->height = get_double(&line, scene);
	cylinder->color = get_color(&line, scene);
	skip_blanks(&line);
	if (*line == '\0')
		return (cylinder);
	else
	{
		exit_error_msg(FILE_ERR, scene);
		return (0);
	}
}

void			read_cylinder(char *line, t_scene *scene)
{
	t_cylinder	*new_cylinder;

	new_cylinder = create_cylinder(line, scene);
	add_cylinder(new_cylinder, scene);
}

void			delete_cylinders(t_scene *scene)
{
	t_cylinder *p;
	t_cylinder *q;

	p = scene->cylinders;
	while (p != NULL)
	{
		q = p->next;
		free(p);
		p = q;
	}
	scene->cylinders = NULL;
}
