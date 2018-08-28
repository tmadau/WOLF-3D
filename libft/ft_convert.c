/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmadau <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 10:39:41 by tmadau            #+#    #+#             */
/*   Updated: 2018/06/14 10:42:30 by tmadau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_convert(long number, int digits, char *str, int neg)
{
	char	hold;

	str[digits] = '\0';
	if (number == 0)
		str[0] = '0';
	else
	{
		while (number)
		{
			hold = number % 10 + '0';
			str[digits - 1] = hold;
			digits--;
			number /= 10;
		}
	}
	if (neg)
		str[0] = '-';
}
