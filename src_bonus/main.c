/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pperea-d <pperea-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 18:05:14 by pperea-d          #+#    #+#             */
/*   Updated: 2021/02/10 17:25:32 by pperea-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void			key_hook2(int keycode, t_scene *scene)
{
	if (scene->cam_act == 1)
		move_cam(keycode, scene);
	else if (scene->cam_act == 2)
		move_sp(keycode, scene);
	else if (scene->cam_act == 3)
		move_cy(keycode, scene);
	else if (scene->cam_act == 4)
		move_pl(keycode, scene);
	else if (scene->cam_act == 5)
		move_tr(keycode, scene);
}

int				key_hook(int keycode, t_scene *scene)
{
	if (keycode == 3)
		fil_render(scene);
	if (keycode == 257)
		scene->shift = 1;
	else if (keycode == 53)
		close_render(scene);
	else if (keycode == 49)
		change_cam(scene);
	else if (keycode == 40)
	{
		scene->cam_act = 1;
		ft_printf("camera selected\n");
	}
	else if (keycode == 1)
		sp_select(scene);
	else if (keycode == 8)
		cy_select(scene);
	else if (keycode == 35)
		pl_select(scene);
	else if (keycode == 17)
		tr_select(scene);
	key_hook2(keycode, scene);
	return (1);
}

int				shift_off(int keycode, t_scene *scene)
{
	if (keycode == 257)
		scene->shift = 0;
	return (0);
}

void			display_scene(t_scene *scene)
{
	t_display	img;

	scene->mlx_win = mlx_new_window(scene->mlx, scene->res.width,
	scene->res.heigth, "miniRT");
	img.img = mlx_new_image(scene->mlx, scene->res.width, scene->res.heigth);
	img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.length, &img.end);
	scene->img = img;
	scene->aux_cam = scene->cams;
	mlx_hook(scene->mlx_win, 17, 0L, close_render, scene);
	mlx_hook(scene->mlx_win, 3, 1L << 1, shift_off, scene);
	mlx_hook(scene->mlx_win, 2, 1L << 0, key_hook, scene);
	threats(scene);
	mlx_put_image_to_window(scene->mlx, scene->mlx_win, img.img, 0, 0);
	mlx_loop(scene->mlx);
}

int				main(int argc, char **argv)
{
	t_scene		scene;

	init_scene(&scene);
	checker(argc, argv, &scene);
	if (!(scene.mlx = mlx_init()))
		exit_error_msg(DEF_ERR, &scene);
	read_file(argv[1], &scene);
	if (scene.res.declared == 0 ||
	scene.amb.declared == 0 || scene.num_cam == 0)
		exit_error_msg(FILE_ERR, &scene);
	if (scene.save == 1)
		save_image_bmp(&scene);
	else
		display_scene(&scene);
	return (0);
}
