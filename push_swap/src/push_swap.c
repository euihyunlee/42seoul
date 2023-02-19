/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euihlee <euihlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 13:46:04 by euihlee           #+#    #+#             */
/*   Updated: 2023/02/19 10:03:05 by euihlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_dllist *a, t_dllist *b, int size)
{
	int		left;
	int		right;

	if (size < 2)
		return ;
	// TODO: optmise sorting for pairs and triples
	if (size == 2)
	{
		if (a->head->n > a->head->next->n)
			swap(a);
		return ;
	}
	left = size / 2;
	right = size - left;
	push_swap(a, b, left);
	rotate(a, left);
	// TODO: push swap straight to btop
	push_swap(a, b, right);
	push(a, b, right);
	while (left && right)
	{
		if (b->head->n < a->tail->n)
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
