# Libft

This project is about coding a C library. It will contain a lot of general purpose functions your program will rely upon.


## Mandatory Part

### Libc Functions

- [x] `int ft_isalpha(int c)`
- [x] `int ft_isdigit(int c)`
- [x] `int ft_isalnum(int c)`
- [x] `int ft_isascii(int c)`
- [x] `int ft_isprint(int c)`
- [x] `size_t ft_strlen(const char *s)`
- [x] `void *ft_memset(void *b, int c, size_t len)`
- [x] `void ft_bzero(void *s, size_t n)`
- [x] `void *ft_memcpy(void *dst, const void *src, size_t n)`
- [x] `void *ft_memmove(void *dst, const void *src, size_t len)`
- [x] `size_t ft_strlcpy(char *dst, const char *src, size_t dstsize)`
- [x] `size_t ft_strlcat(char *dst, const char *src, size_t dstsize)`
- [x] `int ft_toupper(int c)`
- [x] `int ft_tolower(int c)`
- [x] `char *ft_strchr(const char *s, int c)`
- [x] `char *ft_strrchr(const char *s, int c)`
- [x] `int ft_strncmp(const char *s1, const char *s2, size_t n)`
- [x] `void *ft_memchr(const void *s, int c, size_t n)`
- [x] `int ft_memcmp(const void *s1, const void *s2, size_t n)`
- [x] `char *ft_strnstr(const char *haystack, const char *needle, size_t len)`
- [x] `int ft_atoi(const char *str)`
- [x] `void *ft_calloc(size_t count, size_t size)`
- [x] `char *ft_strdup(const char *s1)`

### Additional Functions

- [x] `char *ft_substr(char const *s, unsigned int start, size_t len)`
- [x] `char *ft_strjoin(char const *s1, char const *s2)`
- [x] `char *ft_strtrim(char const *s1, char const *set)`
- [x] `char **ft_split(char const *s, char c)`
- [x] `char *ft_itoa(int n)`
- [x] `char *ft_strmapi(char const *s, char (*f)(unsigned int, char))`
- [x] `void ft_striteri(char *s, void (*f)(unsigned int, char *))`
- [x] `void ft_putchar_fd(char c, int fd)`
- [x] `void ft_putstr_fd(char *s, int fd)`
- [x] `void ft_putendl_fd(char *s, int fd)`
- [x] `void ft_putnbr_fd(int n, int fd)`


## Bonus Part

- [x] `t_list *ft_lstnew(void *content)`
- [x] `void ft_lstadd_front(t_list **lst, t_list *new)`
- [x] `int ft_lstsize(t_list *lst)`
- [x] `t_list *ft_lstlast(t_list *lst)`
- [x] `void ft_lstadd_back(t_list **lst, t_list *new)`
- [x] `void ft_lstdelone(t_list *lst, void (*del)(void *))`
- [x] `void ft_lstclear(t_list **lst, void (*del)(void *))`
- [x] `void ft_lstiter(t_list *lst, void (*f)(void *))`
- [x] `t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))`
