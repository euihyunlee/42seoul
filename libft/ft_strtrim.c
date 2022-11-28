/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euihlee <euihlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 18:11:57 by euihlee           #+#    #+#             */
/*   Updated: 2022/11/24 18:51:07 by euihlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*s2;
	size_t	len;
	char	*trimmed;

	while (*s1 && ft_strchr(set, *s1))
		s1++;
	s2 = (char *) s1 + ft_strlen(s1);
	while (s2 >= s1 && ft_strchr(set, *s2))
		s2--;
	len = s2 - s1 + 1;
	trimmed = malloc(len + 1);
	if (trimmed == NULL)
		return (NULL);
	trimmed[len] = '\0';
	if (len == 0)
		return (trimmed);
	while (len-- > 0)
		trimmed[len] = s1[len];
	return (trimmed);
}
