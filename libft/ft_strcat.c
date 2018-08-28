/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmadau <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 16:17:20 by tmadau            #+#    #+#             */
/*   Updated: 2018/06/11 15:59:19 by tmadau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *s1, const char *s2)
{
	char		*cntstr1;
	const char	*cntstr2;

	cntstr1 = s1;
	cntstr2 = s2;
	if (!s1 && !s2)
		return (0);
	while (*cntstr1)
		cntstr1++;
	while (*cntstr2)
	{
		*cntstr1 = *cntstr2;
		cntstr1++;
		cntstr2++;
	}
	*cntstr1 = '\0';
	return (s1);
}
