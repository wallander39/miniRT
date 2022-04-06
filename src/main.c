/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pperea-d <pperea-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 18:05:14 by pperea-d          #+#    #+#             */
/*   Updated: 2021/02/10 18:13:17 by pperea-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int				close_render(t_scene *scene)
{
	mlx_destroy_window(scene->mlx, scene->mlx_win);
	delete_scene(scene);
	exit(EXIT_FAILURE);
	return (0);
}

int				key_hook(int keycode, t_scene *scene)
{
	if (keycode == 53)
		close_render(scene);
	if (keycode == 49)
	{
		if (scene->aux_cam->next == NULL)
			scene->aux_cam = scene->cams;
		else
			scene->aux_cam = scene->aux_cam->next;
		render_scene(scene);
		mlx_put_image_to_window(scene->mlx, scene->mlx_win,
		scene->img.img, 0, 0);
	}
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
	mlx_hook(scene->mlx_win, 2, 1L << 0, key_hook, scene);
	render_scene(scene);
	mlx_put_image_to_window(scene->mlx, scene->mlx_win, img.img, 0, 0);
	mlx_loop(scene->mlx);
}

static void		init_scene(t_scene *scene)
{
	scene->save = 0;
	scene->res.declared = 0;
	scene->amb.declared = 0;
	scene->cams = NULL;
	scene->planes = NULL;
	scene->spheres = NULL;
	scene->squares = NULL;
	scene->triangles = NULL;
	scene->cylinders = NULL;
	scene->lights = NULL;
	scene->dirlights = NULL;
	scene->num_cam = 0;
	scene->aux_cam = NULL;
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
