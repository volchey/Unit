/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_ways.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchechai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 21:11:03 by vchechai          #+#    #+#             */
/*   Updated: 2018/03/29 21:11:05 by vchechai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	put_ways(t_ways *ways, t_room *rooms)
{
	t_way	*way;

	for (int i = 0; ways; i++)
	{
		ft_printf("\n [%d] way = ", i);
		way = ways->way;
		while (way)
		{
			ft_printf(" %s ->", rooms[way->room].name);
			way = way->next;
		}
		ways = ways->next;
	}
}
