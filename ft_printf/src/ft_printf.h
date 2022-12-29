/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euihlee <euihlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 12:00:24 by euihlee           #+#    #+#             */
/*   Updated: 2022/12/29 19:00:47 by euihlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

# define STDOUT 1

# define FT_PRINTF_BUFSIZ 32

typedef unsigned long long	t_ullong;

int	ft_printf(const char *fstring, ...);

int	convert_specification(const char *fstring, va_list ap);

int	print_char(char c);
int	print_string(char *string);

# define DECIMAL "0123456789"
# define LHEX "0123456789abcdef"
# define UHEX "0123456789ABCDEF"

int	print_integer(int n, unsigned int base_dec, char *base_str);
int	print_pointer(void *ptr);
int	print_ullong(t_ullong n, unsigned int base_dec, char *base_str);

#endif
