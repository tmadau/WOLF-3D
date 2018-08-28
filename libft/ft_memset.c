/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmadau <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 16:53:02 by tmadau            #+#    #+#             */
/*   Updated: 2018/06/05 16:22:12 by tmadau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*bytestr;
	unsigned char	byteval;

	i = 0;
	bytestr = (unsigned char *)b;
	byteval = (unsigned char)c;
	while (i < len)
	{
		bytestr[i] = byteval;
		i++;
	}
	return (b);
}
