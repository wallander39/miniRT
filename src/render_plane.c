/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_plane.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pperea-d <pperea-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/31 18:51:11 by pperea-d          #+#    #+#             */
/*   Updated: 2021/02/06 10:23:59 by pperea-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double		intersect_plane(t_ray *ray, t_plane *aux)
{
	double	t;
	t_vec3	v;
	double	den;

	t = 0;
	aux->normal = norm(aux->normal);
	den = dot_prod(ray->direction, aux->normal);
	if (fabs(den) > pow(10, -6))
	{
		v = sub_vec3(aux->point, ray->origin);
		t = dot_prod(v, aux->normal) / den;
	}
	if (t > 0)
		return (t);
	else
		return (0);
}

void		render_plane(t_ray *ray, t_scene *scene, t_plane *aux)
{
	double	t;
	t_hit	p;

	if ((t = intersect_plane(ray, aux)))
	{
		if (t < ray->t)
		{
			ray->t = t - 0.001;
			p.point = sum_vec3(ray->origin, scal_vec3(ray->t, ray->direction));
			p.normal = aux->normal;
			p.normal = norm(p.normal);
			p.color = aux->color;
			ray->color = shading(scene, &p);
		}
	}
}
