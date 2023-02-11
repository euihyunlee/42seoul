/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dllist.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euihlee <euihlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 13:33:11 by euihlee           #+#    #+#             */
/*   Updated: 2023/02/11 22:02:05 by euihlee          ###   ########.fr       */
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

void	dllist_clear(t_dllist *list)
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
	list->head = NULL;
	list->tail = NULL;
}

void	dllist_free(t_dllist *list)
{
	dllist_clear(list);
	free(list);
}
