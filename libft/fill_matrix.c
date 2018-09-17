/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_matrix.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmadau <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 08:27:47 by tmadau            #+#    #+#             */
/*   Updated: 2018/09/17 13:51:01 by tmadau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	init_take(char *str, t_map *ev)
{
	ev->get_x = 0;
	ev->get_y = 0;
	ev->fd = open(str, O_RDONLY);
}

int		err_check(t_map *ev)
{
	if (ev->get_y == 0 || ev->get_x == 0 || ev->ret == -1)
	{
		ft_putstr(DATA_ERR);
		exit(0);
	}
	return (1);
}

void	fill_matrix(char *str, t_map *ev)
{
	char	*line;
	char	**split;

	init_take(str, ev);
	while ((ev->ret = get_next_line(ev->fd, &line)) > 0)
	{
		if ((ft_wordcount(line, ' ')) >= ev->row)
		{
			split = ft_strsplit(line, ' ');
			ev->get_x = 0;
			while (ev->get_x < ev->x)
			{
				ev->map[ev->get_y][ev->get_x] =
					ft_atoi(split[ev->get_x]);
				free(split[ev->get_x]);
				ev->get_x++;
			}
			ev->get_y++;
			free(line);
			free(split);
		}
		err_check(ev);
	}
	close(ev->fd);
}
