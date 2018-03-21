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
	t_list	*buf;
	t_ways	*ways;
	int 	i;

	i = 0;
	setlocale(LC_ALL, "");
	list = read_file();
	rooms = parse_rooms(list);
//	links = parse_links(list, rooms);
//	ways = get_ways(links, rooms);
//	while (ways)
//	{
//		ft_printf("\nway = ");
//		while (ways->way)
//		{
//			ft_printf(" %d ", ways->way->room);
//			ways->way = ways->way->next;
//		}
//		ways = ways->next;
//	}
//	while (list)
//	{
//		buf = list->next;
//		free(list->content);
//		free(list);
//		ft_printf("%s", list->content);
//		list = buf;
//	}
//	free(list);
	system("leaks lem-in");

//	while (rooms[i].status != -1)
//		ft_printf("name: %s, status: %d, x: %d, y: %d\n", rooms[i].name, rooms[i].status, rooms[i].x, rooms[i++].y);
//	i = 0;
//	while (links[i].room1 != -1)
//		ft_printf("room1 %d, room2 %d\n", links[i].room1, links[i++].room2);

}
