/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhalid <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 15:31:36 by mkhalid           #+#    #+#             */
/*   Updated: 2021/12/01 09:50:06 by mkhalid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	_putnbr(int	nb)
{
	char	c;

	if (nb < 10)
	{
		c = nb + '0';
		write(1, &c, 1);
		return ;
	}
	_putnbr(nb / 10);
	_putnbr(nb % 10);
}

int	ft_putnbr(int nb)
{
	int	len;
	
	len = 0;
	if (nb < 0)
	{
		write (1, "-", 1);
		len++;
		_putnbr(nb / 10 * -1);
		_putnbr(nb % 10 * -1);
	}
	else
	{
		_putnbr(nb / 10);
		_putnbr(nb % 10);
	}
	while(nb)
	{
		nb /= 10;
		len++;
	}
	return (len);
}
