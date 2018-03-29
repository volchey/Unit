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

static int		is_unique(char **arr, t_room *rooms, int size)
{
	int x;
	int y;

	x = ft_atoi(arr[1]);
	y = ft_atoi(arr[2]);
	while (size - 1)
	{
		if (ft_strcmp(arr[0], rooms[size - 1].name) == 0
	|| (x == rooms[size - 1].x
	&& y == rooms[size - 1].y))
			return (0);
		size--;
	}
	return (1);
}

static int		validate(char *str, t_room *rooms, int size)
{
	int		i;
	char	**arr;

	arr = ft_strsplit(str, ' ');
	if (ft_arrlen(arr) != 3)
	{
		arr_del(arr);
		return (0);
	}
	if (arr[0][0] == 'L')
		ft_exit("room with L");
	i = 0;
	while (arr[1][i])
		if (!(ft_isdigit(arr[1][i++])))
			ft_exit("coordinate x is not valid");
	i = 0;
	while (arr[2][i])
		if (!(ft_isdigit(arr[2][i++])))
			ft_exit("coord y is not valid");
	if (size && !is_unique(arr, rooms, size))
		ft_exit("not unique name of room");
	arr_del(arr);
	return (1);
}

static int		count_rooms(t_file *list)
{
	char	*str;
	int		count;

	count = 0;
	while (list)
	{
		str = list->content;
		if (str[0] != '#')
		{
			if (validate(str, 0, 0))
				count++;
		}
		list = list->next;
	}
	return (count);
}

static void		check_command(char *str, t_file **list, t_room **rooms, int *i)
{
	char	*buf;

	*list = (*list)->next;
	buf = (*list)->content;
	if ((ft_strcmp(str, "##start")) == 0)
	{
		if (validate(buf, *rooms, *i))
			(*rooms)[(*i)++] = set_room(buf, 's');
		else
			ft_exit("not valid room after start");
	}
	else if ((ft_strcmp(str, "##end")) == 0)
	{
		if (validate(buf, *rooms, *i))
			(*rooms)[(*i)++] = set_room(buf, 'e');
		else
			ft_exit("not valid room after end");
	}
	else if (str[2] == '#')
		ft_exit("not valid comment");
	else if (validate(buf, *rooms, *i))
		(*rooms)[(*i)++] = set_room(buf, 'd');
}

t_room			*parse_rooms(t_file *list)
{
	t_room	*rooms;
	char	*str;
	int		size;
	int		i;

	list = list->next;
	i = 0;
	size = count_rooms(list);
	rooms = (t_room*)malloc(sizeof(t_room) * (size + 1));
	while (list)
	{
		str = list->content;
		if (str[0] != '#')
		{
			if (validate(str, rooms, i))
				rooms[i++] = set_room(str, 'd');
		}
		else if (list->next)
			check_command(str, &list, &rooms, &i);
		list = list->next;
	}
	rooms[i] = set_room("0 0 0", '0');
	return (rooms);
}
