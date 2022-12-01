/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euihlee <euihlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 17:58:41 by euihlee           #+#    #+#             */
/*   Updated: 2022/11/24 18:10:10 by euihlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len;
	char	*joined;

	len = ft_strlen(s1) + ft_strlen(s2);
	joined = malloc(len + 1);
	if (joined == NULL)
		return (NULL);
	joined[len] = '\0';
	while (*s1)
		*joined++ = *s1++;
	while (*s2)
		*joined++ = *s2++;
	return (joined - len);
}
