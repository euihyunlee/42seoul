/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euihlee <euihlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 12:15:06 by euihlee           #+#    #+#             */
/*   Updated: 2022/12/29 19:04:15 by euihlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	convert_specification(const char *fstring, va_list ap)
{
	if (*fstring == '%')
		return (write(STDOUT, fstring, 1));
	else if (*fstring == 'c')
		return (print_char(va_arg(ap, int)));
	else if (*fstring == 's')
		return (print_str((char *) va_arg(ap, void *)));
	else if (*fstring == 'p')
		return (print_ptr(va_arg(ap, void *)));
	else if (*fstring == 'd')
		return (print_int(va_arg(ap, int), 10, DECIMAL));
	else if (*fstring == 'i')
		return (print_int(va_arg(ap, int), 10, DECIMAL));
	else if (*fstring == 'u')
		return (print_ullong(va_arg(ap, unsigned int), 10, DECIMAL));
	else if (*fstring == 'x')
		return (print_ullong(va_arg(ap, unsigned int), 16, LHEX));
	else if (*fstring == 'X')
		return (print_ullong(va_arg(ap, unsigned int), 16, UHEX));
	else
		return (-1);
}
