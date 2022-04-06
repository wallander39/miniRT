/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camrot.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pperea-d <pperea-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 16:49:50 by pperea-d          #+#    #+#             */
/*   Updated: 2021/02/04 16:50:05 by pperea-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	look_at(t_scene *scene)
{
	t_vec3		forward;
	t_vec3		right;
	t_vec3		up;
	t_vec3		tmp;

	tmp = new_vec3(0, 1, 0);
	forward = scal_vec3(-1, scene->aux_cam->orientation);
	right = norm(cross_prod(tmp, forward));
	up = norm(cross_prod(forward, right));
	scene->cam_rot = new_mat3(right, up, forward);
}

void	cam_rot_matrix(t_scene *scene)
{
	t_vec3		forward;
	t_vec3		right;
	t_vec3		up;

	if (scene->aux_cam->orientation.x == 0 && scene->aux_cam->orientation.y == 1
	&& scene->aux_cam->orientation.z == 0)
	{
		right = new_vec3(1, 0, 0);
		up = new_vec3(0, 0, 1);
		forward = new_vec3(0, -1, 0);
		scene->cam_rot = new_mat3(right, up, forward);
	}
	else if (scene->aux_cam->orientation.x == 0 &&
	scene->aux_cam->orientation.y == -1
	&& scene->aux_cam->orientation.z == 0)
	{
		right = new_vec3(1, 0, 0);
		up = new_vec3(0, 0, -1);
		forward = new_vec3(0, 1, 0);
		scene->cam_rot = new_mat3(right, up, forward);
	}
	else
		look_at(scene);
}
