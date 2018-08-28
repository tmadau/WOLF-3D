/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmadau <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 16:58:17 by tmadau            #+#    #+#             */
/*   Updated: 2018/06/14 13:45:39 by tmadau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	value;

	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n *= -1;
	}
	value = n;
	if (value >= 10)
		ft_putnbr_fd(value / 10, fd);
	ft_putchar_fd((value % 10) + '0', fd);
}
