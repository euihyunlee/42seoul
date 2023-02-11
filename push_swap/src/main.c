/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euihlee <euihlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 13:45:07 by euihlee           #+#    #+#             */
/*   Updated: 2023/02/11 22:14:43 by euihlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_dllist	a;
	t_dllist	b;
	int			ops;

	if (argc < 2)
		return (NO_PARAMS);
	dllist_clear(&a);
	while (*++argv)
	{
		if (push_args(&a, *argv))
		{
			dllist_clear(&a);
			return (INVALID_ARGS);
		}
	}
	dllist_clear(&b);
	ops = push_swap(&a, &b);
	dllist_clear(&a);
	dllist_clear(&b);
	return (ops);
}
