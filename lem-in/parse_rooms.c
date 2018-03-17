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

static t_room	set_room(char *str, int status)
{
	t_room	room;
	char	**arr;

	room.status = status;
	arr = ft_strsplit(str, ' ');
	room.name = arr[0];
	room.x = ft_atoi(arr[1]);
	room.y = ft_atoi(arr[2]);
	return (room);
}

static int		validate(char *str)
{
	int		i;
	char 	*buf;
	char	**arr;

	i = 0;
	buf = ft_strtrim(str);
	arr = ft_strsplit(buf, ' ');
	if (ft_arrlen(arr) != 3)
		return (0);
	while (arr[1][i])
		if (!ft_isalnum(arr[1][i++]))
			ft_exit();
	i = 0;
	while (arr[2][i])
		if (!ft_isalnum(arr[2][i++]))
			ft_exit();
	return (1);
}

static int		count_rooms(t_list	*list)
{
	char	*str;
	int		count;

	count = 0;
	while (list)
	{
		str = (char*)list->content;
		if (str[0] != '#')
		{
			if (validate(str))
				count++;
		}
		list = list->next;
	}
	return (count);
}

static void		check_command(char *str, t_list **list, t_room **rooms, int *i)
{
	char	*buf;

	*list = (*list)->next;
	buf = (char*)(*list)->content;
	if ((ft_strcmp(str, "##start\n")) == 0)
	{
		if (validate(buf))
			(*rooms)[(*i)++] = set_room(buf, 1);
		else
			ft_exit();
	}
	else if ((ft_strcmp(str, "##end\n")) == 0)
	{
		if (validate(buf))
			(*rooms)[(*i)++] = set_room(buf, 2);
		else
			ft_exit();
	}
	else if (validate(buf))
		(*rooms)[(*i)++] = set_room(buf, 0);
}

t_room			*parse_rooms(t_list *list)
{
	t_room	*rooms;
	char	*str;
	int 	size;
	int 	i;

	list = list->next;
	i = 0;
	size = count_rooms(list);
	rooms = (t_room*)malloc(sizeof(t_room) * size + 1);
	while (list)
	{
		str = (char*)list->content;
		if (str[0] != '#')
		{
			if (validate(str))
				rooms[i++] = set_room(str, 0);
		}
		else
			check_command(str, &list, &rooms, &i);
		list = list->next;
	}
	rooms[i] = set_room("-1 -1 -1", -1);
	return (rooms);
}
