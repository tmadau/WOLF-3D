/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmadau <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 08:42:03 by tmadau            #+#    #+#             */
/*   Updated: 2018/06/05 15:41:03 by tmadau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t	bchr1;
	size_t	bchr2;

	bchr1 = 0;
	bchr2 = 0;
	while (s1[bchr1])
		bchr1++;
	while (s2[bchr2] && bchr2 < n)
	{
		s1[bchr1] = s2[bchr2];
		bchr1++;
		bchr2++;
	}
	s1[bchr1] = '\0';
	return (s1);
}
