/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   saver.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pperea-d <pperea-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 07:25:56 by pabloperea        #+#    #+#             */
/*   Updated: 2021/02/10 18:12:47 by pperea-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	header_data(int fd, t_scene *scene)
{
	unsigned char	header[54];
	int				i;

	i = 0;
	while (i < 54)
		header[i++] = (unsigned char)0;
	header[0] = 'B';
	header[1] = 'M';
	header[10] = (unsigned char)(54);
	header[14] = (unsigned char)(40);
	header[18] = (unsigned char)(scene->res.width);
	header[19] = (unsigned char)(scene->res.width >> 8);
	header[20] = (unsigned char)(scene->res.width >> 16);
	header[21] = (unsigned char)(scene->res.width >> 24);
	header[22] = (unsigned char)(scene->res.heigth);
	header[23] = (unsigned char)(scene->res.heigth >> 8);
	header[24] = (unsigned char)(scene->res.heigth >> 16);
	header[25] = (unsigned char)(scene->res.heigth >> 24);
	header[26] = (unsigned char)(1);
	header[28] = (unsigned char)(32);
	write(fd, header, 54);
}

void	pixel_data(int fd, t_scene *scene)
{
	int	i;

	i = scene->res.heigth;
	while (i--)
	{
		write(fd, scene->img.addr + i * scene->res.width
		* 4, scene->res.width * 4);
	}
}

void	save_image_bmp(t_scene *scene)
{
	int			fd;
	t_display	img;

	img.img = mlx_new_image(scene->mlx, scene->res.width, scene->res.heigth);
	img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.length, &img.end);
	scene->img = img;
	scene->aux_cam = scene->cams;
	render_scene(scene);
	if ((fd = open("minirt.bmp", O_WRONLY | O_CREAT | O_TRUNC, 0744)) == -1)
		exit(EXIT_FAILURE);
	header_data(fd, scene);
	pixel_data(fd, scene);
	delete_scene(scene);
	close(fd);
}
