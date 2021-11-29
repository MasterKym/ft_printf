
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhalid <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 15:38:03 by mkhalid           #+#    #+#             */
/*   Updated: 2021/11/29 18:01:01 by mkhalid          ###   ########.fr       */
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
//			print_count += print_arg(str[i+1], args);
			i +=2;
			continue;
		}
		print_count += ft_putchar(str[i]);
		i++;
	}
	va_end(args);
	return (0);
}
