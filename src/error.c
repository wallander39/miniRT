/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pperea-d <pperea-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 16:50:05 by pperea-d          #+#    #+#             */
/*   Updated: 2021/02/10 18:14:00 by pperea-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

char	*g_error[] =
{
	"Error\n",
	"Invalid arguments.\n",
	"Invalid file.\n",
	"Invalid option\n\noptions:\n  --save   save rendered image to bmp\n",
	"Invalid file name\n",
	"Invalid scene: Resolution must be declared only once\n",
	"Invalid scene: Ambient light must be declared only once\n",
	"Invalid scene: Set at least one camera to render a view\n",
	"Invalid scene: ratio value must be in range [0,1]\n",
	"Invalid scene: RGB color must be in range [0-255]\n",
	"Invalid scene: vector values must be in range [-1,1]\n",
	"Invalid scene: wrong vector\n",
	"Invalid scene: FOV value must be in range [0,180]\n"
};

void	exit_error_msg(t_error id, t_scene *scene)
{
	delete_scene(scene);
	ft_printf("Error: %s\n", g_error[id]);
	exit(EXIT_FAILURE);
}
