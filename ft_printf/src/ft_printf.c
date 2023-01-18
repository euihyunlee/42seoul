/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euihlee <euihlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 11:59:21 by euihlee           #+#    #+#             */
/*   Updated: 2023/01/18 13:26:08 by euihlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		converted;
	int		printed;

	va_start(ap, format);
	printed = 0;
	while (*format)
	{
		if (*format != '%')
		{
			if (write(STDOUT, format++, 1) < 0)
				return (-1);
			printed++;
			continue ;
		}
		format++;
		converted = convert_specification(format++, ap);
		if (converted < 0)
			return (converted);
		printed += converted;
	}
	va_end(ap);
	return (printed);
}
