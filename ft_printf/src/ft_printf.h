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

int	ft_printf(const char *fstring, ...);

int	convert_specification(const char *fstring, va_list ap);

# define NULL_MSG "(null)"

int	print_char(char c);
int	print_str(char *string);

# define DECIMAL "0123456789"
# define LHEX "0123456789abcdef"
# define UHEX "0123456789ABCDEF"
# define PTR_PREFIX "0x"

# define FT_PRINTF_BUFSIZ 32

typedef unsigned long long	t_ullong;

int	print_ullong(t_ullong n, unsigned int base_dec, char *base_str);
int	print_int(int n, unsigned int base_dec, char *base_str);
int	print_ptr(void *ptr);

#endif
