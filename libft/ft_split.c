/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euihlee <euihlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 12:07:33 by euihlee           #+#    #+#             */
/*   Updated: 2022/11/26 12:50:09 by euihlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	free_arr(char **arr, size_t start);

char	**ft_split(char const *s, char c)
{
	static size_t	count;
	char const		*t;
	char			*substr;
	char			**arr;

	while (*s && *s == c)
		s++;
	t = s;
	while (*t && *t != c)
		t++;
	if (s == t)
		return (ft_calloc(count + 1, sizeof(*arr)));
	count++;
	arr = ft_split(t, c);
	if (arr == NULL)
		return (NULL);
	substr = ft_substr(s, 0, t - s);
	if (substr == NULL)
	{
		free_arr(arr, count);
		return (NULL);
	}
	arr[--count] = substr;
	return (arr);
}

static void	free_arr(char **arr, size_t start)
{
	char	**tmp;

	tmp = arr + start;
	while (*tmp)
		free(*tmp++);
	free(arr);
}
