/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shading.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pperea-d <pperea-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 20:20:12 by pperea-d          #+#    #+#             */
/*   Updated: 2021/02/04 14:30:25 by pperea-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	check_rgb_color(t_color *color)
{
	if (color->r > 255)
		color->r = 255;
	if (color->g > 255)
		color->g = 255;
	if (color->b > 255)
		color->b = 255;
}

t_color	add_amb(t_scene *s, t_color point)
{
	t_color	color;

	color.r = s->amb.intensity * s->amb.color.r * point.r / 255;
	color.g = s->amb.intensity * s->amb.color.g * point.g / 255;
	color.b = s->amb.intensity * s->amb.color.b * point.b / 255;
	return (color);
}

t_color	add_color(t_color a, t_color b)
{
	t_color	color;

	color.r = a.r + b.r;
	color.g = a.g + b.g;
	color.b = a.b + b.b;
	return (color);
}

t_color	diffuse(t_light *light, t_hit *p)
{
	t_color	color;
	double	diffuse;
	double	kd;

	diffuse = dot_prod(p->light, p->normal);
	if (diffuse < 0)
		kd = 0;
	else
		kd = 400 * light->intensity / (p->distance * p->distance);
	color.r = kd * light->color.r * (p->color.r * diffuse / 255);
	color.g = kd * light->color.g * (p->color.g * diffuse / 255);
	color.b = kd * light->color.b * (p->color.b * diffuse / 255);
	return (color);
}

t_color	shading(t_scene *scene, t_hit *p)
{
	t_color		color;
	t_light		*light;
	t_dlight	*dlight;

	light = scene->lights;
	dlight = scene->dirlights;
	color = add_amb(scene, p->color);
	while (light)
	{
		p->light = sub_vec3(light->point, p->point);
		p->distance = mod_vec3(p->light);
		p->light = norm(p->light);
		p->shadow_ray.direction = p->light;
		p->shadow_ray.origin = p->point;
		if (!shad_1(scene, &p->shadow_ray, light->point))
			color = add_color(color, diffuse(light, p));
		light = light->next;
	}
	check_rgb_color(&color);
	return (color);
}
