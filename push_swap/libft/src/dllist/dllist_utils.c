/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dllist_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euihlee <euihlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 15:08:43 by euihlee           #+#    #+#             */
/*   Updated: 2023/02/11 21:52:22 by euihlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dllist.h"

int	dllist_lookup(int n, t_dllist *list)
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
