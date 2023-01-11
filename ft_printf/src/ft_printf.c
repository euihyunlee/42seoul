/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euihlee <euihlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 11:59:21 by euihlee           #+#    #+#             */
/*   Updated: 2022/12/29 18:34:56 by euihlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *fstring, ...)
{
	va_list	ap;
	int		converted;
	int		printed;

	va_start(ap, fstring);
	printed = 0;
	while (*fstring)
	{
		if (*fstring != '%')
		{
			if (write(STDOUT, fstring++, 1) < 0)
				return (-1);
			printed++;
			continue ;
		}
		fstring++;
		converted = convert_specification(fstring++, ap);
		if (converted < 0)
			return (converted);
		printed += converted;
	}
	va_end(ap);
	return (printed);
}
