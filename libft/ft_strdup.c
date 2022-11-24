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
	char	*allocated;
	size_t	size;

	size = sizeof(char) * (ft_strlen(s1) + 1);
	allocated = malloc(size);
	if (allocated == NULL)
		return (NULL);
	ft_strlcpy(allocated, s1, size);
	return (allocated);
}
