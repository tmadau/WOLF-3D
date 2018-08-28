/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmadau <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/25 11:53:54 by tmadau            #+#    #+#             */
/*   Updated: 2018/06/06 09:43:37 by tmadau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t		i;
	char		*cpstr;

	i = 0;
	cpstr = (char *)malloc(sizeof(char) * ft_strlen(s1) + 1);
	if (cpstr == NULL)
		return (NULL);
	while (s1[i])
	{
		cpstr[i] = s1[i];
		i++;
	}
	cpstr[i] = '\0';
	return (cpstr);
}
