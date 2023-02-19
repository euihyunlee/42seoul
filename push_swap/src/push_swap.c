/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euihlee <euihlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 13:46:04 by euihlee           #+#    #+#             */
/*   Updated: 2023/02/19 09:45:32 by euihlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_dllist *a, t_dllist *b, int size, t_bool rev)
{
	t_bool	order;
	int		left;
	int		right;

	if (size < 2)
		return ;
	if (size == 2)
	{
		order = a->head->n < a->head->next->n;
		if ((rev && order) || (!rev && !order))
			swap(a);
		return ;
	}
	left = size / 2;
	right = size - left;
	push_swap(a, b, left, rev);
	rotate(a, left);
	push_swap(a, b, right, rev);
	push(a, b, right);
	while (left && right)
	{
		order = b->head->n > a->tail->n;
		if ((rev && order) || (!rev && !order))
		{
			reverse_rotate(a, 1);
			left--;
		}
		else
		{
			right--;
			push(b, a, 1);
		}
	}
	if (right)
	{
		push(b, a, right);
		return ;
	}
	while (left-- > 0)
		reverse_rotate(a, 1);
}
