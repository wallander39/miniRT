/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_operations2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pperea-d <pperea-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 15:59:56 by pperea-d          #+#    #+#             */
/*   Updated: 2021/02/03 16:04:00 by pperea-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vec3		sub_vec3(t_vec3 a, t_vec3 b)
{
	t_vec3	c;

	c.x = a.x - b.x;
	c.y = a.y - b.y;
	c.z = a.z - b.z;
	return (c);
}

t_vec3		prod_vec3_mat3(t_vec3 a, t_mat3 m)
{
	t_vec3	v;

	v.x = a.x * m.u.x + a.y * m.v.x + a.z * m.w.x;
	v.y = a.x * m.u.y + a.y * m.v.y + a.z * m.w.y;
	v.z = a.x * m.u.z + a.y * m.v.z + a.z * m.w.z;
	return (v);
}

t_vec3		cross_prod(t_vec3 a, t_vec3 b)
{
	t_vec3	c;

	c.x = a.y * b.z - a.z * b.y;
	c.y = a.z * b.x - a.x * b.z;
	c.z = a.x * b.y - a.y * b.x;
	return (c);
}

t_vec3		scal_vec3(double c, t_vec3 a)
{
	t_vec3	v;

	v.x = c * a.x;
	v.y = c * a.y;
	v.z = c * a.z;
	return (v);
}

double		dot_prod(t_vec3 a, t_vec3 b)
{
	double	s;

	s = a.x * b.x + a.y * b.y + a.z * b.z;
	return (s);
}
