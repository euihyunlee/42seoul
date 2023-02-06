/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euihlee <euihlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 13:45:07 by euihlee           #+#    #+#             */
/*   Updated: 2023/02/06 13:45:09 by euihlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_dllist	*a;
	t_dllist	*b;
	int			ops;

	if (argc < 2)
		exit(NO_PARAMS);
	a = dllist_init();
	if (!a)
		return (MEM_ERROR);
	b = dllist_init();
	if (!b)
	{
		dllist_free(a);
		return (MEM_ERROR);
	}
	ops = push_swap(a, b);
	dllist_free(a);
	dllist_free(b);
	return (ops);
}

