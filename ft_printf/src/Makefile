# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: euihlee <euihlee@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/26 21:32:38 by euihlee           #+#    #+#              #
#    Updated: 2023/02/07 16:30:42 by euihlee          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar
ARFLAGS = -rcs

LIBFT_DIR = ./libft
LIBFT = libft.a

NAME = libftprintf.a

sources = \
ft_printf.c     ft_printf_utils.c \

objects = $(sources:.c=.o)

.PHONY : all
all : $(NAME)

$(NAME) : $(objects)
	${MAKE} -C ${LIBFT_DIR} all
	cp ${LIBFT_DIR}/${LIBFT} ${NAME}
	$(AR) $(ARFLAGS) $@ $^

.PHONY : re
re: fclean
	$(MAKE) all

.PHONY : fclean
fclean : clean
	rm -f $(NAME)

.PHONY : clean
clean :
	${MAKE} -C ${LIBFT_DIR} fclean
	rm -f $(objects)
