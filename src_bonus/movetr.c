/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movetr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pperea-d <pperea-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 19:44:58 by pperea-d          #+#    #+#             */
/*   Updated: 2021/02/06 19:50:20 by pperea-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void			tras_tr2(int keycode, t_scene *scene)
{
	if (keycode == 126)
	{
		scene->aux_tr->p1.y = scene->aux_tr->p1.y + 0.5;
		scene->aux_tr->p2.y = scene->aux_tr->p2.y + 0.5;
		scene->aux_tr->p3.y = scene->aux_tr->p3.y + 0.5;
		threats(scene);
		mlx_put_image_to_window(scene->mlx,
		scene->mlx_win, scene->img.img, 0, 0);
	}
	if (keycode == 125)
	{
		scene->aux_tr->p1.y = scene->aux_tr->p1.y - 0.5;
		scene->aux_tr->p2.y = scene->aux_tr->p2.y - 0.5;
		scene->aux_tr->p3.y = scene->aux_tr->p3.y - 0.5;
		threats(scene);
		mlx_put_image_to_window(scene->mlx,
		scene->mlx_win, scene->img.img, 0, 0);
	}
}

void			tras_tr(int keycode, t_scene *scene)
{
	if (keycode == 124)
	{
		scene->aux_tr->p1.x = scene->aux_tr->p1.x + 0.5;
		scene->aux_tr->p2.x = scene->aux_tr->p2.x + 0.5;
		scene->aux_tr->p3.x = scene->aux_tr->p3.x + 0.5;
		threats(scene);
		mlx_put_image_to_window(scene->mlx,
		scene->mlx_win, scene->img.img, 0, 0);
	}
	if (keycode == 123)
	{
		scene->aux_tr->p1.x = scene->aux_tr->p1.x - 0.5;
		scene->aux_tr->p2.x = scene->aux_tr->p2.x - 0.5;
		scene->aux_tr->p3.x = scene->aux_tr->p3.x - 0.5;
		threats(scene);
		mlx_put_image_to_window(scene->mlx,
		scene->mlx_win, scene->img.img, 0, 0);
	}
	tras_tr2(keycode, scene);
	rot_tr(keycode, scene);
}

void			tras2_tr(int keycode, t_scene *scene)
{
	if (keycode == 125)
	{
		scene->aux_tr->p1.z = scene->aux_tr->p1.z + 0.5;
		scene->aux_tr->p2.z = scene->aux_tr->p2.z + 0.5;
		scene->aux_tr->p3.z = scene->aux_tr->p3.z + 0.5;
		threats(scene);
		mlx_put_image_to_window(scene->mlx,
		scene->mlx_win, scene->img.img, 0, 0);
	}
	if (keycode == 126)
	{
		scene->aux_tr->p1.z = scene->aux_tr->p1.z - 0.5;
		scene->aux_tr->p2.z = scene->aux_tr->p2.z - 0.5;
		scene->aux_tr->p3.z = scene->aux_tr->p3.z - 0.5;
		threats(scene);
		mlx_put_image_to_window(scene->mlx,
		scene->mlx_win, scene->img.img, 0, 0);
	}
}

void			move_tr(int keycode, t_scene *scene)
{
	if (scene->shift == 0)
		tras_tr(keycode, scene);
	else if (scene->shift == 1)
		tras2_tr(keycode, scene);
}
