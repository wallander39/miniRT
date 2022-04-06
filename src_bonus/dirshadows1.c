/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dirshadows1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pperea-d <pperea-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 20:26:43 by pperea-d          #+#    #+#             */
/*   Updated: 2021/02/08 10:27:16 by pperea-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int		dir_blocker(t_ray *shadow_ray)
{
	t_vec3	sh_point;
	double	point_dist;

	sh_point = sum_vec3(shadow_ray->origin,
	scal_vec3(shadow_ray->t, shadow_ray->direction));
	point_dist = mod_vec3(sub_vec3(sh_point, shadow_ray->origin));
	if (point_dist > 0.0001)
		return (1);
	return (0);
}

int		dir_shadows_3(t_scene *scene, t_ray *shadow_ray)
{
	void	*obj;

	obj = scene->triangles;
	while (obj)
	{
		if ((shadow_ray->t = intersect_triangle(shadow_ray, (t_triangle *)obj)))
			if (dir_blocker(shadow_ray))
				return (1);
		obj = ((t_triangle *)obj)->next;
	}
	return (0);
}

int		dir_shadows_2(t_scene *scene, t_ray *shadow_ray)
{
	void	*obj;

	obj = scene->cylinders;
	while (obj)
	{
		if ((shadow_ray->t = intersect_cylinder(shadow_ray, (t_cylinder *)obj)))
			if (dir_blocker(shadow_ray))
				return (1);
		if ((shadow_ray->t = intersect_caps(shadow_ray, (t_cylinder *)obj)))
			if (dir_blocker(shadow_ray))
				return (1);
		obj = ((t_cylinder*)obj)->next;
	}
	obj = scene->squares;
	while (obj)
	{
		if ((shadow_ray->t = intersect_square(shadow_ray, (t_square *)obj)))
			if (dir_blocker(shadow_ray))
				return (1);
		obj = ((t_square*)obj)->next;
	}
	return (dir_shadows_3(scene, shadow_ray));
}

int		dir_shadows_1(t_scene *scene, t_ray *shadow_ray)
{
	void	*obj;

	obj = scene->spheres;
	while (obj)
	{
		if ((shadow_ray->t = intersect_sphere3(shadow_ray, (t_sphere *)obj)))
			if (dir_blocker(shadow_ray))
				return (1);
		obj = ((t_sphere*)obj)->next;
	}
	obj = scene->planes;
	while (obj)
	{
		if ((shadow_ray->t = intersect_plane(shadow_ray, (t_plane *)obj)))
			if (dir_blocker(shadow_ray))
				return (1);
		obj = ((t_plane*)obj)->next;
	}
	return (dir_shadows_2(scene, shadow_ray));
}
