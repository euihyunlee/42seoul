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
	size_t	dstlen;
	size_t	srclen;
	char	*end;

	dstlen = ft_strlen(dst);
	srclen = ft_strlen(src);
	if (dstsize == 0 || dstlen > dstsize)
		return (dstsize + srclen);
	end = dst + dstsize - 1;
	while (*dst)
		dst++;
	while (dst < end && *src)
		*dst++ = *src++;
	*dst = '\0';
	return (dstlen + srclen);
}
