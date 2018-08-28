/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmadau <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 17:42:19 by tmadau            #+#    #+#             */
/*   Updated: 2018/06/10 17:15:33 by tmadau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	fi;
	size_t	si;
	char	*fstr;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	fstr = ft_strnew(ft_strlen(s1) + ft_strlen(s2));
	if (fstr == NULL)
		return (NULL);
	fi = 0;
	si = 0;
	while (s1[si])
	{
		fstr[fi] = s1[si];
		fi++;
		si++;
	}
	si = 0;
	while (s2[si])
	{
		fstr[fi] = s2[si];
		fi++;
		si++;
	}
	return (fstr);
}
