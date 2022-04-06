/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pperea-d <pperea-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 18:11:19 by pperea-d          #+#    #+#             */
/*   Updated: 2021/02/04 13:56:50 by pperea-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	checker(int argc, char **argv, t_scene *scene)
{
	if (argc < 2 || argc > 3)
		exit_error_msg(ARGS_ERR, scene);
	if (ft_strlen(argv[1]) <= 3)
		exit_error_msg(FILE_NAME_ERR, scene);
	if (argc == 3)
	{
		if (!ft_strcmp(argv[2], "--save"))
			scene->save = 1;
		else
			exit_error_msg(OPT_ERR, scene);
	}
	if (ft_strncmp(argv[1] + ft_strlen(argv[1]) - 3, ".rt", 3))
		exit_error_msg(FILE_NAME_ERR, scene);
}
