/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmadau <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 16:18:33 by tmadau            #+#    #+#             */
/*   Updated: 2018/06/14 15:56:53 by tmadau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*str;
	char	lstchr;

	str = (char *)s;
	lstchr = (char)c;
	while (*str != '\0')
		str++;
	while (*str != lstchr)
	{
		if (str == s)
			return (0);
		str--;
	}
	return ((char *)str);
}
