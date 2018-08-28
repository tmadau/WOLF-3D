/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmadau <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/02 14:35:37 by tmadau            #+#    #+#             */
/*   Updated: 2018/06/10 17:05:57 by tmadau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*string;

	string = (char *)malloc(sizeof(*string) * size + 1);
	if (string == NULL)
		return (NULL);
	else
	{
		ft_bzero(string, size + 1);
		return (string);
	}
}
