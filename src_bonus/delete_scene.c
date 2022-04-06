/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_scene.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pperea-d <pperea-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/01 20:11:33 by pperea-d          #+#    #+#             */
/*   Updated: 2021/02/07 17:02:04 by pperea-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	delete_scene(t_scene *scene)
{
	delete_cams(scene);
	delete_spheres(scene);
	delete_planes(scene);
	delete_cylinders(scene);
	delete_squares(scene);
	delete_triangles(scene);
	delete_lights(scene);
	delete_dlights(scene);
}
