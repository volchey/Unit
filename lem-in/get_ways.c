/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_ways.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchechai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 17:56:01 by vchechai          #+#    #+#             */
/*   Updated: 2018/03/13 17:56:04 by vchechai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

static t_way	*new_node(int room)
{
	t_way	*new;

	new = (t_way*)malloc(sizeof(t_way));
	new->room = room;
	new->next = NULL;
	return (new);
}

static int		*get_room_links(t_link *links, int room, t_room *rooms)
{
	int			*room_links;
	int			i;
	int			count;

	i = -1;
	count = 0;
	while (links[++i].room2 != -1)
		if ((links[i].room2 == room && rooms[links[i].room2].status != 3)
			|| (links[i].room1 == room && rooms[links[i].room1].status != 3))
			count++;
	if (count == 0)
		ft_exit();
	room_links = (int*)malloc(sizeof(int) * (count + 1));
	i = -1;
	count = 0;
	while (links[++i].room1 != -1)
	{
		if (links[i].room2 == room && rooms[links[i].room2].status != 3)
			room_links[count++] = links[i].room1;
		else if (links[i].room1 == room && rooms[links[i].room1].status != 3)
			room_links[count++] = links[i].room2;
	}
	room_links[count] = -1;
	return (room_links);
}

static t_way	*check_way(int room, t_ways *ways)
{
	t_way	*buf;

//	ft_printf(" %d ", room);
	while (ways)
	{
		buf = ways->way;
		while (buf)
		{
			if (buf->room == room && !(buf->next))
				return (ways->way);
			buf = buf->next;
		}
		ways = ways->next;
	}
	return (0);
}

static void		copy_and_add(t_way *way, t_ways *ways, int room, t_room *rooms)
{
	t_way		*buf;

	while (ways->next)
		ways = ways->next;
	ways->next = (t_ways*)malloc(sizeof(t_ways));
	ways->next->next = NULL;
	ways->next->way = new_node(way->room);
	ways = ways->next;
	way = way->next;
	buf = ways->way;
	while (way)
	{
		buf->next = new_node(way->room);
		buf = buf->next;
		way = way->next;
	}
	buf->next = new_node(room);
	if (rooms[room].status == 0)
		rooms[room].status = 3;
}

static void		set_room(t_room *rooms, int room, t_link *links, t_ways *ways)
{
	int 	*room_links;
	int		j;
	int 	x;
	t_way	*way;
	t_ways	*buf;
	t_way	*current;

	j = 0;
	x = 0;
	buf = ways;
	ft_printf("\n room number: %d room status: %d\n", room, rooms[room].status);
	room_links = get_room_links(links, room, rooms);
//	for (int i = 0; room_links[i] != -1; i++)
//		ft_printf(" %d ", room_links[i]);
	while (buf)
	{
		current = buf->way;
		ft_printf("\nway = ");
		while (current)
		{
			ft_printf(" %d ", current->room);
			current = current->next;
		}
		buf = buf->next;
	}
	while (room_links[j] != -1)
	{
		if ((way = check_way(room_links[j], ways)))
		{
			copy_and_add(way, ways, room, rooms);
			break ;
		}
		j++;
	}
	while (room_links[x] != -1 && room_links[j] != -1)
	{
		if (rooms[room].status == 0 && x != j)
			set_room(rooms, room_links[x], links, ways);
		x++;
	}
}

t_ways			*get_ways(t_link *links, t_room *rooms)
{
	t_ways	*ways;
	int		room;
	int		*room_links;

	room = 0;
	while (rooms[room].status != 1)
		room++;
	ways = (t_ways*)malloc(sizeof(t_ways));
	ways->way = new_node(room);
	ways->next = NULL;
	room_links = get_room_links(links, room, rooms);
	room = 0;
//	while (room_links[room] != -1)
//	{
		set_room(rooms, room_links[0], links, ways);
//		room++;
//	}
	return (ways);
}
