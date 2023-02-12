/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euihlee <euihlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 22:23:39 by euihlee           #+#    #+#             */
/*   Updated: 2023/02/12 15:11:42 by euihlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	swap(t_dllist *list)
{
	t_dlnode	*first;
	t_dlnode	*second;
	int			tmp;

	first = list->head;
	if (!first)
		return (0);
	second = first->next;
	if (!second)
		return (0);
	tmp = first->n;
	first->n = second->n;
	second->n = tmp;
	return (1);
}

int	push(t_dllist *a, t_dllist *b)
{
	t_dlnode	*node;

	node = dllist_pop(b);
	if (!node)
		return (0);
	dllist_push_front(a, node);
	return (1);
}

int	rotate(t_dllist *list)
{
	t_dlnode	*node;

	node = dllist_pop(list);
	if (!node)
		return (0);
	dllist_push_back(list, node);
	return (1);
}

int	reverse_rotate(t_dllist *list)
{
	t_dlnode	*node;

	node = dllist_eject(list);
	if (!node)
		return (0);
	dllist_push_front(list, node);
	return (1);
}
