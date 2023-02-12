/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dllist.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euihlee <euihlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 13:33:11 by euihlee           #+#    #+#             */
/*   Updated: 2023/02/12 15:12:02 by euihlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dllist.h"

void	dllist_init_static(t_dllist *list)
{
	list->head = NULL;
	list->tail = NULL;
}

t_dllist	*dllist_init_dynamic(void)
{
	t_dllist	*list;

	list = malloc(sizeof(*list));
	if (!list)
		return (NULL);
	dllist_init_static(list);
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
	dllist_init_static(list);
}

void	dllist_free(t_dllist *list)
{
	dllist_clear(list);
	free(list);
}
