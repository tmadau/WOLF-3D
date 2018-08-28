/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmadau <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 09:48:51 by tmadau            #+#    #+#             */
/*   Updated: 2018/06/14 18:20:18 by tmadau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *hs, const char *nd, size_t len)
{
	size_t		hi;
	size_t		ni;

	hi = 0;
	if (ft_strlen(nd) == 0)
		return ((char *)hs);
	while (hs[hi] != 0 && hi <= len)
	{
		ni = 0;
		while (nd[ni] == hs[hi + ni] &&
				hs[hi + ni] != 0 && (ni + hi) < len)
		{
			if (nd[ni + 1] == '\0')
				return ((char *)hs + hi);
			if (hi + ni > len)
				return (NULL);
			ni++;
		}
		hi++;
	}
	return (NULL);
}
