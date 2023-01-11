/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euihlee <euihlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 11:59:21 by euihlee           #+#    #+#             */
/*   Updated: 2022/12/29 18:34:56 by euihlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_printf(const char *fstring, ...)
{
	va_list	ap;
	t_spec	spec;
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
		if (init_spec(&spec, ++fstring) < 0 || convert_spec(&spec, ap) < 0)
			return (-1);
		printed += spec.converted;
		fstring += spec.specified;
	}
	va_end(ap);
	return (printed);
}
