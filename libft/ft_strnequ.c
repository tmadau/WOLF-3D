/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmadau <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 17:40:45 by tmadau            #+#    #+#             */
/*   Updated: 2018/06/10 17:20:25 by tmadau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	size_t		i;
	const char	*cmpstr1;
	const char	*cmpstr2;

	i = 0;
	if (s1 && s2)
	{
		cmpstr1 = s1;
		cmpstr2 = s2;
		if (ft_strncmp(cmpstr1, cmpstr2, n) == 0)
			return (1);
	}
	return (0);
}
