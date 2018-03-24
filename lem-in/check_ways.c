/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_ways.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchechai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/24 14:45:23 by vchechai          #+#    #+#             */
/*   Updated: 2018/03/24 14:45:25 by vchechai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

static int	is_unique(t_ways *way, t_ways *list, t_room *rooms)
{
	t_way	*current;
	t_way	*buf;

	while (list && list != way)
	{
		current = list->way->next;
		while (current)
		{
			buf = way->way->next;
			while (buf)
			{
				if (buf->room == current->room && rooms[buf->room].status != 'e')
					return (0);
				buf = buf->next;
			}
			current = current->next;
		}
		list = list->next;
	}
	return (1);
}

t_ways		*check_ways(t_ways *list, t_room *rooms)
{
	t_ways	*head;

	head = list;
	while (list)
	{
		if (!is_unique(list, head, rooms))
			list = del_way(list, head, &head);
		else
			list = list->next;
	}
	return (head);
}
