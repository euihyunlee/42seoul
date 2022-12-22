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

NAME = libft.a

sources = \
ft_isalpha.c    ft_isdigit.c    ft_isalnum.c    ft_isascii.c    ft_isprint.c \
ft_strlen.c     ft_memset.c     ft_bzero.c      ft_memcpy.c     ft_memmove.c \
ft_strlcpy.c    ft_strlcat.c    ft_toupper.c    ft_tolower.c    ft_strchr.c \
ft_strrchr.c    ft_strncmp.c    ft_memchr.c     ft_memcmp.c     ft_strnstr.c \
ft_atoi.c       ft_calloc.c     ft_strdup.c \
\
ft_substr.c     ft_strjoin.c    ft_strtrim.c    ft_split.c \
ft_itoa.c       ft_strmapi.c    ft_striteri.c   ft_putchar_fd.c \
ft_putstr_fd.c  ft_putendl_fd.c ft_putnbr_fd.c

bonuses = \
ft_lstnew.c         ft_lstadd_front.c   ft_lstsize.c    ft_lstlast.c \
ft_lstadd_back.c    ft_lstdelone.c      ft_lstclear.c   ft_lstiter.c \
ft_lstmap.c

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
