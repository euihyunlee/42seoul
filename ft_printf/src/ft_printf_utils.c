/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euihlee <euihlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 16:27:49 by euihlee           #+#    #+#             */
/*   Updated: 2023/02/07 16:28:13 by euihlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_char(char c)
{
	return (write(STDOUT, &c, 1));
}

int	print_str(char *str)
{
	if (str == NULL)
		return (write(STDOUT, NULL_MSG, ft_strlen(NULL_MSG)));
	return (write(STDOUT, str, ft_strlen(str)));
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

int	print_int(int n, unsigned int base_dec, char *base_str)
{
	t_ullong	ullong;
	int			printed;
	int			expected;

	printed = 0;
	ullong = (t_ullong) n;
	if (n < 0)
	{
		ullong = 0ULL - ullong;
		if (write(STDOUT, "-", 1) < 0)
			return (-1);
		printed++;
	}
	expected = print_ullong(ullong, base_dec, base_str);
	if (expected < 0)
		return (expected);
	printed += expected;
	return (printed);
}

int	print_ptr(void *ptr)
{
	t_ullong	ullong;
	int			printed;
	int			expected;

	ullong = (t_ullong) ptr;
	printed = write(STDOUT, PTR_PREFIX, ft_strlen(PTR_PREFIX));
	if (printed < 0)
		return (printed);
	expected = print_ullong(ullong, 16, LHEX);
	if (expected < 0)
		return (expected);
	printed += expected;
	return (printed);
}
