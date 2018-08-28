/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmadau <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 08:54:13 by tmadau            #+#    #+#             */
/*   Updated: 2018/06/07 16:05:13 by tmadau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	size_t			i;
	unsigned char	*ntstr1;
	unsigned char	*ntstr2;

	i = 0;
	ntstr1 = (unsigned char *)s1;
	ntstr2 = (unsigned char *)s2;
	while ((ntstr1[i]) || (ntstr2[i]))
	{
		if ((ntstr1[i]) != (ntstr2[i]))
		{
			return ((ntstr1[i]) - (ntstr2[i]));
		}
		i++;
	}
	return (0);
}
