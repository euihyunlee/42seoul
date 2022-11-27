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
	void	*fresult;
	t_list	*flst;
	t_list	*new;

	flst = NULL;
	while (lst)
	{
		fresult = f(lst->content);
		new = ft_lstnew(fresult);
		if (new == NULL)
		{
			del(fresult);
			ft_lstclear(&flst, del);
			return (NULL);
		}
		ft_lstadd_back(&flst, new);
		lst = lst->next;
	}
	return (flst);
}
