/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchechai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 11:47:11 by vchechai          #+#    #+#             */
/*   Updated: 2018/02/15 11:47:19 by vchechai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <locale.h>
#include "lem-in.h"

int	main(void)
{
	t_room	*rooms;
	t_link	*links;
	t_list	*list;
	t_ways	*buf;
	t_way	*way;
	t_ways	*ways;
	int 	i;

	i = -1;
	setlocale(LC_ALL, "");
	list = read_file();
	rooms = parse_rooms(list);
	links = parse_links(list, rooms);
	ways = get_ways(links, rooms);
	ways = check_ways(ways, rooms);
	buf = ways;
	while (ways)
	{
		ft_printf("\nway = ");
		way = ways->way;
		while (way)
		{
			ft_printf(" %d ->", way->room);
			way = way->next;
		}
		ways = ways->next;
	}
//	while (rooms[++i].status != '0')
//		ft_printf("name: %s, status: %c, x: %d, y: %d\n", rooms[i].name, rooms[i].status, rooms[i].x, rooms[i].y);
//	i = 0;
//	while (links[i].room1 != -1)
//		ft_printf("room1 %d, room2 %d\n", links[i].room1, links[i++].room2);
//	system("leaks lem-in");
}
