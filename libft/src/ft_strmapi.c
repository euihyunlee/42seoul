/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euihlee <euihlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 15:31:36 by euihlee           #+#    #+#             */
/*   Updated: 2022/11/26 15:39:33 by euihlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*fs;
	unsigned int	i;

	fs = ft_strdup(s);
	if (fs == NULL)
		return (NULL);
	i = 0;
	while (fs[i])
	{
		fs[i] = f(i, fs[i]);
		i++;
	}
	return (fs);
}
