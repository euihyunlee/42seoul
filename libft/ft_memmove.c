/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euihlee <euihlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 16:50:02 by euihlee           #+#    #+#             */
/*   Updated: 2022/11/23 20:42:46 by euihlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*dstcpy;
	unsigned char	*srccpy;

	if (len == 0 || dst == src)
		return (dst);
	dstcpy = (unsigned char *) dst;
	srccpy = (unsigned char *) src;
	if (srccpy < dstcpy)
	{
		while (len-- > 0)
			dstcpy[len] = srccpy[len];
		return (dst);
	}
	while (len-- > 0)
		*dstcpy++ = *srccpy++;
	return (dst);
}
