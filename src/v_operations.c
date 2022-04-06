/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_operations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pperea-d <pperea-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 20:23:03 by pperea-d          #+#    #+#             */
/*   Updated: 2021/02/03 15:59:35 by pperea-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double		mod_vec3(t_vec3 a)
{
	double	v;

	v = sqrt(a.x * a.x + a.y * a.y + a.z * a.z);
	return (v);
}

t_vec3		norm(t_vec3 a)
{
	t_vec3	v;
	double	m;

	m = mod_vec3(a);
	v.x = a.x / m;
	v.y = a.y / m;
	v.z = a.z / m;
	return (v);
}

t_vec3		new_vec3(double a, double b, double c)
{
	t_vec3	v;

	v.x = a;
	v.y = b;
	v.z = c;
	return (v);
}

t_mat3		new_mat3(t_vec3 a, t_vec3 b, t_vec3 c)
{
	t_mat3	m;

	m.u = a;
	m.v = b;
	m.w = c;
	return (m);
}

t_vec3		sum_vec3(t_vec3 a, t_vec3 b)
{
	t_vec3	c;

	c.x = a.x + b.x;
	c.y = a.y + b.y;
	c.z = a.z + b.z;
	return (c);
}
