/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euihlee <euihlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 13:46:04 by euihlee           #+#    #+#             */
/*   Updated: 2023/02/12 15:06:00 by euihlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push_swap(t_dllist *a, t_dllist *b, int size)
{
	(void) a;
	(void) b;
	(void) size;
	return (0);
}

int	push_args(t_dllist *list, char *str)
{
	int			count;
	long		l;
	char		*endptr;
	t_dlnode	*node;

	count = 0;
	while (*str)
	{
		l = ft_strtol(str, &endptr, 10);
		if (endptr == str)
		{
			if (!valid_trail(endptr))
				return (INVALID_ARGS);
			return (count);
		}
		if (!valid_arg(endptr, l) || dllist_search((int) l, list))
			return (INVALID_ARGS);
		node = dlnode_init((int) l);
		if (!node)
			return (MEM_ERROR);
		dllist_push_back(list, node);
		count++;
		str = endptr;
	}
	return (count);
}

t_bool	valid_trail(char *endptr)
{
	while (ft_isspace(*endptr))
		endptr++;
	if (*endptr)
		return (0);
	return (!0);
}

t_bool	valid_arg(char *endptr, long l)
{
	if (*endptr && !ft_isspace(*endptr))
		return (0);
	if (l < INT_MIN || INT_MAX < l)
		return (0);
	return (!0);
}
