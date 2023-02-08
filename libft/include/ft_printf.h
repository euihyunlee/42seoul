/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euihlee <euihlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 12:00:24 by euihlee           #+#    #+#             */
/*   Updated: 2023/02/08 14:35:43 by euihlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

# include "libft.h"

# define STDOUT 1

# define NULL_MSG "(null)"

# define DECIMAL "0123456789"
# define LHEX "0123456789abcdef"
# define UHEX "0123456789ABCDEF"
# define PTR_PREFIX "0x"

# define FT_PRINTF_BUFSIZ 32

typedef unsigned long long	t_ullong;

int	ft_printf(const char *format, ...);
int	convert_specification(const char *format, va_list ap);

int	print_char(char c);
int	print_str(char *string);
int	print_ullong(t_ullong n, unsigned int base_dec, char *base_str);
int	print_int(int n, unsigned int base_dec, char *base_str);
int	print_ptr(void *ptr);

#endif
