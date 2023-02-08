/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dllist.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euihlee <euihlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 13:19:34 by euihlee           #+#    #+#             */
/*   Updated: 2023/02/07 15:47:37 by euihlee          ###   ########.fr       */
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

t_dllist	*dllist_init(void);
t_dlnode	*dlnode_init(int n);
void		dllist_free(t_dllist *list);
void		dllist_insert_front(t_dllist *list, t_dlnode *new);
void		dllist_insert_back(t_dllist *list, t_dlnode *new);

#endif
