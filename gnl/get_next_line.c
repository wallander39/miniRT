/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pperea-d <pperea-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/21 18:08:16 by pperea-d          #+#    #+#             */
/*   Updated: 2020/12/27 17:25:08 by pperea-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	no_text(char **line, int n_bytes)
{
	if (n_bytes < 0)
		return (-1);
	*line = gn_strdup("");
	return (0);
}

static int	new_line(char **line, char **text, int fd)
{
	char	*aux;
	int		i;

	aux = gn_strchr(text[fd], '\n');
	i = 0;
	while (text[fd][i] != '\0' && text[fd][i] != '\n')
		i++;
	*line = (char *)malloc(i + 1);
	if (!*line)
		return (-1);
	gn_strlcpy(*line, text[fd], i + 1);
	if (aux)
	{
		aux = gn_strdup(aux + 1);
		free(text[fd]);
		text[fd] = aux;
		return (1);
	}
	free(text[fd]);
	text[fd] = NULL;
	return (0);
}

int			get_next_line(int fd, char **line)
{
	static char	*text[4096];
	char		*buffer;
	int			n_bytes;

	if (fd < 0 || !line || BUFFER_SIZE <= 0 \
	|| !(buffer = (char *)malloc(BUFFER_SIZE + 1)))
		return (-1);
	while ((n_bytes = read(fd, buffer, BUFFER_SIZE)) && n_bytes > 0)
	{
		buffer[n_bytes] = '\0';
		if (!text[fd])
			text[fd] = gn_strdup(buffer);
		else
			text[fd] = gn_strjoin(text[fd], buffer);
		if (gn_strchr(text[fd], '\n'))
			break ;
	}
	free(buffer);
	if (n_bytes < 0 || (n_bytes == 0 && !text[fd]))
		return (no_text(line, n_bytes));
	return (new_line(line, text, fd));
}
