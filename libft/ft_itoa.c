/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euihlee <euihlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 14:27:02 by euihlee           #+#    #+#             */
/*   Updated: 2022/11/26 15:25:26 by euihlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_len(unsigned int n);

char	*ft_itoa(int n)
{
	unsigned int	un;
	bool			is_negative;
	size_t			len;
	char			*nstr;

	is_negative = n < 0;
	if (is_negative)
		un = n * -1;
	else
		un = n;
	len = get_len(un);
	if (is_negative)
		len++;
	nstr = malloc((len + 1) * sizeof(*nstr));
	if (nstr == NULL)
		return (NULL);
	nstr[len] = '\0';
	while (len-- > 0)
	{
		nstr[len] = '0' + (un % 10);
		un /= 10;
	}
	if (is_negative)
		nstr[0] = '-';
	return (nstr);
}

static size_t	get_len(unsigned int n)
{
	size_t	len;

	len = 1;
	while (n > 9)
	{
		n /= 10;
		len++;
	}
	return (len);
}
