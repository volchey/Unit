/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_rooms.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchechai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/10 18:17:12 by vchechai          #+#    #+#             */
/*   Updated: 2018/03/10 18:17:14 by vchechai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			is_unique(char **arr, t_room *rooms, t_link *links, int size)
{
	int		i;
	char	*room1;
	char	*room2;

	i = 0;
	while (i < size)
	{
		room1 = rooms[links[i].room1].name;
		room2 = rooms[links[i].room2].name;
		if (!(ft_strcmp(room1, arr[0])) && !(ft_strcmp(room2, arr[1])))
			return (0);
		if (!(ft_strcmp(room2, arr[0])) && !(ft_strcmp(room1, arr[1])))
			return (0);
		i++;
	}
	return (1);
}

t_link		set_link(char *str, t_room *rooms)
{
	t_link	link;
	char	**arr;
	int		i;

	i = 0;
	arr = ft_strsplit(str, '-');
	while (rooms[i].status != '0' && ft_strcmp(rooms[i].name, arr[0]))
		i++;
	if (rooms[i].status == '0')
		ft_exit("no room with the same name");
	else
		link.room1 = i;
	i = 0;
	while (rooms[i].status != '0' && ft_strcmp(rooms[i].name, arr[1]))
		i++;
	if (rooms[i].status == '0')
		ft_exit("no room with the same name");
	else
		link.room2 = i;
	arr_del(arr);
	return (link);
}

static int	validate(char *str, t_room *rooms, t_link *links, int size)
{
	int		i;
	char	**arr;

	i = 0;
	arr = ft_strsplit(str, '-');
	if (ft_arrlen(arr) != 2)
	{
		arr_del(arr);
		return (0);
	}
	while (rooms[i].status != '0' && !ft_strcmp(arr[0], rooms[i].name))
		i++;
	if (rooms[i].status == '0')
		ft_exit("no room with the same name");
	i = 0;
	while (rooms[i].status != '0' && !ft_strcmp(arr[1], rooms[i].name))
		i++;
	if (rooms[i].status == '0')
		ft_exit("no room with the same name");
	if (!(ft_strcmp(arr[0], arr[1])))
		ft_exit("pipe to itself");
//	if (size && !is_unique(arr, rooms, links, size))
//		ft_exit("not unique link");
	arr_del(arr);
	return (1);
}

static int	count_links(t_file *list, t_room *rooms)
{
	char	*str;
	int		count;

	count = 0;
	while (list)
	{
		str = list->content;
		if (str[0] != '#')
		{
			if (validate(str, rooms, 0, 0))
				count++;
		}
		list = list->next;
	}
	return (count);
}

t_link		*parse_links(t_file *list, t_room *rooms)
{
	t_link	*links;
	char	*str;
	int		size;
	int		i;

	i = 0;
	list = list->next;
	if (!(size = count_links(list, rooms)))
		ft_exit("no links");
	links = (t_link*)malloc(sizeof(t_link) * (size + 1));
	while (list)
	{
		str = list->content;
		if (str[0] != '#')
			if (validate(str, rooms, links, i))
				links[i++] = set_link(str, rooms);
		list = list->next;
	}
	links[i].room1 = -1;
	links[i].room2 = -1;
	return (links);
}
