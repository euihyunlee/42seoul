/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euihlee <euihlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 13:45:07 by euihlee           #+#    #+#             */
/*   Updated: 2023/02/28 06:25:48 by euihlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// TODO: remove print_list function
//#include <stdio.h>
//void	print_list(t_dllist *list)
//{
//	t_dlnode	*trav;
//
//	trav = list->head;
//	while (trav)
//	{
//		printf("%d\n", trav->n);
//		trav = trav->next;
//	}
//}

int	main(int argc, char **argv)
{
	t_dllist	a;
	t_dllist	b;
	int			pushed;
	int			size;

	if (argc < 2)
		return (EXIT_FAILURE);
	dllist_init_static(&a);
	size = 0;
	while (*++argv)
	{
		pushed = push_args(&a, *argv);
		if (pushed < 0)
		{
			dllist_clear(&a);
			return (EXIT_FAILURE);
		}
		size += pushed;
	}
	dllist_init_static(&b);
	// TODO: hard code for sizes less than 5
//	if (size <= 5)
//		push_swap_small(&a, &b, size);
//	else
	push_swap(&a, &b, size);
	dllist_clear(&a);
}
