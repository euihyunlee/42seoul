/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euihlee <euihlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 23:47:09 by euihlee           #+#    #+#             */
/*   Updated: 2022/11/23 23:55:42 by euihlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char		ch;
	const char	*t;

	ch = (char) c;
	if (ch == '\0')
		return ((char *) s + ft_strlen(s));
	t = NULL;
	while (*s)
	{
		if (*s == ch)
			t = s;
		s++;
	}
	return ((char *) t);
}
