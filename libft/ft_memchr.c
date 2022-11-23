/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euihlee <euihlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 00:01:02 by euihlee           #+#    #+#             */
/*   Updated: 2022/11/24 00:12:35 by euihlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*t;
	unsigned char	ch;

	t = (unsigned char *) s;
	ch = (unsigned char) c;
	while (n-- > 0)
	{
		if (*t == ch)
			return ((void *) t);
		t++;
	}
	return (NULL);
}
