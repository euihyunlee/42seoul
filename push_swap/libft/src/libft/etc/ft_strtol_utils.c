/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtol_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euihlee <euihlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 11:36:12 by euihlee           #+#    #+#             */
/*   Updated: 2023/02/11 12:09:38 by euihlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_bool	is_hex(const char *str)
{
	t_bool	hex;

	hex = (str[0] == '0' && (str[1] == 'x' || str[1] == 'X')
			&& (('0' <= str[2] && str[2] <= '9')
				|| ('A' <= str[2] && str[2] <= 'F')
				|| ('a' <= str[2] && str[2] <= 'f')));
	return (hex);
}

void	get_cut(long *cut, int base, int sign)
{
	unsigned long	cutoff;

	cutoff = LONG_MAX;
	if (sign < 0)
		cutoff = (unsigned long) -(LONG_MIN + LONG_MAX) + LONG_MAX;
	cut[1] = cutoff % base;
	cut[0] = cutoff / base;
}

int	get_digit(char c, int base)
{
	if ('0' <= c && c <= '9')
		c -= '0';
	else if ('A' <= c && c <= 'F')
		c -= 'A' - 10;
	else if ('a' <= c && c <= 'f')
		c -= 'a' - 10;
	else
		return (STRTOL_EINVAL);
	if (c >= base)
		return (STRTOL_EINVAL);
	return (c);
}
