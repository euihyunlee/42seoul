/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euihlee <euihlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 13:32:57 by euihlee           #+#    #+#             */
/*   Updated: 2022/12/05 10:48:52 by euihlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*malloced;

	if (count != 0 && SIZE_MAX / count < size)
		return (NULL);
	malloced = malloc(count * size);
	if (malloced == NULL)
		return (NULL);
	return (ft_memset(malloced, 0, count * size));
}
