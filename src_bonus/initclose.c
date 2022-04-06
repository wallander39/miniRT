/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initclose.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pperea-d <pperea-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 19:52:41 by pperea-d          #+#    #+#             */
/*   Updated: 2021/02/10 18:11:09 by pperea-d         ###   ########.fr       */
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

void			init_scene(t_scene *scene)
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
	scene->aux_sph = NULL;
	scene->aux_cyl = NULL;
	scene->aux_pl = NULL;
	scene->aux_tr = NULL;
	scene->cam_act = 0;
	scene->shift = 0;
	scene->filter = 0;
}
