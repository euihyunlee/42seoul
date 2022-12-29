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

// int	convert_specification(const char *fstring, va_list ap)
// {
// 	va_list	local_ap;
// 	int		printed;

// 	va_copy(local_ap, ap);
// 	printed = -1;
// 	if (*fstring == '%')
// 		printed = write(STDOUT, fstring, 1);
// 	else if (*fstring == 'c')
// 		printed = print_char(va_arg(local_ap, int));
// 	else if (*fstring == 's')
// 		printed = print_string((char *) va_arg(local_ap, void *));
// 	else if (*fstring == 'p')
// 		printed = print_ullong((t_ullong) va_arg(local_ap, void *), 16, LHEX);
// 	else if (*fstring == 'd')
// 		printed = print_integer(va_arg(local_ap, int), 10, DECIMAL);
// 	else if (*fstring == 'i')
// 		printed = print_integer(va_arg(local_ap, int), 10, DECIMAL);
// 	else if (*fstring == 'u')
// 		printed = print_ullong(va_arg(local_ap, int), 10, DECIMAL);
// 	else if (*fstring == 'x')
// 		printed = print_integer(va_arg(local_ap, int), 16, LHEX);
// 	else if (*fstring == 'X')
// 		printed = print_integer(va_arg(local_ap, int), 16, UHEX);
// 	va_end(local_ap);
// 	return (printed);
// }

int	convert_specification(const char *fstring, va_list ap)
{
	int		printed;

	printed = -1;
	if (*fstring == '%')
		printed = write(STDOUT, fstring, 1);
	else if (*fstring == 'c')
		printed = print_char(va_arg(ap, int));
	else if (*fstring == 's')
		printed = print_string((char *) va_arg(ap, void *));
	else if (*fstring == 'p')
		printed = print_pointer(va_arg(ap, void *));
	else if (*fstring == 'd')
		printed = print_integer(va_arg(ap, int), 10, DECIMAL);
	else if (*fstring == 'i')
		printed = print_integer(va_arg(ap, int), 10, DECIMAL);
	else if (*fstring == 'u')
		printed = print_ullong(va_arg(ap, unsigned int), 10, DECIMAL);
	else if (*fstring == 'x')
		printed = print_ullong(va_arg(ap, unsigned int), 16, LHEX);
	else if (*fstring == 'X')
		printed = print_ullong(va_arg(ap, unsigned int), 16, UHEX);
	return (printed);
}
