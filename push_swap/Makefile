# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: euihlee <euihlee@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/30 16:19:40 by euihlee           #+#    #+#              #
#    Updated: 2023/02/19 09:46:40 by euihlee          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

libft_dir = libft
libft = libft.a

include_dirs = include libft/include

CC = cc
CFLAGS = -Wall -Wextra -Werror -L$(libft_dir) -lft \
		 $(foreach dir, $(include_dirs), -I$(dir))

sources_dir = src/
sources = \
main.c      push_swap.c     push_args.c     instructions.c

objects = $(sources:.c=.o)

.PHONY : all
all : $(NAME)

$(NAME) :
	${MAKE} -C ${libft_dir} all
	$(CC) $(CFLAGS) $(addprefix $(sources_dir), $(sources)) -o $(NAME)

debug :
	${MAKE} -C ${libft_dir} all
	$(CC) $(CFLAGS) -g $(addprefix $(sources_dir), $(sources)) -o $(NAME)

.PHONY : re
re: fclean
	$(MAKE) all
	$(MAKE) clean

.PHONY : fclean
fclean : clean
	rm -f $(NAME)

.PHONY : clean
clean :
	${MAKE} -C ${libft_dir} fclean
	rm -f $(objects)
