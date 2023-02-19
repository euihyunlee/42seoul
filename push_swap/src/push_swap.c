/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euihlee <euihlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 13:46:04 by euihlee           #+#    #+#             */
/*   Updated: 2023/02/19 11:06:28 by euihlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	merge(t_dllist *a, t_dllist *b, int left, int right)
{
	while (left && right)
	{
		if (b->head->n < a->tail->n)
		{
			reverse_rotate(a, 1);
			left--;
			continue ;
		}
		push(b, a, 1);
		right--;
	}
	push(b, a, right);
	reverse_rotate(a, left);
}

void	push_swap(t_dllist *a, t_dllist *b, int size)
{
	int		left;
	int		right;

	if (size < 2)
		return ;
	if (size == 2 && (a->head->n > a->head->next->n))
	{
		swap(a);
		return ;
	}
	left = size / 2;
	right = size - left;
	push_swap(a, b, left);
	rotate(a, left);
	push_swap(a, b, right);
	push(a, b, right);
	merge(a, b, left, right);
}
