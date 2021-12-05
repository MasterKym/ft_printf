/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhalid <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 15:31:36 by mkhalid           #+#    #+#             */
/*   Updated: 2021/12/05 20:41:21 by mkhalid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	_get_len(int nb)
{
	int	len;

	if (nb == 0)
		return (1);
	len = 0;
	while (nb)
	{
		nb /= 10;
		len++;
	}
	return (len);
}

static void	_putnbr(int nb)
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
	int	min;
	int	sign;

	sign = (nb < 0) == 1;
	if (nb < 0)
	{
		write(1, "-", 1);
		min = 1 << (sizeof(int) * 8 - 1);
		if (nb == min)
		{
			_putnbr(nb / 10 * -1);
			_putnbr(nb % 10 * -1);
			return (_get_len(nb) + sign);
		}
		nb *= -1;
	}
	_putnbr(nb);
	return (_get_len(nb) + sign);
}
