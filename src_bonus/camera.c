/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pperea-d <pperea-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/25 20:05:40 by pperea-d          #+#    #+#             */
/*   Updated: 2021/02/04 15:38:24 by pperea-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void		add_cam(t_camera *cam, t_scene *scene)
{
	t_camera	*last;

	cam->next = NULL;
	if (scene->cams == NULL)
	{
		scene->cams = cam;
	}
	else
	{
		last = scene->cams;
		while (last->next != NULL)
			last = last->next;
		last->next = cam;
	}
}

t_camera	*create_cam(char *line, t_scene *scene)
{
	t_camera	*cam;

	if (!(cam = malloc(sizeof(t_camera))))
		exit_error_msg(DEF_ERR, scene);
	line += 2;
	cam->position = get_vec3(&line, scene);
	cam->orientation = get_vec3(&line, scene);
	if (cam->orientation.x < -1 || cam->orientation.y < -1
	|| cam->orientation.z < -1 || cam->orientation.x > 1 ||
	cam->orientation.y > 1 || cam->orientation.z > 1)
		exit_error_msg(FILE_ERR, scene);
	cam->orientation = norm(cam->orientation);
	cam->fov = get_double(&line, scene);
	if (cam->fov < 0 || cam->fov > 180)
		exit_error_msg(FILE_ERR, scene);
	skip_blanks(&line);
	if (*line == '\0')
		return (cam);
	else
	{
		exit_error_msg(FILE_ERR, scene);
		return (0);
	}
}

void		read_cam(char *line, t_scene *scene)
{
	t_camera	*new_cam;

	new_cam = create_cam(line, scene);
	add_cam(new_cam, scene);
	scene->num_cam += 1;
}

void		delete_cams(t_scene *scene)
{
	t_camera *p;
	t_camera *q;

	p = scene->cams;
	while (p != NULL)
	{
		q = p->next;
		free(p);
		p = q;
	}
	scene->cams = NULL;
}
