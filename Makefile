# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mkhalid <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/25 15:30:41 by mkhalid           #+#    #+#              #
#    Updated: 2021/12/01 19:34:10 by mkhalid          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
HEADER = ft_printf.h
CC = gcc
AR = ar
CFLAGS = -Wall -Werror -Wextra
ARFLAGS = rc

SRCS = ft_printf.c \
	   ft_putchar.c \
	   ft_putstr.c \
	   ft_print_hexa.c \
	   ft_putnbr.c \
	   ft_putnbr_uns.c \
	   ft_strlen.c


OBJS = $(SRCS:.c=.o)

$(NAME): $(OBJS)
	$(AR) $(ARFLAGS) $(NAME) $(OBJS)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@ -I $(HEADER)

all: $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean all re

