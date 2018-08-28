/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmadau <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 16:23:37 by tmadau            #+#    #+#             */
/*   Updated: 2018/06/08 12:25:38 by tmadau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t		hi;
	size_t		ni;
	size_t		strlen;

	hi = 0;
	ni = 0;
	strlen = 0;
	while (haystack[strlen])
		strlen++;
	if (ft_strlen(needle) == 0)
		return ((char *)haystack);
	while (haystack[hi])
	{
		while (needle[ni] && needle[ni] == haystack[hi + ni])
			ni++;
		if (needle[ni] == '\0')
			return ((char *)(haystack + hi));
		ni = 0;
		hi++;
	}
	return (NULL);
}
