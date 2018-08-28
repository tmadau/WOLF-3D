/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmadau <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 17:23:36 by tmadau            #+#    #+#             */
/*   Updated: 2018/06/05 14:01:12 by tmadau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*dmema;
	unsigned char	*smema;

	i = 0;
	dmema = (unsigned char *)dst;
	smema = (unsigned char *)src;
	while (i < n)
	{
		dmema[i] = smema[i];
		i++;
	}
	return (dst);
}
