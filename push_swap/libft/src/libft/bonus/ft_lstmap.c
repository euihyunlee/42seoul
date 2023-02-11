/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euihlee <euihlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 17:30:30 by euihlee           #+#    #+#             */
/*   Updated: 2022/11/26 19:31:03 by euihlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*flst;
	void	*fcontent;
	t_list	*new;

	flst = NULL;
	while (lst)
	{
		fcontent = f(lst->content);
		new = ft_lstnew(fcontent);
		if (new == NULL)
		{
			del(fcontent);
			ft_lstclear(&flst, del);
			return (NULL);
		}
		ft_lstadd_back(&flst, new);
		lst = lst->next;
	}
	return (flst);
}
