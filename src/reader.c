/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pperea-d <pperea-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 14:35:32 by pperea-d          #+#    #+#             */
/*   Updated: 2021/02/10 17:23:20 by pperea-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void			read_amb(char *line, t_scene *scene)
{
	if (scene->amb.declared)
		exit_error_msg(AMB_DECLARED, scene);
	scene->amb.declared = 1;
	line += 2;
	scene->amb.intensity = get_double(&line, scene);
	if (scene->amb.intensity < 0 || scene->amb.intensity > 1)
		exit_error_msg(FILE_ERR, scene);
	scene->amb.color = get_color(&line, scene);
	skip_blanks(&line);
	if (*line == '\0')
		return ;
	else
		exit_error_msg(FILE_ERR, scene);
}

void			read_res(char *line, t_scene *scene)
{
	if (scene->res.declared)
		exit_error_msg(FILE_ERR, scene);
	scene->res.declared = 1;
	line += 2;
	scene->res.width = get_int(&line, scene);
	if (scene->res.width >= 2560)
		scene->res.width = 2560;
	scene->res.heigth = get_int(&line, scene);
	if (scene->res.heigth >= 1440)
		scene->res.heigth = 1440;
	skip_blanks(&line);
	if (*line == '\0')
		return ;
	else
		exit_error_msg(FILE_ERR, scene);
}

void			read_elements(char *line, t_scene *scene)
{
	if (!ft_strncmp(line, "R ", 2))
		read_res(line, scene);
	else if (!ft_strncmp(line, "A ", 2))
		read_amb(line, scene);
	else if (!ft_strncmp(line, "l ", 2))
		read_light(line, scene);
	else if (!ft_strncmp(line, "c ", 2))
		read_cam(line, scene);
	else if (!ft_strncmp(line, "sp ", 3))
		read_sphere(line, scene);
	else if (!ft_strncmp(line, "pl ", 3))
		read_plane(line, scene);
	else if (!ft_strncmp(line, "cy ", 3))
		read_cylinder(line, scene);
	else if (!ft_strncmp(line, "sq ", 3))
		read_square(line, scene);
	else if (!ft_strncmp(line, "tr ", 3))
		read_triangle(line, scene);
	else if (!ft_strcmp(line, ""))
		return ;
	else
		exit_error_msg(FILE_ERR, scene);
}

void			read_file(char *file, t_scene *scene)
{
	char	*line;
	int		fd;
	int		size;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		exit_error_msg(FILE_ERR, scene);
	while ((size = get_next_line(fd, &line)) > 0)
	{
		read_elements(line, scene);
		free(line);
		line = NULL;
	}
	if (size == 0)
		read_elements(line, scene);
	if (line)
	{
		free(line);
		line = NULL;
	}
	close(fd);
}
