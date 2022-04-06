/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filters2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pperea-d <pperea-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 11:26:33 by pperea-d          #+#    #+#             */
/*   Updated: 2021/02/08 11:30:39 by pperea-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_color		filter(t_color color, t_scene *scene)
{
	if (scene->filter == 1)
		color = sepia_filter(color);
	else if (scene->filter == 2)
		color = mono_filter(color);
	else if (scene->filter == 3)
		color = red_filter(color);
	else if (scene->filter == 4)
		color = green_filter(color);
	else if (scene->filter == 5)
		color = blue_filter(color);
	return (color);
}

void		fil_render(t_scene *scene)
{
	if (scene->filter == 5)
		scene->filter = 0;
	else
		scene->filter += 1;
	threats(scene);
	mlx_put_image_to_window(scene->mlx,
	scene->mlx_win, scene->img.img, 0, 0);
}
