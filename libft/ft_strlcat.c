/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euihlee <euihlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 17:56:43 by euihlee           #+#    #+#             */
/*   Updated: 2022/11/21 17:58:38 by euihlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t		srclen;
	size_t		dstlen;

	srclen = ft_strlen(src);
	dstlen = 0;
	while (*dst && dstlen < dstsize)
	{
		dst++;
		dstlen++;
	}
	dstsize -= dstlen;
	if (dstsize == 0)
		return (dstlen + srclen);
	while (*src && dstsize-- > 1)
		*dst++ = *src++;
	*dst = '\0';
	return (dstlen + srclen);
}
