/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhalid <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 14:18:05 by mkhalid           #+#    #+#             */
/*   Updated: 2021/12/01 19:42:57 by mkhalid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ft_printf.h"

int	is_conversion(char c)
{
	char	*s;

	s = "cspdiuxX%";
	while(*s)
	{
		if (c == *s)
			return (1);
		s++;
	}
	return (0);
}

int	print_arg(char c, va_list args)
{
	if (c == 'c')
		return (ft_putchar(va_arg(args, int)));
	if (c == 's')
		return (ft_putstr(va_arg(args, char *)));
	//if (c == 'p')
	//
	if (c == 'd')
		return (ft_putnbr(va_arg(args, int)));
	if (c == 'i')
		return (ft_putnbr(va_arg(args, int)));
	if (c == 'u')
		return (ft_putnbr_uns(va_arg(args, unsigned int)));
	if (c == 'x')
		return (ft_print_hexa(va_arg(args, unsigned int), "0123456789abcdef"));
	if (c == 'X')
		return (ft_print_hexa(va_arg(args, unsigned int), "0123456789ABCDEF"));
	if (c == '%')
		return (ft_putchar ('%'));

	return (0);

}

int	ft_printf(char *str, ...)
{
	va_list	args;
	int	i;
	int	print_count;

	i = 0;
	print_count = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] =='%' && is_conversion(str[i+1]))
		{
			print_count += print_arg(str[i+1], args);
			i +=2;
			continue;
		}
		print_count += ft_putchar(str[i]);
		i++;
	}
	va_end(args);
	return (print_count);
}
