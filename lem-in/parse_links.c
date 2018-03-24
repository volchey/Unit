/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_links.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchechai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/10 18:18:09 by vchechai          #+#    #+#             */
/*   Updated: 2018/03/10 18:18:11 by vchechai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

#include "lem-in.h"

t_link		set_link(char *str, t_room *rooms)
{
	t_link	link;
	char	**arr;
	char	*buf;
	int 	i;

	i = 0;
	buf = ft_strtrim(str);
	arr = ft_strsplit(buf, '-');
	ft_strdel(&buf);
	while (rooms[i].status != '0' && ft_strcmp(rooms[i].name, arr[0]))
		i++;
	if (rooms[i].status == '0')
		ft_exit();
	else
		link.room1 = i;
	i = 0;
	while (rooms[i].status != '0' && ft_strcmp(rooms[i].name, arr[1]))
		i++;
	if (rooms[i].status == '0')
		ft_exit();
	else
		link.room2 = i;
	arr_del(arr);
	return (link);
}

static int 	validate(char *str, t_room *rooms)
{
	int		i;
	char 	*buf;
	char	**arr;

	i = 0;
	buf = ft_strtrim(str);
	arr = ft_strsplit(buf, '-');
	ft_strdel(&buf);
	if (ft_arrlen(arr) != 2)
	{
		arr_del(arr);
		return (0);
	}
	while (rooms[i].status != '0' && !ft_strcmp(arr[0], rooms[i].name))
		i++;
	if (rooms[i].status == '0')
		ft_exit();
	i = 0;
	while (rooms[i].status != '0' && !ft_strcmp(arr[1], rooms[i].name))
		i++;
	if (rooms[i].status == '0')
		ft_exit();
	arr_del(arr);
	return (1);
}

static int 	count_links(t_list	*list, t_room *rooms)
{
	char	*str;
	int		count;

	count = 0;
	while (list)
	{
		str = (char*)list->content;
		if (str[0] != '#')
		{
			if (validate(str, rooms))
				count++;
		}
		list = list->next;
	}
	return (count);
}

t_link	*parse_links(t_list *list, t_room *rooms)
{
	t_link	*links;
	char	*str;
	int 	size;
	int 	i;

	i = 0;
	list = list->next;
	size = count_links(list, rooms);
	links = (t_link*)malloc(sizeof(t_link) * (size + 1));
	while (list)
	{
		str = (char*)list->content;
		if (str[0] != '#')
			if (validate(str, rooms))
				links[i++] = set_link(str, rooms);
		list = list->next;
	}
	links[i].room1 = -1;
	links[i].room2 = -1;
	return (links);
}
