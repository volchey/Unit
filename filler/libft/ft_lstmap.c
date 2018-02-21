/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchechai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 10:18:07 by vchechai          #+#    #+#             */
/*   Updated: 2017/11/07 15:48:07 by vchechai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;
	t_list	*ptr;
	t_list	*buf;

	if (!lst && !f)
		return (0);
	if (!(ptr = (t_list*)malloc(sizeof(t_list))))
		return (0);
	ptr = f(lst);
	new = ft_lstnew(ptr->content, ptr->content_size);
	buf = new;
	lst = lst->next;
	while (lst)
	{
		if (!(ptr = (t_list*)malloc(sizeof(t_list))))
			return (0);
		ptr = f(lst);
		new->next = ft_lstnew(ptr->content, ptr->content_size);
		new = new->next;
		lst = lst->next;
	}
	new->next = NULL;
	return (buf);
}
