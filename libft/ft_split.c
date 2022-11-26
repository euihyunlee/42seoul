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

static void	free_arr(char **arr, unsigned int count);

char	**ft_split(char const *s, char c)
{
	char				**arr;
	static unsigned int	count;
	size_t				len;
	char				*substr;

	while (*s && *s == c)
		s++;
	len = 0;
	while (s[len] && s[len] != c)
		len++;
	if (len == 0)
		return (ft_calloc(count + 1, sizeof(*arr)));
	count++;
	arr = ft_split(s + len, c);
	if (arr == NULL)
		return (NULL);
	substr = ft_substr(s, 0, len);
	if (substr == NULL)
	{
		free_arr(arr, count);
		return (NULL);
	}
	arr[--count] = substr;
	return (arr);
}

static void	free_arr(char **arr, unsigned int count)
{
	if (arr == NULL)
		return ;
	arr += count;
	while (*arr)
		free(*arr++);
	free(arr);
}
