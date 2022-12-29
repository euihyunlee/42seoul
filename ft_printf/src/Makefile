# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: euihlee <euihlee@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/26 21:32:38 by euihlee           #+#    #+#              #
#    Updated: 2022/12/22 13:39:39 by euihlee          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar
ARFLAGS = -rcs

NAME = libftprintf.a

sources = \

bonuses = \

sources_objects = $(sources:.c=.o)
bonuses_objects = $(bonuses:.c=.o)

ifdef WITH_BONUS
	objects = $(sources_objects) $(bonuses_objects)
else
	objects = $(sources_objects)
endif

.PHONY : all
all : $(NAME)

$(NAME) : $(objects)
	$(AR) $(ARFLAGS) $@ $^

.PHONY : bonus
bonus :
	$(MAKE) WITH_BONUS=1 all

.PHONY : re
re: fclean
	$(MAKE) all

.PHONY : fclean
fclean : clean
	rm -f $(NAME)

.PHONY : clean
clean :
	rm -f $(sources_objects) $(bonuses_objects)
