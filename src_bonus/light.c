/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pperea-d <pperea-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 20:39:49 by pperea-d          #+#    #+#             */
/*   Updated: 2021/02/04 15:54:10 by pperea-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void			add_light(t_light *light, t_scene *scene)
{
	t_light	*last;

	light->next = NULL;
	if (scene->lights == NULL)
	{
		scene->lights = light;
	}
	else
	{
		last = scene->lights;
		while (last->next != NULL)
			last = last->next;
		last->next = light;
	}
}

t_light			*create_light(char *line, t_scene *scene)
{
	t_light	*light;

	if (!(light = malloc(sizeof(t_light))))
		exit_error_msg(DEF_ERR, scene);
	line += 2;
	light->point = get_vec3(&line, scene);
	light->intensity = get_double(&line, scene);
	if (light->intensity < 0 || light->intensity > 1)
		exit_error_msg(FILE_ERR, scene);
	light->color = get_color(&line, scene);
	skip_blanks(&line);
	if (*line == '\0')
		return (light);
	else
	{
		exit_error_msg(FILE_ERR, scene);
		return (0);
	}
}

void			read_light(char *line, t_scene *scene)
{
	t_light	*new_light;

	new_light = create_light(line, scene);
	add_light(new_light, scene);
}

void			delete_lights(t_scene *scene)
{
	t_light *p;
	t_light *q;

	p = scene->lights;
	while (p != NULL)
	{
		q = p->next;
		free(p);
		p = q;
	}
	scene->lights = NULL;
}
