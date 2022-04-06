/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movecam.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pperea-d <pperea-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 19:30:01 by pperea-d          #+#    #+#             */
/*   Updated: 2021/02/06 19:32:20 by pperea-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void			tras_cam2(int keycode, t_scene *scene)
{
	t_mat3	cam;

	cam = cam_rot_display(scene);
	if (keycode == 125)
	{
		scene->aux_cam->position = sub_vec3(scene->aux_cam->position, cam.v);
		threats(scene);
		mlx_put_image_to_window(scene->mlx,
		scene->mlx_win, scene->img.img, 0, 0);
	}
	else if (keycode == 31)
	{
		scene->aux_cam->position = sub_vec3(scene->aux_cam->position, cam.w);
		threats(scene);
		mlx_put_image_to_window(scene->mlx,
		scene->mlx_win, scene->img.img, 0, 0);
	}
	else if (keycode == 37)
	{
		scene->aux_cam->position = sum_vec3(scene->aux_cam->position, cam.w);
		threats(scene);
		mlx_put_image_to_window(scene->mlx,
		scene->mlx_win, scene->img.img, 0, 0);
	}
}

void			tras_cam(int keycode, t_scene *scene)
{
	t_mat3	cam;

	cam = cam_rot_display(scene);
	if (keycode == 124)
	{
		scene->aux_cam->position = sum_vec3(scene->aux_cam->position, cam.u);
		threats(scene);
		mlx_put_image_to_window(scene->mlx,
		scene->mlx_win, scene->img.img, 0, 0);
	}
	else if (keycode == 126)
	{
		scene->aux_cam->position = sum_vec3(scene->aux_cam->position, cam.v);
		threats(scene);
		mlx_put_image_to_window(scene->mlx,
		scene->mlx_win, scene->img.img, 0, 0);
	}
	else if (keycode == 123)
	{
		scene->aux_cam->position = sub_vec3(scene->aux_cam->position, cam.u);
		threats(scene);
		mlx_put_image_to_window(scene->mlx,
		scene->mlx_win, scene->img.img, 0, 0);
	}
	tras_cam2(keycode, scene);
}

void			rot_move_cam2(int keycode, t_scene *scene)
{
	t_mat3	cam;
	t_vec3	local_cam;
	t_vec3	aux_vec;

	local_cam = new_vec3(0, 0, -1);
	cam = cam_rot_display(scene);
	if (keycode == 126)
	{
		aux_vec = rotneg_x_axis(local_cam);
		scene->aux_cam->orientation = prod_vec3_mat3(aux_vec, cam);
		threats(scene);
		mlx_put_image_to_window(scene->mlx,
		scene->mlx_win, scene->img.img, 0, 0);
	}
	else if (keycode == 124)
	{
		aux_vec = rotneg_y_axis(local_cam);
		scene->aux_cam->orientation = prod_vec3_mat3(aux_vec, cam);
		threats(scene);
		mlx_put_image_to_window(scene->mlx,
		scene->mlx_win, scene->img.img, 0, 0);
	}
}

void			rot_move_cam(int keycode, t_scene *scene)
{
	t_mat3	cam;
	t_vec3	local_cam;
	t_vec3	aux_vec;

	local_cam = new_vec3(0, 0, -1);
	cam = cam_rot_display(scene);
	if (keycode == 123)
	{
		aux_vec = rot_y_axis(local_cam);
		scene->aux_cam->orientation = prod_vec3_mat3(aux_vec, cam);
		threats(scene);
		mlx_put_image_to_window(scene->mlx,
		scene->mlx_win, scene->img.img, 0, 0);
	}
	else if (keycode == 125)
	{
		aux_vec = rot_x_axis(local_cam);
		scene->aux_cam->orientation = prod_vec3_mat3(aux_vec, cam);
		threats(scene);
		mlx_put_image_to_window(scene->mlx,
		scene->mlx_win, scene->img.img, 0, 0);
	}
	rot_move_cam2(keycode, scene);
}

void			move_cam(int keycode, t_scene *scene)
{
	if (scene->shift == 0)
		tras_cam(keycode, scene);
	else if (scene->shift == 1)
		rot_move_cam(keycode, scene);
}
