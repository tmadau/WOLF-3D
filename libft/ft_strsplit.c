/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmadau <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 17:43:54 by tmadau            #+#    #+#             */
/*   Updated: 2018/06/16 14:59:20 by tmadau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strsplit(char const *s, char c)
{
	char	**arr_str;
	size_t	i;
	size_t	j;
	size_t	len;

	i = 0;
	j = 0;
	if (s == 0 || c == 0)
		return (0);
	arr_str = (char**)malloc(sizeof(*arr_str) * (ft_strlen(s) + 1));
	if (arr_str == NULL)
		return (NULL);
	while (s[i])
		if (s[i] == c)
			i++;
		else
		{
			len = 0;
			while (s[i + len] && (s[i + len] != c))
				len++;
			arr_str[j++] = ft_strsub(s, i, len);
			i = i + len;
		}
	arr_str[j] = 0;
	return (arr_str);
}
