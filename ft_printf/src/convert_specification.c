/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_specification.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euihlee <euihlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 12:07:05 by euihlee           #+#    #+#             */
/*   Updated: 2023/01/18 13:25:51 by euihlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	convert_specification(const char *format, va_list ap)
{
	if (*format == '%')
		return (write(STDOUT, format, 1));
	else if (*format == 'c')
		return (print_char(va_arg(ap, int)));
	else if (*format == 's')
		return (print_str((char *) va_arg(ap, void *)));
	else if (*format == 'p')
		return (print_ptr(va_arg(ap, void *)));
	else if (*format == 'd')
		return (print_int(va_arg(ap, int), 10, DECIMAL));
	else if (*format == 'i')
		return (print_int(va_arg(ap, int), 10, DECIMAL));
	else if (*format == 'u')
		return (print_ullong(va_arg(ap, unsigned int), 10, DECIMAL));
	else if (*format == 'x')
		return (print_ullong(va_arg(ap, unsigned int), 16, LHEX));
	else if (*format == 'X')
		return (print_ullong(va_arg(ap, unsigned int), 16, UHEX));
	else
		return (-1);
}
