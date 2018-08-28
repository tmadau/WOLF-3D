/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmadau <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 17:39:59 by tmadau            #+#    #+#             */
/*   Updated: 2018/06/07 16:15:33 by tmadau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strequ(char const *s1, char const *s2)
{
	size_t		i;
	const char	*cmpstr1;
	const char	*cmpstr2;

	i = 0;
	cmpstr1 = s1;
	cmpstr2 = s2;
	if (!s1 || !s2)
		return (0);
	while (ft_strlen(cmpstr1) == ft_strlen(cmpstr2))
	{
		if (ft_strcmp(cmpstr1, cmpstr2) != '\0')
			return (0);
		return (1);
	}
	return (0);
}
