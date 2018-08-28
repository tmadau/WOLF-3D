/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmadau <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 17:44:25 by tmadau            #+#    #+#             */
/*   Updated: 2018/06/14 10:46:30 by tmadau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_itoa(int n)
{
	long	op;
	char	*str;
	int		digits;
	long	number;
	int		neg;

	op = 1;
	number = n;
	digits = 0;
	neg = 0;
	if (number < 0 && number != 0 && ++neg)
		number *= -1;
	while (number / op > 0 && number != 0 && ++digits)
		op *= 10;
	if (number == 0)
		digits++;
	if (neg)
		digits = digits + 1;
	if (!(str = (char *)malloc(sizeof(char) * (digits + 1))))
		return (NULL);
	ft_convert(number, digits, str, neg);
	return (str);
}
