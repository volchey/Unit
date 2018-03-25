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

t_ant	*get_way(t_way *way)
{
	int 	size;
	t_way	*head;
	t_ant	*ants;

	size = 0;
	head = way;
	while (way)
	{
		size++;
		way = way->next;
	}
	ants = (t_ant*)malloc(sizeof(t_ant) * (size + 1));
	size = 0;
	while (head)
	{
		ants[size].room = head->room;
		ants[size++].ant = 0;
		head = head->next;
	}
	ants[size].ant = -1;
	ants[size].room = -1;
	return (ants);
}

t_ant	**parse_ways(t_ways *list)
{
	t_ant	**ways;
	t_ways	*head;
	int		size;

	size = 0;
	head = list;
	while (list)
	{
		size++;
		list = list->next;
	}
	ways = (t_ant**)malloc(sizeof(t_ant*) * (size + 1));
	size = 0;
	while (head)
	{
		ways[size++] = get_way(head->way);
		head = head->next;
	}
	ways[size] = 0;
	return (ways);
}

int	main(void)
{
	t_room	*rooms;
	t_link	*links;
	t_list	*list;
	t_list	*buf;
	t_ways	*ways;
	t_ant	**ants;

	setlocale(LC_ALL, "");
	list = read_file();
	rooms = parse_rooms(list);
	links = parse_links(list, rooms);
	ways = get_ways(links, rooms);
	ways = check_ways(ways, rooms);
	ants = parse_ways(ways);
	buf = list;
	while (list)
	{
		ft_printf("%s", list->content);
		list = list->next;
	}
	ft_printf("\n");
	lets_go(ants, ft_atoi(buf->content), rooms);
//	buf = ways;
//	while (ways)
//	{
//		ft_printf("\nway = ");
//		way = ways->way;
//		while (way)
//		{
//			ft_printf(" %s ->", rooms[way->room].name);
//			way = way->next;
//		}
//		ways = ways->next;
//	}
//	for (int k = 0; ants[k]; k++)
//	{
//		ft_printf("\nway = ");
//		for (int j = 0; ants[k][j].ant != -1; j++)
//		{
//			ft_printf("room: %d ant: %d ", ants[k][j].room, ants[k][j].ant);
//		}
//	}
//	while (rooms[++i].status != '0')
//		ft_printf("name: %s, status: %c, x: %d, y: %d\n", rooms[i].name, rooms[i].status, rooms[i].x, rooms[i].y);
//	i = 0;
//	while (links[i].room1 != -1)
//		ft_printf("room1 %d, room2 %d\n", links[i].room1, links[i++].room2);
//	system("leaks lem-in");
}
