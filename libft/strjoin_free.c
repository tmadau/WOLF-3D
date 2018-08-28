/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strjoin_free.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmadau <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/21 10:10:29 by tmadau            #+#    #+#             */
/*   Updated: 2018/08/21 10:11:52 by tmadau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*strjoin_free(char const *s1, char const *s2)
{
	t_array		string;

	if (!s1 || !s2)
		return (NULL);
	string.i = 0;
	string.count = ft_strlen((char *)s1) + ft_strlen((char *)s2) + 2;
	if (!(string.row = (char *)malloc(sizeof(char) * string.count)))
		return (NULL);
	if (s1 && s2)
	{
		string.row[string.i] = '\0';
		ft_strlcat(string.row, s1, string.count);
		ft_strlcat(string.row, ")", string.count);
		ft_strlcat(string.row, s2, string.count);
	}
	free((void *)s1);
	return (string.row);
}
