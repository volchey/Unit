/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchechai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 09:27:00 by vchechai          #+#    #+#             */
/*   Updated: 2017/11/07 09:35:56 by vchechai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*buf;
	t_list	*move;

	if (*alst && del)
	{
		buf = *alst;
		while (buf)
		{
			del(buf->content, buf->content_size);
			move = buf->next;
			free(buf);
			buf = move;
		}
		*alst = 0;
	}
}
