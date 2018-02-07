/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chrjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchechai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 16:36:32 by vchechai          #+#    #+#             */
/*   Updated: 2018/01/15 16:37:03 by vchechai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_chrjoin(t_list **str, char c)
{
	char	*buf;
	t_list	*new;

	if (str)
	{
		if ((*str)->content_size == BUFF_SIZE)
		{
			new = ft_lstnew("", BUFF_SIZE);
			new->content_size = 0;
			(*str)->next = new;
			*str = (*str)->next;
			(*str)->content_size = 0;
		}
		buf = (char*)(*str)->content;
		buf[(*str)->content_size] = c;
		(*str)->content_size += 1;
	}
}
