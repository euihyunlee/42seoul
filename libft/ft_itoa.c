/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euihlee <euihlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 14:27:02 by euihlee           #+#    #+#             */
/*   Updated: 2022/11/28 12:08:57 by euihlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	to_unsigned(int n);
static size_t		get_len(int n);

char	*ft_itoa(int n)
{
	unsigned int	un;
	size_t			len;
	char			*str;

	un = to_unsigned(n);
	len = get_len(n);
	str = malloc((len + 1) * sizeof(*str));
	if (str == NULL)
		return (NULL);
	str[len] = '\0';
	while (len-- > 0)
	{
		str[len] = (un % 10) + '0';
		un /= 10;
	}
	if (n < 0)
		str[0] = '-';
	return (str);
}

static unsigned int	to_unsigned(int n)
{
	if (n < 0)
		return ((unsigned int) n * -1);
	return ((unsigned int) n);
}

static size_t	get_len(int n)
{
	size_t			len;
	unsigned int	un;

	len = 1;
	un = n;
	if (n < 0)
	{
		un *= -1;
		len++;
	}
	while (un > 9)
	{
		un /= 10;
		len++;
	}
	return (len);
}
