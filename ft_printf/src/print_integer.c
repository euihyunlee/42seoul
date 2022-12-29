/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_integer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euihlee <euihlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 16:36:48 by euihlee           #+#    #+#             */
/*   Updated: 2022/12/29 19:11:58 by euihlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_integer(int n, unsigned int base_dec, char *base_str)
{
	int			written;
	int			printed;
	t_ullong	ullong;

	printed = 0;
	ullong = (t_ullong) n;
	if (n < 0)
	{
		written = write(STDOUT, "-", 1);
		if (written < 0)
			return (written);
		printed += written;
		ullong = 0ULL - ullong;
	}
	written = print_ullong(ullong, base_dec, base_str);
	if (written < 0)
		return (written);
	printed += written;
	return (printed);
}

int	print_pointer(void *ptr)
{
	t_ullong	ullong;
	int			written;
	int			printed;

	ullong = (t_ullong) ptr;
	written = write(STDOUT, "0x", 2);
	if (written < 0)
		return (written);
	printed = written;
	written = print_ullong(ullong, 16, LHEX);
	if (written < 0)
		return (written);
	printed += written;
	return (printed);
}

int	print_ullong(t_ullong n, unsigned int base_dec, char *base_str)
{
	char	buffer[FT_PRINTF_BUFSIZ];
	int		setback;

	if (n == 0)
		return (write(STDOUT, base_str, 1));
	setback = FT_PRINTF_BUFSIZ;
	while (n != 0)
	{
		buffer[--setback] = base_str[n % base_dec];
		n /= base_dec;
	}
	return (write(STDOUT, buffer + setback, FT_PRINTF_BUFSIZ - setback));
}
