# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: euihlee <euihlee@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/26 21:32:38 by euihlee           #+#    #+#              #
#    Updated: 2022/12/29 19:19:13 by euihlee          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar
ARFLAGS = -rcs

NAME = libftprintf.a

sources = \
ft_printf.c     convert_specification.c     print_text.c    print_num.c \

objects = $(sources:.c=.o)

.PHONY : all
all : $(NAME)

$(NAME) : $(objects)
	$(AR) $(ARFLAGS) $@ $^

.PHONY : re
re: fclean
	$(MAKE) all

.PHONY : fclean
fclean : clean
	rm -f $(NAME)

.PHONY : clean
clean :
	rm -f $(objects)
