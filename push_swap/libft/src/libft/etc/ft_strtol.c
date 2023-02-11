/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtol.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euihlee <euihlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 11:35:29 by euihlee           #+#    #+#             */
/*   Updated: 2023/02/11 12:05:21 by euihlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_bool	is_hex(const char *str);
long	get_l(const char *str, char **endptr, int base, int sign);
int		get_cut(long *cut, int base, int sign);
int		get_digit(char c, int base);
long	get_return(int flag, int sign, long val);

long	ft_strtol(const char *str, char **endptr, int base)
{
	int	sign;

	if (endptr)
		*endptr = (char *) str;
	while (ft_isspace(*str))
		str++;
	sign = 1;
	if (*str == '-')
		sign = -1;
	if (*str == '-' || *str == '+')
		str++;
	if ((base == 0 || base == 16) && is_hex(str))
	{
		base = 16;
		str += 2;
	}
	if (base == 0 && *str == '0')
	{
		base = 8;
		str++;
	}
	if (base == 0)
		base = 10;
	return (get_l(str, endptr, base, sign));
}

long	get_l(const char *str, char **endptr, int base, int sign)
{
	long	cut[2];
	int		flag;
	int		digit;
	long	val;

	get_cut(cut, base, sign);
	flag = 0;
	val = 0;
	while (*str)
	{
		digit = get_digit(*str, base);
		if (digit < 0)
			break ;
		if (flag < 0 || val > cut[0] || (val == cut[0] && digit > cut[1]))
			flag = -1;
		else
		{
			flag = 1;
			val = val * base + digit;
		}
		str++;
	}
	if (endptr && flag)
		*endptr = (char *) str;
	return (get_return(flag, sign, val));
}

long	get_return(int flag, int sign, long val)
{
	if (flag < 0)
	{
		if (sign < 0)
			return (LONG_MIN);
		return (LONG_MAX);
	}
	return (sign * val);
}
