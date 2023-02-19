/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euihlee <euihlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 22:23:39 by euihlee           #+#    #+#             */
/*   Updated: 2023/02/19 03:57:36 by euihlee          ###   ########.fr       */
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
	ft_printf("swap\n");
	return (1);
}

int	push(t_dllist *a, t_dllist *b, int count)
{
	int			i;
	t_dlnode	*node;

	i = 0;
	while (i < count)
	{
		node = dllist_pop(a);
		if (!node)
			break ;
		dllist_push_front(b, node);
		ft_printf("push\n");
		i++;
	}
	return (i);
}

int	rotate(t_dllist *list, int count)
{
	int			i;
	t_dlnode	*node;

	i = 0;
	while (i < count)
	{
		node = dllist_pop(list);
		if (!node)
			break ;
		dllist_push_back(list, node);
		ft_printf("rotate\n");
		i++;
	}
	return (i);
}

int	reverse_rotate(t_dllist *list, int count)
{
	int			i;
	t_dlnode	*node;

	i = 0;
	while (i < count)
	{
		node = dllist_eject(list);
		if (!node)
			break ;
		dllist_push_front(list, node);
		ft_printf("reverse rotate\n");
		i++;
	}
	return (i);
}
