/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhalid <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 15:52:00 by mkhalid           #+#    #+#             */
/*   Updated: 2021/12/05 20:35:05 by mkhalid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	_print_hexa(unsigned int nb, char *base, int base_len)
{
	if (nb < 16)
	{
		ft_putchar(base[nb]);
		return ;
	}
	_print_hexa(nb / 16, base, base_len);
	_print_hexa(nb % 16, base, base_len);
}

int	ft_print_hexa(unsigned int nb, char *base)
{
	int	len;
	int	base_len;

	base_len = ft_strlen(base);
	_print_hexa(nb, base, base_len);
	len = 0;
	if (nb == 0)
		len = 1;
	while (nb)
	{
		len++;
		nb /= base_len;
	}
	return (len);
}
