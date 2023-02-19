/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euihlee <euihlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 13:45:07 by euihlee           #+#    #+#             */
/*   Updated: 2023/02/19 10:03:32 by euihlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include <stdio.h>

void print_list(t_dllist *list)
{
	t_dlnode	*trav;

	trav = list->head;
	while (trav)
	{
		printf("%d\n", trav->n);
		trav = trav->next;
	}
}

int	main(int argc, char **argv)
{
	t_dllist	a;
	t_dllist	b;
	int			pushed;
	int			size;

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
	push_swap(&a, &b, size);
	print_list(&a);
	print_list(&b);
	dllist_clear(&a);
	return (0);
}
