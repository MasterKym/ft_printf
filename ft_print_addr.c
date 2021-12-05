/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_addr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhalid <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 18:23:20 by mkhalid           #+#    #+#             */
/*   Updated: 2021/12/05 15:47:12 by mkhalid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
static void	__print_hexa(unsigned long int nb, char *base, int base_len)
{
	if (nb < 16)
	{
		ft_putchar(base[nb]);
		return;
	}
	__print_hexa(nb / 16, base, base_len);
	__print_hexa(nb % 16, base, base_len);
}

static int	_print_hexa(unsigned long int nb, char *base)
{
	int	len;
	int	base_len;

	base_len = ft_strlen(base);
	__print_hexa(nb, base, base_len);
	len = 0;
	while(nb)
	{
		len++;
		nb /= base_len;
	}
	return (len);	
}

int	ft_print_addr(unsigned long int addr)
{
	int	len;
	int	base_len;
	char *base;

	ft_putstr("0x");
	if (addr == 0)
		return (ft_putchar(48) + 2);
	base = "0123456789abcdef";
	base_len = ft_strlen(base);
	_print_hexa(addr, base);
	len = 2;
	while (addr)
	{
		addr /= base_len;
		len++;
	}
	return (len);
}


