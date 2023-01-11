/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_num_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euihlee <euihlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 12:27:22 by euihlee           #+#    #+#             */
/*   Updated: 2022/12/31 12:27:27 by euihlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

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

int	print_int(int n, unsigned int base_dec, char *base_str)
{
	int			printed;
	int			written;
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

int	print_ptr(void *ptr)
{
	t_ullong	ullong;
	int			printed;
	int			written;

	ullong = (t_ullong) ptr;
	printed = write(STDOUT, PTR_PREFIX, ft_strlen(PTR_PREFIX));
	if (printed < 0)
		return (printed);
	written = print_ullong(ullong, 16, LHEX);
	if (written < 0)
		return (written);
	printed += written;
	return (printed);
}
