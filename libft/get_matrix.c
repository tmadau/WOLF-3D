/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_matrix.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmadau <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/21 10:11:07 by tmadau            #+#    #+#             */
/*   Updated: 2018/08/21 10:11:28 by tmadau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		get_matrix(t_array *n_row, int fd)
{
	n_row->row = NULL;
	n_row->link_rows = NULL;
	n_row->count = -1;
	n_row->i = 0;
	while ((n_row->ret = get_next_line(fd, &n_row->row)) > 0)
	{
		if (!n_row->link_rows)
			n_row->link_rows = ft_strdup("");
		if (n_row->count == -1)
			n_row->count = ft_wordcount(n_row->row, ' ');
		else if (n_row->count != (long)ft_wordcount(n_row->row, ' '))
		{
			ft_strdel(&n_row->link_rows);
			return (-2);
		}
		n_row->link_rows = strjoin_free(n_row->link_rows, n_row->row);
		ft_strdel(&n_row->row);
		n_row->i++;
	}
	if (n_row->count == 0 || n_row->ret == -1)
		return (-3);
	n_row->matrix = ft_strsplit(n_row->link_rows, ')');
	ft_strdel(&n_row->link_rows);
	return (1);
}
