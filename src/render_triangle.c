/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_triangle.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pperea-d <pperea-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 15:08:30 by pperea-d          #+#    #+#             */
/*   Updated: 2021/02/06 10:23:23 by pperea-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int		inside_test(t_triangle *aux, double t, t_ray *ray, t_plane *triangle)
{
	t_mat3	edge;
	t_mat3	c;
	t_vec3	p;

	p = scal_vec3(t, ray->direction);
	p = sum_vec3(ray->origin, p);
	edge.u = sub_vec3(aux->p2, aux->p1);
	edge.v = sub_vec3(aux->p3, aux->p2);
	edge.w = sub_vec3(aux->p1, aux->p3);
	c.u = sub_vec3(p, aux->p1);
	c.v = sub_vec3(p, aux->p2);
	c.w = sub_vec3(p, aux->p3);
	if (dot_prod(triangle->normal, cross_prod(edge.u, c.u)) > 0 &&
		dot_prod(triangle->normal, cross_prod(edge.v, c.v)) > 0 &&
		dot_prod(triangle->normal, cross_prod(edge.w, c.w)) > 0)
		return (1);
	else
		return (0);
}

int		intersect_triangle(t_ray *ray, t_triangle *aux)
{
	double	t;
	t_vec3	v1;
	t_vec3	v2;
	t_plane	tr;

	v1 = sub_vec3(aux->p2, aux->p1);
	v2 = sub_vec3(aux->p3, aux->p1);
	tr.point = aux->p1;
	tr.normal = cross_prod(v1, v2);
	tr.normal = norm(tr.normal);
	if ((t = intersect_plane(ray, &tr)))
		if (inside_test(aux, t, ray, &tr))
			return (t);
	return (0);
}

void	render_tr(t_ray *ray, t_scene *scene, t_triangle *aux)
{
	double	t;
	t_vec3	v1;
	t_vec3	v2;
	t_hit	p;

	if ((t = intersect_triangle(ray, aux)))
	{
		if (t < ray->t)
		{
			ray->t = t - 0.001;
			v1 = sub_vec3(aux->p2, aux->p1);
			v2 = sub_vec3(aux->p3, aux->p1);
			p.normal = cross_prod(v1, v2);
			p.normal = dot_prod(p.normal, ray->direction) < 0 ?
			p.normal : scal_vec3(-1, p.normal);
			p.normal = norm(p.normal);
			p.point = sum_vec3(ray->origin, scal_vec3(ray->t, ray->direction));
			p.color = aux->color;
			ray->color = shading(scene, &p);
		}
	}
}
