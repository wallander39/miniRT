/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_square.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pperea-d <pperea-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 18:12:06 by pperea-d          #+#    #+#             */
/*   Updated: 2021/02/06 10:23:32 by pperea-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int		in_square(t_square *aux, t_vec3 point)
{
	t_vec3	x;
	t_vec3	y;

	x = new_vec3(1, 0, 0);
	y = cross_prod(aux->orientation, x);
	x = cross_prod(y, aux->orientation);
	if (mod_vec3(y) == 0)
	{
		x = new_vec3(0, 1, 0);
		y = cross_prod(aux->orientation, x);
		x = cross_prod(y, aux->orientation);
	}
	x = norm(x);
	y = norm(y);
	if (fabs(dot_prod(x, sub_vec3(point, aux->point))) <= aux->height / 2
	&& fabs(dot_prod(y, sub_vec3(point, aux->point))) <= aux->height / 2)
		return (1);
	return (0);
}

double	intersect_square(t_ray *ray, t_square *square)
{
	double	t;
	t_hit	p;
	t_plane	pl_sq;

	pl_sq.point = square->point;
	pl_sq.normal = square->orientation;
	if ((t = intersect_plane(ray, &pl_sq)))
	{
		p.point = sum_vec3(ray->origin, scal_vec3(t, ray->direction));
		if (in_square(square, p.point))
			return (t);
	}
	return (0);
}

void	render_square(t_ray *ray, t_scene *scene, t_square *aux)
{
	double	t;
	t_hit	p;
	t_plane	sq;

	sq.point = aux->point;
	sq.normal = aux->orientation;
	if ((t = intersect_square(ray, aux)))
	{
		if (t < ray->t)
		{
			ray->t = t - 0.01;
			p.point = sum_vec3(ray->origin, scal_vec3(ray->t, ray->direction));
			p.normal = dot_prod(sq.normal, ray->direction) < 0 ?
			sq.normal : scal_vec3(-1, sq.normal);
			p.normal = norm(p.normal);
			p.color = aux->color;
			ray->color = shading(scene, &p);
		}
	}
}
