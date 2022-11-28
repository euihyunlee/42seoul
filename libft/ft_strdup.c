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
	size_t	size;
	char	*malloced;

	size = (ft_strlen(s1) + 1) * sizeof(char);
	malloced = malloc(size);
	if (malloced == NULL)
		return (NULL);
	ft_strlcpy(malloced, s1, size);
	return (malloced);
}
