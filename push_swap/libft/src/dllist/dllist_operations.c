/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dllist_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euihlee <euihlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 15:02:01 by euihlee           #+#    #+#             */
/*   Updated: 2023/02/12 15:07:08 by euihlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dllist.h"

t_dlnode	*dllist_eject(t_dllist *list)
{
	t_dlnode	*node;

	node = list->tail;
	if (!node)
		return (NULL);
	if (!node->prev)
	{
		dllist_init_static(list);
		return (node);
	}
	list->tail = node->prev;
	list->tail->next = NULL;
	node->prev = NULL;
	return (node);
}

t_dlnode	*dllist_pop(t_dllist *list)
{
	t_dlnode	*node;

	node = list->head;
	if (!node)
		return (NULL);
	if (!node->next)
	{
		dllist_init_static(list);
		return (node);
	}
	list->head = node->next;
	list->head->prev = NULL;
	node->next = NULL;
	return (node);
}

void	dllist_push_back(t_dllist *list, t_dlnode *new)
{
	if (!list->tail)
	{
		new->prev = NULL;
		new->next = NULL;
		list->head = new;
		list->tail = new;
		return ;
	}
	list->tail->next = new;
	new->prev = list->tail;
	new->next = NULL;
	list->tail = new;
}

void	dllist_push_front(t_dllist *list, t_dlnode *new)
{
	t_dlnode	*tmp;

	if (!list->head)
	{
		new->prev = NULL;
		new->next = NULL;
		list->head = new;
		list->tail = new;
		return ;
	}
	tmp = list->head;
	list->head = new;
	new->prev = NULL;
	new->next = tmp;
	tmp->prev = new;
}

int	dllist_search(int n, t_dllist *list)
{
	t_dlnode	*trav;

	trav = list->head;
	while (trav)
	{
		if (trav->n == n)
			return (1);
		trav = trav->next;
	}
	return (0);
}
