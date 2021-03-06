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

#include "lem_in.h"

static void	validate(t_file *file)
{
	int count;

	count = 0;
	while (file)
	{
		if (!ft_strcmp(file->content, "##start")
			|| !ft_strcmp(file->content, "##end"))
			count++;
		file = file->next;
	}
	if (count != 2)
		ft_exit("multiple ##start or ##end");
}

t_ant		*get_way(t_way *way)
{
	int		size;
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
	ants[0].ant = size;
	ants[0].room = head->room;
	head = head->next;
	size = 1;
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

t_ant		**parse_ways(t_ways *list)
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

void		put_map(t_file *list)
{
	while (list)
	{
		ft_printf("%s\n", list->content);
		list = list->next;
	}
}

int			main(int ac, char **av)
{
	t_room	*rooms;
	t_link	*links;
	t_file	*list;
	t_ways	*ways;
	t_ant	**ants;

	list = read_file();
	validate(list);
	rooms = parse_rooms(list);
	links = parse_links(list, rooms);
	ways = get_ways(links, rooms);
	ways = check_ways(ways, rooms);
	ants = parse_ways(ways);
	put_map(list);
	ft_printf("\n");
	lets_go(ants, ft_atoi(list->content), rooms);
	if (ac > 1 && (!ft_strcmp(av[1], "-w")
		|| (ac > 2 && !ft_strcmp(av[2], "-w"))))
		put_ways(ways, rooms);
	if (ac > 1 && (!ft_strcmp(av[1], "-v")
		|| (ac > 2 && !ft_strcmp(av[2], "-v"))))
		draw_farm(rooms, ants, links);
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
