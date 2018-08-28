/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmadau <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 08:37:35 by tmadau            #+#    #+#             */
/*   Updated: 2018/06/07 11:32:01 by tmadau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*dest;
	unsigned char	*src;

	i = 0;
	dest = (unsigned char *)(s1);
	src = (unsigned char *)(s2);
	while ((dest[i] || src[i]) && i < n)
	{
		if ((dest[i]) != (src[i]))
		{
			return (dest[i] - src[i]);
		}
		i++;
	}
	return (0);
}
