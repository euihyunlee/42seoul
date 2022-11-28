/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euihlee <euihlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 12:09:30 by euihlee           #+#    #+#             */
/*   Updated: 2022/11/23 16:45:25 by euihlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	nlen;

	nlen = ft_strlen(needle);
	if (nlen == 0)
		return ((char *) haystack);
	while (*haystack && len-- > nlen - 1)
	{
		if (ft_strncmp(needle, haystack, nlen) == 0)
			return ((char *) haystack);
		haystack++;
	}
	return (NULL);
}
