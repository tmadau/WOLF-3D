/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmadau <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 08:58:00 by tmadau            #+#    #+#             */
/*   Updated: 2018/06/07 15:43:19 by tmadau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*csbyte1;
	unsigned char	*csbyte2;

	csbyte1 = (unsigned char *)dst;
	csbyte2 = (unsigned char *)src;
	if (csbyte2 < csbyte1)
	{
		while (len)
		{
			csbyte1[len - 1] = csbyte2[len - 1];
			len--;
		}
	}
	else
		ft_memcpy(dst, src, len);
	return (dst);
}
