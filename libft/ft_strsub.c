/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmadau <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 17:41:39 by tmadau            #+#    #+#             */
/*   Updated: 2018/06/10 12:09:24 by tmadau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	int			i;
	char		*substr;

	substr = (char *)malloc(sizeof(*s) * (len + 1));
	if (!substr)
		return (NULL);
	if (s)
	{
		i = 0;
		while (s[start] && len > 0)
		{
			substr[i] = s[start];
			i++;
			start++;
			len--;
		}
		substr[i] = '\0';
		return (substr);
	}
	else
		return (NULL);
}
