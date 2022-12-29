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
	int		written;
	int		printed;

	va_start(ap, fstring);
	printed = 0;
	while (*fstring)
	{
		if (*fstring != '%')
		{
			written = write(STDOUT, fstring++, 1);
			if (written < 0)
				return (written);
			printed += written;
			continue ;
		}
		fstring++;
		written = convert_specification(fstring++, ap);
		if (written < 0)
			return (written);
		printed += written;
	}
	va_end(ap);
	return (printed);
}
