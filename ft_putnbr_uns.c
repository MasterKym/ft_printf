/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_uns.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhalid <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 15:31:36 by mkhalid           #+#    #+#             */
/*   Updated: 2021/12/01 09:46:26 by mkhalid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	_putnbr_uns(unsigned int nb)
{
	char	c;

	if (nb < 10)
	{
		c = nb + '0';
		write(1, &c, 1);
		return ;
	}
	_putnbr_uns(nb / 10);
	_putnbr_uns(nb % 10);
}

int	ft_putnbr_uns(unsigned int nb)
{
	int	len;
	
	len = 0;
	_putnbr_uns(nb / 10);
	_putnbr_uns(nb % 10);
	while(nb)
	{
		nb /= 10;
		len++;
	}
	return (len);
}
