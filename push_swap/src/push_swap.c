/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euihlee <euihlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 13:46:04 by euihlee           #+#    #+#             */
/*   Updated: 2023/02/11 21:42:42 by euihlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push_swap(t_dllist *a, t_dllist *b)
{
	(void) a;
	(void) b;
	return (0);
}

int	push_args(t_dllist *list, char *str)
{
	long		l;
	char		*endptr;
	t_dlnode	*node;

	while (*str)
	{
		l = ft_strtol(str, &endptr, 10);
		if (endptr == str)
		{
			while (ft_isspace(*endptr))
				endptr++;
			if (*endptr)
				return (INVALID_ARGS);
			return (0);
		}
		if ((*endptr && !ft_isspace(*endptr))
			|| l < INT_MIN || INT_MAX < l || dllist_lookup((int) l, list))
			return (INVALID_ARGS);
		node = dlnode_init((int) l);
		if (!node)
			return (MEM_ERROR);
		dllist_insert_back(list, node);
		str = endptr;
	}
	return (0);
}
