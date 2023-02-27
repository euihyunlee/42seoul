/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euihlee <euihlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 13:46:04 by euihlee           #+#    #+#             */
/*   Updated: 2023/02/28 06:03:28 by euihlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	bubble(t_dllist *b, int size)
{
	t_dlnode	*ltr;
	t_dlnode	*rtl;
	int			i;

	ltr = b->head;
	rtl = b->tail;
	i = 0;
	while (TRUE)
	{
		if (ltr->n == size)
		{
			rotate(RB, b, i);
			return ;
		}
		if (rtl->n == size)
		{
			reverse_rotate(RRB, b, i + 1);
			return ;
		}
		ltr = ltr->next;
		rtl = rtl->prev;
		i++;
	}
}

static void	index(t_dllist *list, int size)
{
	// TODO: convert integers in list to ordinal numbers
	(void) list;
	(void) size;
}

void	push_swap_small(t_dllist *a, t_dllist *b, int size)
{
	(void) a;
	(void) b;
	(void) size;
}

void	push_swap(t_dllist *a, t_dllist *b, int size)
{
	int	pivot;
	int	i;

	index(a, size);
	pivot = (int)(0.0269524 * size + 14.6418);
	i = 0;
	while (i < size)
	{
		if (a->head->n < i + pivot)
		{
			push(PB, a, b, 1);
			if (i < b->head->n)
				rotate(RB, b, 1);
			i++;
		}
		else if (i < size / 2)
			reverse_rotate(RRA, a, 1);
		else
			rotate(RA, a, 1);
	}
	while (size-- > 0)
	{
		bubble(b, size);
		push(PA, b, a, 1);
	}
}
