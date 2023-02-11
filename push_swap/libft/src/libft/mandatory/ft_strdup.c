/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euihlee <euihlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 13:43:06 by euihlee           #+#    #+#             */
/*   Updated: 2022/11/24 13:47:27 by euihlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	bytes;
	char	*malloced;

	bytes = (ft_strlen(s1) + 1) * sizeof(*s1);
	malloced = malloc(bytes);
	if (malloced == NULL)
		return (NULL);
	ft_memcpy(malloced, s1, bytes);
	return (malloced);
}
