/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dirlight.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pperea-d <pperea-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 16:50:05 by pperea-d          #+#    #+#             */
/*   Updated: 2021/02/07 16:55:00 by pperea-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void			add_dlight(t_dlight *dlight, t_scene *scene)
{
	t_dlight	*last;

	dlight->next = NULL;
	if (scene->dirlights == NULL)
		scene->dirlights = dlight;
	else
	{
		last = scene->dirlights;
		while (last->next != NULL)
			last = last->next;
		last->next = dlight;
	}
}

t_dlight		*create_dlight(char *line, t_scene *scene)
{
	t_dlight	*dlight;

	if (!(dlight = malloc(sizeof(t_dlight))))
		exit_error_msg(DEF_ERR, scene);
	line += 2;
	dlight->orientation = get_vec3(&line, scene);
	if (dlight->orientation.x < -1 || dlight->orientation.y < -1 ||
	dlight->orientation.z < -1 || dlight->orientation.x > 1 ||
	dlight->orientation.y > 1 || dlight->orientation.z > 1)
		exit_error_msg(FILE_ERR, scene);
	dlight->intensity = get_double(&line, scene);
	dlight->color = get_color(&line, scene);
	skip_blanks(&line);
	if (*line == '\0')
		return (dlight);
	else
	{
		exit_error_msg(FILE_ERR, scene);
		return (0);
	}
}

void			read_dir_light(char *line, t_scene *scene)
{
	t_dlight	*new_dlight;

	new_dlight = create_dlight(line, scene);
	add_dlight(new_dlight, scene);
}

void			delete_dlights(t_scene *scene)
{
	t_dlight *p;
	t_dlight *q;

	p = scene->dirlights;
	while (p != NULL)
	{
		q = p->next;
		free(p);
		p = q;
	}
	scene->dirlights = NULL;
}
