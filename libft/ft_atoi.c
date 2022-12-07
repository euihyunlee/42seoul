/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euihlee <euihlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 18:04:26 by euihlee           #+#    #+#             */
/*   Updated: 2022/12/07 17:28:58 by euihlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long	to_long(const char *str, long cutoff, int remainder);
static int	ft_isspace(int c);

int	ft_atoi(const char *str)
{
	int		sign;
	long	cutoff;
	int		remainder;
	long	number;

	while (ft_isspace(*str))
		str++;
	sign = 1;
	if (*str == '-')
		sign = -1;
	if (*str == '-' || *str == '+')
		str++;
	cutoff = LONG_MAX / 10;
	remainder = LONG_MAX % 10;
	if (sign < 0)
		remainder++;
	number = to_long(str, cutoff, remainder);
	if (number >= 0)
		return (sign * (int) number);
	if (sign < 0)
		return ((int) LONG_MIN);
	return ((int) LONG_MAX);
}

static long	to_long(const char *str, long cutoff, int remainder)
{
	long	number;
	int		digit;

	number = 0;
	while (ft_isdigit(*str))
	{
		digit = *str++ - '0';
		if (number > cutoff || (number == cutoff && digit > remainder))
			return (-1);
		number = number * 10 + digit;
	}
	return (number);
}

static int	ft_isspace(int c)
{
	return (c == ' ' || c == '\t' || c == '\n'
		|| c == '\v' || c == '\f' || c == '\r');
}
