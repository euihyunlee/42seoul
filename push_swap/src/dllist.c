/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dllist.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euihlee <euihlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 13:33:11 by euihlee           #+#    #+#             */
/*   Updated: 2023/02/06 13:55:04 by euihlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dllist.h"

t_dllist	*dllist_init(void)
{
	t_dllist	*list;

	list = malloc(sizeof(*list));
	if (!list)
		return (NULL);
	list->head = malloc(sizeof(*list->head));
	if (!list->head)
	{
		free(list);
		return (NULL);
	}
	list->tail = malloc(sizeof(*list->tail));
	if (!list->tail)
	{
		free(list->head);
		free(list);
		return (NULL);
	}
	list->head->prev = NULL;
	list->head->next = list->tail;
	list->tail->prev = list->head;
	list->tail->next = NULL;
	return (list);
}

void	dllist_free(t_dllist *list)
{
	t_dlnode	*trav;
	t_dlnode	*tmp;

	if (!list)
		return ;
	trav = list->head;
	while (trav)
	{
		tmp = trav->next;
		free(trav);
		trav = tmp;
	}
	free(list);
}
