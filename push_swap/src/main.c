/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euihlee <euihlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 13:45:07 by euihlee           #+#    #+#             */
/*   Updated: 2023/02/12 13:54:51 by euihlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_dllist	a;
	t_dllist	b;
	int			pushed;
	int			size;
	int			ops;

	if (argc < 2)
		return (NO_PARAMS);
	dllist_init_static(&a);
	pushed = 0;
	size = 0;
	while (*++argv)
	{
		pushed = push_args(&a, *argv);
		if (pushed < 0)
		{
			dllist_clear(&a);
			return (INVALID_ARGS);
		}
		size += pushed;
	}
	dllist_init_static(&b);
	ops = push_swap(&a, &b, size);
	dllist_clear(&a);
	return (ops);
}
