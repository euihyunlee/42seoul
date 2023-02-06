/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dllist.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euihlee <euihlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 13:19:34 by euihlee           #+#    #+#             */
/*   Updated: 2023/02/06 13:55:13 by euihlee          ###   ########.fr       */
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
void		dllist_free(t_dllist *list);

#endif
