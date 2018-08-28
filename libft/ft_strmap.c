/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmadau <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 17:31:30 by tmadau            #+#    #+#             */
/*   Updated: 2018/06/07 17:59:53 by tmadau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	size_t	i;
	char	*newstr;

	if (!s)
		return (NULL);
	if (!(newstr = (char*)malloc(ft_strlen(s) + 1)))
		return (NULL);
	i = 0;
	while (*s)
	{
		newstr[i] = (*f)(*s);
		i++;
		s++;
	}
	newstr[i] = '\0';
	return (newstr);
}
