/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc_matrix.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmadau <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 08:12:13 by tmadau            #+#    #+#             */
/*   Updated: 2018/09/17 12:06:07 by tmadau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	alloc_matrix(char *str, t_map *ev)
{
	int		index;

	index = 0;
	ev->map = (int **)malloc(sizeof(int *) * ev->y);
	while (index < ev->y)
	{
		ev->map[index] = (int *)malloc(sizeof(int) * ev->x);
		index++;
	}
	fill_matrix(str, ev);
}
