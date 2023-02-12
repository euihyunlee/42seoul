/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dllist.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euihlee <euihlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 13:19:34 by euihlee           #+#    #+#             */
/*   Updated: 2023/02/12 15:05:15 by euihlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DLLIST_H
# define DLLIST_H

# include <stdlib.h>

typedef struct s_dlnode
{
	int				n;
	struct s_dlnode	*prev;
	struct s_dlnode	*next;
}					t_dlnode;

typedef struct s_dllist
{
	t_dlnode	*head;
	t_dlnode	*tail;
}				t_dllist;

void		dllist_init_static(t_dllist *list);
t_dllist	*dllist_init_dynamic(void);
t_dlnode	*dlnode_init(int n);
void		dllist_clear(t_dllist *list);
void		dllist_free(t_dllist *list);

t_dlnode	*dllist_eject(t_dllist *list);
t_dlnode	*dllist_pop(t_dllist *list);
void		dllist_push_back(t_dllist *list, t_dlnode *new);
void		dllist_push_front(t_dllist *list, t_dlnode *new);
int			dllist_search(int n, t_dllist *list);

#endif
