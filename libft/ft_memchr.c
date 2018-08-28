/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmadau <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 08:23:07 by tmadau            #+#    #+#             */
/*   Updated: 2018/06/07 15:40:35 by tmadau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*locbyte;
	unsigned char	str;

	i = 0;
	locbyte = (unsigned char *)s;
	str = (unsigned char)c;
	while (i < n)
	{
		if (locbyte[i] == str)
			return (locbyte + i);
		i++;
	}
	return (NULL);
}
