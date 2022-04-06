/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camrot.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pperea-d <pperea-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 16:49:50 by pperea-d          #+#    #+#             */
/*   Updated: 2021/02/06 12:27:11 by pperea-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_mat3	look_at_display(t_scene *scene)
{
	t_vec3		forward;
	t_vec3		right;
	t_vec3		up;
	t_vec3		tmp;
	t_mat3		cam;

	tmp = new_vec3(0, 1, 0);
	forward = scal_vec3(-1, scene->aux_cam->orientation);
	right = norm(cross_prod(tmp, forward));
	up = norm(cross_prod(forward, right));
	cam = new_mat3(right, up, forward);
	return (cam);
}

t_mat3	cam_rot_display(t_scene *scene)
{
	t_vec3		forward;
	t_vec3		right;
	t_vec3		up;
	t_mat3		cam;

	if (scene->aux_cam->orientation.x == 0 &&
	scene->aux_cam->orientation.y == 1 && scene->aux_cam->orientation.z == 0)
	{
		right = new_vec3(1, 0, 0);
		up = new_vec3(0, 0, 1);
		forward = new_vec3(0, -1, 0);
		return (cam = new_mat3(right, up, forward));
	}
	else if (scene->aux_cam->orientation.x == 0
	&& scene->aux_cam->orientation.y == -1 &&
	scene->aux_cam->orientation.z == 0)
	{
		right = new_vec3(1, 0, 0);
		up = new_vec3(0, 0, -1);
		forward = new_vec3(0, 1, 0);
		return (cam = new_mat3(right, up, forward));
	}
	else
		return (cam = look_at_display(scene));
}

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

void	ray_generator(t_ray *ray, t_scene *scene, double i, double j)
{
	double	aspectratio;
	double	px;
	double	py;

	aspectratio = (double)scene->res.width / (double)scene->res.heigth;
	px = (2 * ((i + 0.5) / (double)scene->res.width) - 1)
	* tan(scene->aux_cam->fov / 2 * M_PI / 180) * aspectratio;
	py = (1 - 2 * (j + 0.5) / scene->res.heigth)
	* tan(scene->aux_cam->fov / 2 * M_PI / 180);
	ray->origin = new_vec3(0, 0, 0);
	ray->direction = new_vec3(px, py, -1);
	ray->origin = sum_vec3(ray->origin, scene->aux_cam->position);
	ray->direction = prod_vec3_mat3(ray->direction, scene->cam_rot);
	ray->direction = norm(ray->direction);
	ray->t = DBL_MAX;
	ray->color = (t_color){0, 0, 0};
}
