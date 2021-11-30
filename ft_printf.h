/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhalid <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 17:51:10 by mkhalid           #+#    #+#             */
/*   Updated: 2021/11/30 16:46:08 by mkhalid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
#define FT_PRINTF_H

# include <unistd.h>
int	ft_printf(char *str, ...);

int	ft_putchar(char c);
int	ft_putstr(char *s);
int	ft_print_hexa(unsigned long nb);
int	ft_putnbr(int nb);
#endif
