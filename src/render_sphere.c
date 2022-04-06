/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_sphere.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pperea-d <pperea-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 18:24:11 by pperea-d          #+#    #+#             */
/*   Updated: 2021/02/09 20:26:32 by pperea-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double		checksp(double t1, double t2)
{
	if ((t1 < 0) && (t2 < 0))
		return (0);
	else if (t1 <= t2 && t1 > 0)
		return (t1);
	else if (t2 <= t1 && t2 > 0)
		return (t2);
	else if (t2 > 0)
		return (t2);
	else
		return (t1);
}

double		intersect_sphere3(t_ray *ray, t_sphere *aux)
{
	t_vars	r;
	double	discr;
	double	t1;
	double	t2;
	t_vec3	v;

	v = sub_vec3(ray->origin, aux->center);
	r.a = 1;
	r.b = 2 * dot_prod(ray->direction, v);
	r.c = dot_prod(v, v) - (aux->diameter * aux->diameter / 4);
	discr = r.b * r.b - 4 * r.a * r.c;
	if (discr < 0)
		return (0);
	else if (discr == 0)
	{
		t1 = -r.b / 2;
		t2 = t1;
	}
	else
	{
		t1 = (-r.b + sqrt(discr)) / 2;
		t2 = (-r.b - sqrt(discr)) / 2;
	}
	return (checksp(t1, t2));
}

void		render_sphere(t_ray *ray, t_scene *scene, t_sphere *aux)
{
	double		t;
	t_hit		p;

	if ((t = intersect_sphere3(ray, aux)))
	{
		if (t < ray->t)
		{
			ray->t = t - 0.1;
			p.color = aux->color;
			p.point = sum_vec3(ray->origin, scal_vec3(ray->t, ray->direction));
			p.normal = sub_vec3(p.point, aux->center);
			p.normal = norm(p.normal);
			ray->color = shading(scene, &p);
		}
	}
}
