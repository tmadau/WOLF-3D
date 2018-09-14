/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_matrix.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmadau <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/21 10:11:07 by tmadau            #+#    #+#             */
/*   Updated: 2018/09/14 11:48:25 by tmadau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	get_matrix(char *str, t_map *ev)
{
	int		fd;
	char	*line;
	int		buff;
	int		inc;

	fd = open(str, O_RDONLY);
	line = NULL;
	inc = 1;
	if (get_next_line(fd, &line) > 0)
	{
		buff = ft_wordcount(line, ' ');
		free(line);
	}
	while (get_next_line(fd, &line) > 0)
	{
		free(line);
		inc++;
	}
	ev->row = buff;
	ev->x = buff;
	ev->y = inc;
	close(fd);
}
