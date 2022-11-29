/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euihlee <euihlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 13:32:57 by euihlee           #+#    #+#             */
/*   Updated: 2022/11/24 13:41:33 by euihlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	bytes;
	void	*malloced;

	bytes = count * size;
	if (bytes / count != size)
		return (NULL);
	malloced = malloc(bytes);
	if (malloced == NULL)
		return (NULL);
	return (ft_memset(malloced, 0, bytes));
}
