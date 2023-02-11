/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euihlee <euihlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 18:00:08 by euihlee           #+#    #+#             */
/*   Updated: 2022/11/21 18:03:17 by euihlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*t1;
	unsigned char	*t2;

	if (n == 0)
		return (0);
	t1 = (unsigned char *) s1;
	t2 = (unsigned char *) s2;
	while (n-- > 0 && *t1 == *t2)
	{
		if (n == 0 || *t1 == '\0')
			return (0);
		t1++;
		t2++;
	}
	return (*t1 - *t2);
}
