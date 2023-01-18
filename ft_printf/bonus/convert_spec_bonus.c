/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_spec.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euihlee <euihlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 12:07:48 by euihlee           #+#    #+#             */
/*   Updated: 2023/01/11 12:07:57 by euihlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	init_spec(t_spec *spec, const char *fstring)
{
	spec->spec = fstring;
	spec->specified = 1;
	spec->converted = 0;
	return (spec->specified);
}

int	convert_spec(t_spec *spec, va_list ap)
{
	if (*(spec->spec) == '%')
		spec->converted = write(STDOUT, spec->spec, 1);
	else if (*(spec->spec) == 'c')
		spec->converted = print_char(va_arg(ap, int));
	else if (*(spec->spec) == 's')
		spec->converted = print_str((char *) va_arg(ap, void *));
	else if (*(spec->spec) == 'p')
		spec->converted = print_ptr(va_arg(ap, void *));
	else if (*(spec->spec) == 'd')
		spec->converted = print_int(va_arg(ap, int), 10, DECIMAL);
	else if (*(spec->spec) == 'i')
		spec->converted = print_int(va_arg(ap, int), 10, DECIMAL);
	else if (*(spec->spec) == 'u')
		spec->converted = print_ullong(va_arg(ap, unsigned int), 10, DECIMAL);
	else if (*(spec->spec) == 'x')
		spec->converted = print_ullong(va_arg(ap, unsigned int), 16, LHEX);
	else if (*(spec->spec) == 'X')
		spec->converted = print_ullong(va_arg(ap, unsigned int), 16, UHEX);
	else
		spec->converted = -1;
	return (spec->converted);
}
