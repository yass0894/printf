# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yibrahim <yibrahim@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/14 17:07:48 by yibrahim          #+#    #+#              #
#    Updated: 2024/10/14 17:23:29 by yibrahim         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = ft_printf.c printing.c ft_puthexnbr.c\

OBJS = $(SRC:.c=.o)

CC = gcc
CFLAGS = -Wall -Werror -Wextra

AR = ar rcs
INCLUDE = ft_printf.h

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
		$(AR) $@ $^

clean:
		rm -f $(NAME)

fclean: clean
		rm -f $(NAME)
re: fclean all

.PHONY: all clean fclean re