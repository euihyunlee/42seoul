/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euihlee <euihlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 14:27:02 by euihlee           #+#    #+#             */
/*   Updated: 2022/11/29 23:19:08 by euihlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#define MAX_DIGITS 22

char	*ft_itoa(int n)
{
	char			buffer[MAX_DIGITS];
	char			*ptr;
	unsigned int	un;

	ptr = buffer + MAX_DIGITS - 1;
	*ptr = '\0';
	if (n == 0)
	{
		*--ptr = '0';
		return (ft_strdup(ptr));
	}
	un = (unsigned int) n;
	if (n < 0)
		un = -un;
	while (un != 0)
	{
		*--ptr = (un % 10) + '0';
		un /= 10;
	}
	if (n < 0)
		*--ptr = '-';
	return (ft_strdup(ptr));
}
