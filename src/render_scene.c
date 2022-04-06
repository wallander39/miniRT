/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_scene.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pperea-d <pperea-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 22:00:40 by pperea-d          #+#    #+#             */
/*   Updated: 2021/02/06 10:23:52 by pperea-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	ray_generator(t_ray *ray, t_scene *scene, double i, double j)
{
	double	aspectratio;
	double	px;
	double	py;

	aspectratio = (double)scene->res.width / (double)scene->res.heigth;
	px = (2 * ((i + 0.5) / (double)scene->res.width) - 1)
	* tan(scene->aux_cam->fov / 2 * M_PI / 180) * aspectratio;
	py = (1 - 2 * (j + 0.5) / scene->res.heigth)
	* tan(scene->aux_cam->fov / 2 * M_PI / 180);
	ray->origin = new_vec3(0, 0, 0);
	ray->direction = new_vec3(px, py, -1);
	ray->origin = sum_vec3(ray->origin, scene->aux_cam->position);
	ray->direction = prod_vec3_mat3(ray->direction, scene->cam_rot);
	ray->direction = norm(ray->direction);
	ray->t = DBL_MAX;
	ray->color = (t_color){0, 0, 0};
}

void	my_pixels_put(char **dst, t_ray *ray)
{
	**dst = (char)floor(ray->color.b);
	(*dst)++;
	**dst = (char)floor(ray->color.g);
	(*dst)++;
	**dst = (char)floor(ray->color.r);
	(*dst)++;
	(*dst)++;
}

t_color	ray_cast2(t_ray *ray, t_scene *scene)
{
	void	*aux;

	aux = scene->cylinders;
	while (aux)
	{
		render_cyl(ray, scene, (t_cylinder *)aux);
		aux = ((t_cylinder *)aux)->next;
	}
	aux = scene->squares;
	while (aux)
	{
		render_square(ray, scene, (t_square *)aux);
		aux = ((t_square *)aux)->next;
	}
	aux = scene->triangles;
	while (aux)
	{
		render_tr(ray, scene, (t_triangle *)aux);
		aux = ((t_triangle *)aux)->next;
	}
	return (shading(scene, &scene->p));
}

t_color	ray_cast(t_ray *ray, t_scene *scene)
{
	void *aux;

	aux = scene->spheres;
	while (aux)
	{
		render_sphere(ray, scene, (t_sphere *)aux);
		aux = ((t_sphere *)aux)->next;
	}
	aux = scene->planes;
	while (aux)
	{
		render_plane(ray, scene, (t_plane *)aux);
		aux = ((t_plane *)aux)->next;
	}
	return (ray_cast2(ray, scene));
}

void	render_scene(t_scene *scene)
{
	t_ray	ray;
	char	*dst;
	int		i;
	int		j;

	dst = scene->img.addr;
	cam_rot_matrix(scene);
	j = 0;
	while (j < scene->res.heigth)
	{
		i = 0;
		while (i < scene->res.width)
		{
			ray_generator(&ray, scene, (double)i, (double)j);
			ray_cast(&ray, scene);
			my_pixels_put(&dst, &ray);
			i++;
		}
		j++;
	}
}
