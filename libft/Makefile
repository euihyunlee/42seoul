CC = gcc
CFLAGS = -Wall -Wextra -Werror

sources = ft_isalpha.c ft_isdigit.c ft_isalnum.c
objects = $(sources:.c=.o)
NAME = libft.a

.PHONY : all
all : $(NAME)

$(NAME) : $(objects)
	ar -rv $@ $^

$(objects) : libft.h

.PHONY : re
re: fclean all

.PHONY : fclean
fclean : clean
	rm -f $(NAME)

.PHONY : clean
clean :
	rm -f $(objects)
