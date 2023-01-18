/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euihlee <euihlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 12:00:24 by euihlee           #+#    #+#             */
/*   Updated: 2023/01/11 12:30:16 by euihlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

# include "./libft/libft.h"

# define STDOUT 1
# define FT_PRINTF_BUFSIZ 32

typedef struct s_spec
{
	const char	*spec;
	int			specified;
	int			converted;
}				t_spec;

int	ft_printf(const char *fstring, ...);

int	init_spec(t_spec *spec, const char *fstring);
int	convert_spec(t_spec *spec, va_list ap);

# define NULL_MSG "(null)"

int	print_char(char c);
int	print_str(char *string);

# define DECIMAL "0123456789"
# define LHEX "0123456789abcdef"
# define UHEX "0123456789ABCDEF"
# define PTR_PREFIX "0x"

typedef unsigned long long	t_ullong;

int	print_ullong(t_ullong n, unsigned int base_dec, char *base_str);
int	print_int(int n, unsigned int base_dec, char *base_str);
int	print_ptr(void *ptr);

#endif
