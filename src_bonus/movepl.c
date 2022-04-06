/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movepl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pperea-d <pperea-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 19:42:39 by pperea-d          #+#    #+#             */
/*   Updated: 2021/02/06 19:43:12 by pperea-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void			rot_pl(int keycode, t_scene *scene)
{
	if (keycode == 6)
	{
		scene->aux_pl->normal = rot_z_axis(scene->aux_pl->normal);
		threats(scene);
		mlx_put_image_to_window(scene->mlx,
		scene->mlx_win, scene->img.img, 0, 0);
	}
	if (keycode == 7)
	{
		scene->aux_pl->normal = rot_x_axis(scene->aux_pl->normal);
		threats(scene);
		mlx_put_image_to_window(scene->mlx,
		scene->mlx_win, scene->img.img, 0, 0);
	}
	if (keycode == 16)
	{
		scene->aux_pl->normal = rot_y_axis(scene->aux_pl->normal);
		threats(scene);
		mlx_put_image_to_window(scene->mlx,
		scene->mlx_win, scene->img.img, 0, 0);
	}
}

void			tras_pl2(int keycode, t_scene *scene)
{
	if (keycode == 126)
	{
		scene->aux_pl->point.y = scene->aux_pl->point.y + 0.5;
		threats(scene);
		mlx_put_image_to_window(scene->mlx,
		scene->mlx_win, scene->img.img, 0, 0);
	}
	if (keycode == 125)
	{
		scene->aux_pl->point.y = scene->aux_pl->point.y - 0.5;
		threats(scene);
		mlx_put_image_to_window(scene->mlx,
		scene->mlx_win, scene->img.img, 0, 0);
	}
}

void			tras_pl(int keycode, t_scene *scene)
{
	if (keycode == 124)
	{
		scene->aux_pl->point.x = scene->aux_pl->point.x + 0.5;
		threats(scene);
		mlx_put_image_to_window(scene->mlx,
		scene->mlx_win, scene->img.img, 0, 0);
	}
	if (keycode == 123)
	{
		scene->aux_pl->point.x = scene->aux_pl->point.x - 0.5;
		threats(scene);
		mlx_put_image_to_window(scene->mlx,
		scene->mlx_win, scene->img.img, 0, 0);
	}
	tras_pl2(keycode, scene);
	rot_pl(keycode, scene);
}

void			tras2_pl(int keycode, t_scene *scene)
{
	if (keycode == 125)
	{
		scene->aux_pl->point.z = scene->aux_pl->point.z + 0.5;
		threats(scene);
		mlx_put_image_to_window(scene->mlx,
		scene->mlx_win, scene->img.img, 0, 0);
	}
	if (keycode == 126)
	{
		scene->aux_pl->point.z = scene->aux_pl->point.z - 0.5;
		threats(scene);
		mlx_put_image_to_window(scene->mlx,
		scene->mlx_win, scene->img.img, 0, 0);
	}
}

void			move_pl(int keycode, t_scene *scene)
{
	if (scene->shift == 0)
		tras_pl(keycode, scene);
	else if (scene->shift == 1)
		tras2_pl(keycode, scene);
}
