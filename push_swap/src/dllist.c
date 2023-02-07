/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dllist.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euihlee <euihlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 13:33:11 by euihlee           #+#    #+#             */
/*   Updated: 2023/02/07 15:48:41 by euihlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dllist.h"

t_dllist	*dllist_init(void)
{
	t_dllist	*list;

	list = malloc(sizeof(*list));
	if (!list)
		return (NULL);
	list->head = NULL;
	list->tail = NULL;
	return (list);
}

t_dlnode	*dlnode_init(int n)
{
	t_dlnode	*node;

	node = malloc(sizeof(*node));
	if (!node)
		return (NULL);
	node->n = n;
	node->prev = NULL;
	node->next = NULL;
	return (node);
}

void	dllist_free(t_dllist *list)
{
	t_dlnode	*trav;
	t_dlnode	*tmp;

	trav = list->head;
	while (trav)
	{
		tmp = trav->next;
		free(trav);
		trav = tmp;
	}
	free(list);
}

void	dllist_insert_front(t_dllist *list, t_dlnode *new)
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

void	dllist_insert_back(t_dllist *list, t_dlnode *new)
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
