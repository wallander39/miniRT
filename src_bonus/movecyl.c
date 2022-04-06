/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movecyl.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pperea-d <pperea-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 19:39:49 by pperea-d          #+#    #+#             */
/*   Updated: 2021/02/06 19:40:35 by pperea-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void			tras2_cy(int keycode, t_scene *scene)
{
	if (keycode == 125)
	{
		scene->aux_cyl->point.z = scene->aux_cyl->point.z + 0.5;
		threats(scene);
		mlx_put_image_to_window(scene->mlx,
		scene->mlx_win, scene->img.img, 0, 0);
	}
	if (keycode == 126)
	{
		scene->aux_cyl->point.z = scene->aux_cyl->point.z - 0.5;
		threats(scene);
		mlx_put_image_to_window(scene->mlx,
		scene->mlx_win, scene->img.img, 0, 0);
	}
}

void			rot_cy(int keycode, t_scene *scene)
{
	if (keycode == 6)
	{
		scene->aux_cyl->orientation = rot_z_axis(scene->aux_cyl->orientation);
		threats(scene);
		mlx_put_image_to_window(scene->mlx,
		scene->mlx_win, scene->img.img, 0, 0);
	}
	if (keycode == 7)
	{
		scene->aux_cyl->orientation = rot_x_axis(scene->aux_cyl->orientation);
		threats(scene);
		mlx_put_image_to_window(scene->mlx,
		scene->mlx_win, scene->img.img, 0, 0);
	}
	if (keycode == 16)
	{
		scene->aux_cyl->orientation = rot_y_axis(scene->aux_cyl->orientation);
		threats(scene);
		mlx_put_image_to_window(scene->mlx,
		scene->mlx_win, scene->img.img, 0, 0);
	}
}

void			tras_cy2(int keycode, t_scene *scene)
{
	if (keycode == 126)
	{
		scene->aux_cyl->point.y = scene->aux_cyl->point.y + 0.5;
		threats(scene);
		mlx_put_image_to_window(scene->mlx,
		scene->mlx_win, scene->img.img, 0, 0);
	}
	if (keycode == 125)
	{
		scene->aux_cyl->point.y = scene->aux_cyl->point.y - 0.5;
		threats(scene);
		mlx_put_image_to_window(scene->mlx,
		scene->mlx_win, scene->img.img, 0, 0);
	}
}

void			tras_cy(int keycode, t_scene *scene)
{
	if (keycode == 124)
	{
		scene->aux_cyl->point.x = scene->aux_cyl->point.x + 0.5;
		threats(scene);
		mlx_put_image_to_window(scene->mlx,
		scene->mlx_win, scene->img.img, 0, 0);
	}
	if (keycode == 123)
	{
		scene->aux_cyl->point.x = scene->aux_cyl->point.x - 0.5;
		threats(scene);
		mlx_put_image_to_window(scene->mlx,
		scene->mlx_win, scene->img.img, 0, 0);
	}
	tras_cy2(keycode, scene);
	rot_cy(keycode, scene);
}

void			move_cy(int keycode, t_scene *scene)
{
	if (scene->shift == 0)
		tras_cy(keycode, scene);
	else if (scene->shift == 1)
		tras2_cy(keycode, scene);
}
