# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: euihlee <euihlee@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/26 21:32:38 by euihlee           #+#    #+#              #
#    Updated: 2023/02/08 14:39:41 by euihlee          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror -I .
AR = ar
ARFLAGS = -rcs

NAME = libft.a

VPATH = mandatory:bonus:printf:get_next_line:add

sources = \
ft_isalpha.c    ft_isdigit.c    ft_isalnum.c    ft_isascii.c    ft_isprint.c \
ft_strlen.c     ft_memset.c     ft_bzero.c      ft_memcpy.c     ft_memmove.c \
ft_strlcpy.c    ft_strlcat.c    ft_toupper.c    ft_tolower.c    ft_strchr.c \
ft_strrchr.c    ft_strncmp.c    ft_memchr.c     ft_memcmp.c     ft_strnstr.c \
ft_atoi.c       ft_calloc.c     ft_strdup.c \
\
ft_substr.c     ft_strjoin.c    ft_strtrim.c    ft_split.c \
ft_itoa.c       ft_strmapi.c    ft_striteri.c   ft_putchar_fd.c \
ft_putstr_fd.c  ft_putendl_fd.c ft_putnbr_fd.c \
\
ft_lstnew.c         ft_lstadd_front.c   ft_lstsize.c    ft_lstlast.c \
ft_lstadd_back.c    ft_lstdelone.c      ft_lstclear.c   ft_lstiter.c \
ft_lstmap.c \
\
ft_printf.c         ft_printf_utils.c \
\
get_next_line.c     get_next_line_utils.c \
\
ft_isdecimal.c

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
