/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euihlee <euihlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 14:27:02 by euihlee           #+#    #+#             */
/*   Updated: 2022/12/07 17:42:59 by euihlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t		get_len(int n);

char	*ft_itoa(int n)
{
	size_t			len;
	unsigned int	un;
	char			*str;

	len = get_len(n);
	un = (unsigned int) n;
	if (n < 0)
		un = 0u - un;
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

static size_t	get_len(int n)
{
	size_t			len;
	unsigned int	un;

	len = 1;
	un = (unsigned int) n;
	if (n < 0)
	{
		un = 0u - un;
		len++;
	}
	while (un > 9)
	{
		un /= 10;
		len++;
	}
	return (len);
}
