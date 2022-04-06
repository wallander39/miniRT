/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movesp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pperea-d <pperea-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 19:35:25 by pperea-d          #+#    #+#             */
/*   Updated: 2021/02/06 19:36:16 by pperea-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void			tras_sp2(int keycode, t_scene *scene)
{
	if (keycode == 126)
	{
		scene->aux_sph->center.y = scene->aux_sph->center.y + 0.5;
		threats(scene);
		mlx_put_image_to_window(scene->mlx,
		scene->mlx_win, scene->img.img, 0, 0);
	}
	if (keycode == 125)
	{
		scene->aux_sph->center.y = scene->aux_sph->center.y - 0.5;
		threats(scene);
		mlx_put_image_to_window(scene->mlx,
		scene->mlx_win, scene->img.img, 0, 0);
	}
}

void			tras_sp(int keycode, t_scene *scene)
{
	if (keycode == 124)
	{
		scene->aux_sph->center.x = scene->aux_sph->center.x + 0.5;
		threats(scene);
		mlx_put_image_to_window(scene->mlx,
		scene->mlx_win, scene->img.img, 0, 0);
	}
	if (keycode == 123)
	{
		scene->aux_sph->center.x = scene->aux_sph->center.x - 0.5;
		threats(scene);
		mlx_put_image_to_window(scene->mlx,
		scene->mlx_win, scene->img.img, 0, 0);
	}
	tras_sp2(keycode, scene);
}

void			rot_sp(int keycode, t_scene *scene)
{
	if (keycode == 125)
	{
		scene->aux_sph->center.z = scene->aux_sph->center.z + 0.5;
		threats(scene);
		mlx_put_image_to_window(scene->mlx,
		scene->mlx_win, scene->img.img, 0, 0);
	}
	if (keycode == 126)
	{
		scene->aux_sph->center.z = scene->aux_sph->center.z - 0.5;
		threats(scene);
		mlx_put_image_to_window(scene->mlx,
		scene->mlx_win, scene->img.img, 0, 0);
	}
}

void			move_sp(int keycode, t_scene *scene)
{
	if (scene->shift == 0)
		tras_sp(keycode, scene);
	else if (scene->shift == 1)
		rot_sp(keycode, scene);
}
