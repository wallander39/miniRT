/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_cylinder.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pperea-d <pperea-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/03 18:44:00 by pperea-d          #+#    #+#             */
/*   Updated: 2021/02/06 10:24:11 by pperea-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double		checkt(double t1, double t2)
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

double		solve_quadratic2(double a, double b, double c)
{
	double	t1;
	double	t2;
	double	d;

	d = b * b - 4 * a * c;
	if (d < 0)
		return (0);
	else if (d == 0)
	{
		t1 = -b / (2 * a);
		t2 = t1;
	}
	else
	{
		t1 = (-b + sqrt(d)) / (2 * a);
		t2 = (-b - sqrt(d)) / (2 * a);
	}
	return (checkt(t1, t2));
}

double		intersect_cylinder(t_ray *ray, t_cylinder *aux)
{
	double	t;
	t_vec3	v;
	t_vec3	p;
	t_vars	r;
	double	cyl_m;

	r.a = dot_prod(ray->direction, aux->orientation);
	v = sub_vec3(ray->direction, scal_vec3(r.a, aux->orientation));
	r.a = dot_prod(v, v);
	p = sub_vec3(ray->origin, aux->point);
	r.b = dot_prod(p, aux->orientation);
	r.b = 2 * (dot_prod(v, sub_vec3(p, scal_vec3(dot_prod(p, aux->orientation),
	aux->orientation))));
	v = sub_vec3(p, scal_vec3(dot_prod(p, aux->orientation), aux->orientation));
	r.c = dot_prod(v, v) - (aux->diameter * aux->diameter / 4);
	t = solve_quadratic2(r.a, r.b, r.c);
	p = sum_vec3(ray->origin, scal_vec3(t, ray->direction));
	cyl_m = dot_prod(aux->orientation, sub_vec3(p, aux->point));
	if (cyl_m > 0 && cyl_m < aux->height)
		return (t);
	return (0);
}

void		render_cyl(t_ray *ray, t_scene *scene, t_cylinder *aux)
{
	double	t;
	double	cyl_m;
	t_vec3	cyl_center;
	t_hit	p;

	aux->orientation = norm(aux->orientation);
	if ((t = intersect_cylinder(ray, aux)))
	{
		if (t < ray->t)
		{
			ray->t = t - 1;
			p.point = sum_vec3(ray->origin, scal_vec3(t, ray->direction));
			p.color = aux->color;
			cyl_m = dot_prod(aux->orientation, sub_vec3(p.point, aux->point));
			cyl_center = sum_vec3(aux->point,
			scal_vec3(cyl_m, aux->orientation));
			p.normal = norm(sub_vec3(p.point, cyl_center));
			ray->color = shading(scene, &p);
		}
	}
	render_caps(ray, scene, aux);
}
