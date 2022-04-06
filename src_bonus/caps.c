/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   caps.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pperea-d <pperea-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 16:46:46 by pperea-d          #+#    #+#             */
/*   Updated: 2021/02/08 13:08:49 by pperea-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vec3		visible(t_ray *ray, t_cylinder *aux)
{
	t_vec3	p2;
	double	d1;
	double	d2;

	p2 = sum_vec3(aux->point, scal_vec3(aux->height, aux->orientation));
	d1 = mod_vec3(sub_vec3(ray->origin, aux->point));
	d2 = mod_vec3(sub_vec3(ray->origin, p2));
	if (d1 > d2)
		return (p2);
	return (aux->point);
}

double		intersect_caps(t_ray *ray, t_cylinder *aux)
{
	t_plane		cap;
	double		t;
	t_hit		p;

	cap.normal = aux->orientation;
	cap.point = visible(ray, aux);
	if ((t = intersect_plane(ray, &cap)))
	{
		p.point = sum_vec3(ray->origin, scal_vec3(t, ray->direction));
		if (mod_vec3(sub_vec3(p.point, cap.point)) < ((aux->diameter) / 2))
			return (t);
	}
	return (0);
}

void		render_caps(t_ray *ray, t_scene *scene, t_cylinder *aux)
{
	double		t;
	t_hit		p;

	if ((t = intersect_caps(ray, aux)))
	{
		if (t < ray->t)
		{
			ray->t = t - 0.1;
			p.point = sum_vec3(ray->origin, scal_vec3(ray->t, ray->direction));
			p.normal = dot_prod(aux->orientation, ray->direction) < 0
			? aux->orientation : scal_vec3(-1, aux->orientation);
			p.normal = norm(p.normal);
			p.color = aux->color;
			p.specular = aux->specular;
			p.reflect = aux->reflect;
			ray->color = shading(scene, &p, ray);
		}
	}
}
