CC = gcc
CFLAGS = -Wall -Wextra -Werror

sources = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
		  ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c \
		  ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c \
		  ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c  ft_strnstr.c \
		  ft_atoi.c ft_calloc.c ft_strdup.c \
		  ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c \
		  ft_strmapi.c ft_striteri.c ft_putchar_fd.c
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

debug : ft_itoa.c
	$(CC) $(CFLAGS) -g $^ -o debug
