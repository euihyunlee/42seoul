/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euihlee <euihlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 18:04:26 by euihlee           #+#    #+#             */
/*   Updated: 2022/11/29 20:44:34 by euihlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(int c);
static long	tol(const char *str, int sign);

int	ft_atoi(const char *str)
{
	int	sign;

	while (ft_isspace(*str))
		str++;
	sign = 1;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	return ((int) tol(str, sign));
}

static int	ft_isspace(int c)
{
	return (c == ' ' || c == '\t' || c == '\n'
		|| c == '\v' || c == '\f' || c == '\r');
}

static long	tol(const char *str, int sign)
{
	unsigned long	ul;
	unsigned long	cutoff;
	int				cutlim;
	int				digit;

	cutoff = __LONG_MAX__ / 10;
	cutlim = __LONG_MAX__ % 10;
	if (sign < 0)
		cutlim++;
	ul = 0;
	while (ft_isdigit(*str))
	{
		digit = *str - '0';
		if (ul > cutoff || (ul == cutoff && digit > cutlim))
		{
			if (sign < 0)
				return (-(__LONG_MAX__) - 1);
			return (__LONG_MAX__);
		}
		ul = ul * 10 + digit;
		str++;
	}
	return (sign * ul);
}
