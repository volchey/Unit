/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_node.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchechai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 11:41:15 by vchechai          #+#    #+#             */
/*   Updated: 2018/03/21 11:41:18 by vchechai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_way	*new_node(int room)
{
	t_way	*new;

	new = (t_way*)malloc(sizeof(t_way));
	new->room = room;
	new->next = NULL;
	return (new);
}

t_way	*last_node(t_way *way)
{
	t_way	*buf;

	buf = way;
	while (buf->next)
		buf = buf->next;
	return (buf);
}
