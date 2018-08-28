/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmadau <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 08:50:09 by tmadau            #+#    #+#             */
/*   Updated: 2018/06/17 13:01:52 by tmadau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t		i;

	i = 0;
	while (dst[i])
		i++;
	if (i >= dstsize)
		return (dstsize + ft_strlen((char *)src));
	ft_strncat(dst, src, dstsize - i - 1);
	return (i + ft_strlen((char *)src));
}
