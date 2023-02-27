/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euihlee <euihlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 17:01:50 by euihlee           #+#    #+#             */
/*   Updated: 2023/02/28 06:22:58 by euihlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_bool	valid_trail(char *endptr)
{
	while (ft_isspace(*endptr))
		endptr++;
	if (*endptr)
		return (FALSE);
	return (TRUE);
}

static t_bool	valid_arg(char *endptr, long l)
{
	if (*endptr && !ft_isspace(*endptr))
		return (FALSE);
	if (l < INT_MIN || INT_MAX < l)
		return (FALSE);
	return (TRUE);
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
