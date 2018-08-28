/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmadau <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 11:23:49 by tmadau            #+#    #+#             */
/*   Updated: 2018/06/04 15:24:21 by tmadau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*ssbyte;
	unsigned char	*dsbyte;

	i = 0;
	ssbyte = (unsigned char *)s2;
	dsbyte = (unsigned char *)s1;
	while (i < n)
	{
		if ((dsbyte[i]) != (ssbyte[i]))
			return ((dsbyte[i]) - (ssbyte[i]));
		i++;
	}
	return (0);
}
