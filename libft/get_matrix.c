/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_matrix.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmadau <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/21 10:11:07 by tmadau            #+#    #+#             */
/*   Updated: 2018/09/17 11:37:02 by tmadau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	get_matrix(char *str, t_map *ev)
{
	ev->fd = open(str, O_RDONLY);
	ev->line = NULL;
	ev->inc = 1;
	if ((ev->ret = get_next_line(ev->fd, &ev->line) > 0))
	{
		ev->size = ft_wordcount(ev->line, ' ');
		free(ev->line);
	}
	while ((ev->ret = get_next_line(ev->fd, &ev->line) > 0))
	{
		free(ev->line);
		ev->inc++;
	}
	ev->row = ev->size;
	ev->x = ev->size;
	ev->y = ev->inc;
	close(ev->fd);
}
