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

static int		*get_room_links(t_link *links, int room, t_room *rooms)
{
	int			*room_links;
	int			i;
	int			count;

	i = -1;
	count = 0;
	while (links[++i].room2 != -1)
		if ((links[i].room2 == room && rooms[links[i].room1].status != 'm')
			|| (links[i].room1 == room && rooms[links[i].room2].status != 'm'))
			count++;
	room_links = (int*)malloc(sizeof(int) * (count + 1));
	i = -1;
	count = 0;
	while (links[++i].room1 != -1)
	{
		if (links[i].room2 == room && rooms[links[i].room1].status != 'm')
			room_links[count++] = links[i].room1;
		else if (links[i].room1 == room && rooms[links[i].room2].status != 'm')
			room_links[count++] = links[i].room2;
	}
	room_links[count] = -1;
	return (room_links);
}

static void		copy_and_add(t_ways *list, int room)
{
	t_way		*buf;
    t_way		*way;
	t_ways		*new;

	way = list->way;
	new = (t_ways*)malloc(sizeof(t_ways));
	new->way = new_node(way->room);
	new->next = NULL;
	way = way->next;
	buf = new->way;
	while (way)
	{
		buf->next = new_node(way->room);
		buf = buf->next;
		way = way->next;
	}
	buf->next = new_node(room);
	while (list->next)
		list = list->next;
	list->next = new;
}

t_ways	*del_way(t_ways *way, t_ways *list, t_ways **head)
{
	t_way	*buf;

	if (list->way == way->way)
	{
		list->next = way->next;
		*head = list->next;
	}
	else
	{
		while (list->next && list->next->way != way->way)
			list = list->next;
		list->next = way->next;
	}
	while (way->way)
	{
		buf = way->way->next;
		free(way->way);
		way->way = buf;
	}
	free(way);
	return (list->next);
}

static t_ways		*set_room(t_room **rooms, t_link *links, t_ways *list)
{
	int 	*room_links;
    int     i;
	t_way	*way;
	t_ways	*buf;

	buf = list;
    while (list)
    {
        way = last_node(list->way);
		if ((*rooms)[way->room].status != 'e')
		{
			room_links = get_room_links(links, way->room, *rooms);
			if ((*rooms)[way->room].status != 'm')
				(*rooms)[way->room].status = 'm';
			i = -1;
			while (room_links[++i] != -1)
				copy_and_add(list, room_links[i]);
			list = del_way(list, buf, &buf);
			free(room_links);
		}
		else
			list = list->next;
	}
	return (buf);
}

t_ways			*get_ways(t_link *links, t_room *rooms)
{
	t_ways	*ways;
	int		room;

	room = 0;
	while (rooms[room].status != 's')
		room++;
	ways = (t_ways*)malloc(sizeof(t_ways));
	ways->way = new_node(room);
	ways->next = NULL;
	return (set_room(&rooms, links, ways));
}
