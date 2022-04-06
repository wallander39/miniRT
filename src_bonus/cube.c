/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pperea-d <pperea-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 20:43:19 by pperea-d          #+#    #+#             */
/*   Updated: 2021/02/10 15:36:50 by pperea-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_square	*create_sqfromc(t_vec3 center,
t_vec3 orientation, t_scene *scene, t_cube cube)
{
	t_square	*square;

	if (!(square = malloc(sizeof(t_square))))
		exit_error_msg(DEF_ERR, scene);
	square->orientation = orientation;
	square->point = center;
	square->specular = cube.specular;
	square->reflect = cube.reflect;
	square->height = cube.height;
	square->color = cube.color;
	return (square);
}

void		read_cube3(t_cube cube, t_vec3 center,
t_vec3 orientation, t_scene *scene)
{
	t_square	*square;

	center.x = cube.point.x - cube.height / 2;
	center.y = cube.point.y;
	center.z = cube.point.z;
	orientation = (t_vec3){-1, 0, 0};
	square = create_sqfromc(center, orientation, scene, cube);
	add_square(square, scene);
	center.x = cube.point.x;
	center.y = cube.point.y;
	center.z = cube.point.z + cube.height / 2;
	orientation = (t_vec3){0, 0, 1};
	square = create_sqfromc(center, orientation, scene, cube);
	add_square(square, scene);
}

void		read_cube2(t_cube cube, t_vec3 center,
t_vec3 orientation, t_scene *scene)
{
	t_square	*square;

	center.x = cube.point.x;
	center.y = cube.point.y - cube.height / 2;
	center.z = cube.point.z;
	orientation = (t_vec3){0, -1, 0};
	square = create_sqfromc(center, orientation, scene, cube);
	add_square(square, scene);
	center.x = cube.point.x;
	center.y = cube.point.y + cube.height / 2;
	center.z = cube.point.z;
	orientation = (t_vec3){0, 1, 0};
	square = create_sqfromc(center, orientation, scene, cube);
	add_square(square, scene);
	center.x = cube.point.x + cube.height / 2;
	center.y = cube.point.y;
	center.z = cube.point.z;
	orientation = (t_vec3){1, 0, 0};
	square = create_sqfromc(center, orientation, scene, cube);
	add_square(square, scene);
}

void		read_cube(char *line, t_scene *scene)
{
	t_cube		cube;
	t_vec3		center;
	t_vec3		orientation;
	t_square	*square;

	line += 2;
	cube.point = get_vec3(&line, scene);
	cube.height = get_double(&line, scene);
	cube.color = get_color(&line, scene);
	cube.specular = get_double(&line, scene);
	cube.reflect = get_double(&line, scene);
	skip_blanks(&line);
	if (*line != '\0')
		exit_error_msg(FILE_ERR, scene);
	center.x = cube.point.x;
	center.y = cube.point.y;
	center.z = cube.point.z - cube.height / 2;
	orientation = (t_vec3){0, 0, -1};
	square = create_sqfromc(center, orientation, scene, cube);
	add_square(square, scene);
	read_cube2(cube, center, orientation, scene);
	read_cube3(cube, center, orientation, scene);
}
