/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmadau <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 15:46:50 by tmadau            #+#    #+#             */
/*   Updated: 2018/06/05 09:58:18 by tmadau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*ssbyte;
	unsigned char	*dsbyte;

	i = 0;
	ssbyte = (unsigned char *)src;
	dsbyte = (unsigned char *)dst;
	while (i < n)
	{
		dsbyte[i] = ssbyte[i];
		if (dsbyte[i] == (unsigned char)c)
			return (dsbyte + i + 1);
		i++;
	}
	return (NULL);
}
