/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadows1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pperea-d <pperea-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 17:21:22 by pperea-d          #+#    #+#             */
/*   Updated: 2021/02/06 10:00:36 by pperea-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int		blocker(t_ray *shadow_ray, t_vec3 light_pos)
{
	t_vec3	sh_point;
	double	point_dist;
	double	light_dist;

	sh_point = sum_vec3(shadow_ray->origin,
	scal_vec3(shadow_ray->t, shadow_ray->direction));
	point_dist = mod_vec3(sub_vec3(sh_point, shadow_ray->origin));
	light_dist = mod_vec3(sub_vec3(light_pos, shadow_ray->origin));
	if (point_dist > 0.0001 && point_dist < light_dist)
		return (1);
	return (0);
}

int		shad_3(t_scene *scene, t_ray *shadow_ray, t_vec3 light_pos)
{
	void	*obj;

	obj = scene->triangles;
	while (obj)
	{
		if ((shadow_ray->t = intersect_triangle(shadow_ray, (t_triangle *)obj)))
			if (blocker(shadow_ray, light_pos))
				return (1);
		obj = ((t_triangle *)obj)->next;
	}
	return (0);
}

int		shad_2(t_scene *scene, t_ray *shadow_ray, t_vec3 light_pos)
{
	void	*obj;

	obj = scene->cylinders;
	while (obj)
	{
		if ((shadow_ray->t = intersect_cylinder(shadow_ray, (t_cylinder *)obj)))
			if (blocker(shadow_ray, light_pos))
				return (1);
		if ((shadow_ray->t = intersect_caps(shadow_ray, (t_cylinder *)obj)))
			if (blocker(shadow_ray, light_pos))
				return (1);
		obj = ((t_cylinder*)obj)->next;
	}
	obj = scene->squares;
	while (obj)
	{
		if ((shadow_ray->t = intersect_square(shadow_ray, (t_square *)obj)))
			if (blocker(shadow_ray, light_pos))
				return (1);
		obj = ((t_square*)obj)->next;
	}
	return (shad_3(scene, shadow_ray, light_pos));
}

int		shad_1(t_scene *scene, t_ray *shadow_ray, t_vec3 light_pos)
{
	void	*obj;

	obj = scene->spheres;
	while (obj)
	{
		if ((shadow_ray->t = intersect_sphere3(shadow_ray, (t_sphere *)obj)))
		{
			if (blocker(shadow_ray, light_pos))
				return (1);
		}
		obj = ((t_sphere*)obj)->next;
	}
	obj = scene->planes;
	while (obj)
	{
		if ((shadow_ray->t = intersect_plane(shadow_ray, (t_plane *)obj)))
			if (blocker(shadow_ray, light_pos))
				return (1);
		obj = ((t_plane*)obj)->next;
	}
	return (shad_2(scene, shadow_ray, light_pos));
}
