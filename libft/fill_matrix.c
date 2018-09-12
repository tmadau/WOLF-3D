/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_matrix.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmadau <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 08:27:47 by tmadau            #+#    #+#             */
/*   Updated: 2018/09/12 17:13:53 by tmadau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		fill_matrix(char *str, t_map *ev)
{
	char	*line;
	char	**split;

	ev->get_x = 0;
	ev->get_y = 0;
	ev->fd = open(str, O_RDONLY);
	while (get_next_line(ev->fd, &line) > 0 && ev->get_y < ev->y)
	{
		if ((ft_wordcount(line, ' ')) >= ev->row)
		{
			split = ft_strsplit(line, ' ');
			ev->get_x = 0;
			while (ev->get_x < ev->x)
			{
				ev->map[ev->get_y][ev->get_x] =
					(int)ft_atoi(split[ev->get_x]);
				free(split[ev->get_x]);
				ev->get_x++;
			}
			ev->get_y++;
			free(line);
			free(split);
		}
		else
			ft_putendl("Map Error!");
	}
	close(ev->fd);
}
