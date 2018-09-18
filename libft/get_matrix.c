/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_matrix.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmadau <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/21 10:11:07 by tmadau            #+#    #+#             */
/*   Updated: 2018/09/18 16:54:16 by tmadau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	get_matrix(char *str, t_map *ev)
{
	ev->fd = open(str, O_RDONLY);
	ev->line = NULL;
	ev->inc = 1;
	ev->tk = 1;
	if ((ev->ret = get_next_line(ev->fd, &ev->line) > 0))
	{
		ev->size = ft_wordcount(ev->line, ' ');
		free(ev->line);
	}
	while ((ev->ret = get_next_line(ev->fd, &ev->line) > 0))
	{
		if ((size_t)ev->size != ft_wordcount(ev->line, ' '))
			ev->tk = 0;
		ev->inc++;
		free(ev->line);
	}
	ev->row = ev->size;
	ev->x = ev->size;
	ev->y = ev->inc;
	close(ev->fd);
}
