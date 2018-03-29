/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchechai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/10 19:45:36 by vchechai          #+#    #+#             */
/*   Updated: 2018/03/10 19:45:37 by vchechai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static t_file	*new_element(char *str)
{
	t_file	*new;

	new = (t_file*)malloc(sizeof(t_file));
	new->content = ft_strdup(str);
	new->next = NULL;
	return (new);
}

static int		valid_room(char *str)
{
	int		i;
	char	**arr;

	arr = ft_strsplit(str, ' ');
	if (ft_arrlen(arr) != 3)
	{
		arr_del(arr);
		return (0);
	}
	i = 0;
	while (arr[1][i])
		if (!ft_isdigit(arr[1][i++]))
			ft_exit("not valid room");
	i = 0;
	while (arr[2][i])
		if (!ft_isdigit(arr[2][i++]))
			ft_exit("not valid room");
	arr_del(arr);
	return (1);
}

static int		valid_link(char *str)
{
	char	**arr;

	arr = ft_strsplit(str, '-');
	if (ft_arrlen(arr) != 2)
	{
		arr_del(arr);
		return (0);
	}
	arr_del(arr);
	return (1);
}

static void		check_ants_count(char *line)
{
	int	i;

	i = 0;
	while (line[i] && i < 9)
	{
		if (!(ft_isalnum(line[i])))
			ft_exit("not valid ants count");
		i++;
	}
	if (i == 9)
		ft_exit("too many ants");
	if (!(ft_atoi(line)))
		ft_exit("not valid ants count");
}

t_file			*read_file(void)
{
	t_file	*ptr;
	t_file	*head;
	char	*line;
	char	*buf;

	if (get_next_line(0, &line) <= 0)
		ft_exit("first read error");
	buf = ft_strtrim(line);
	check_ants_count(buf);
	ptr = new_element(buf);
	head = ptr;
	ft_strdel(&line);
	ft_strdel(&buf);
	while (get_next_line(0, &line) > 0)
	{
		buf = ft_strtrim(line);
		if (buf[0] != '#' && !(valid_link(buf)) && !(valid_room(buf)))
			ft_exit("error while read file");
		ptr->next = new_element(buf);
		ptr = ptr->next;
		ft_strdel(&line);
		ft_strdel(&buf);
	}
	ft_strdel(&line);
	return (head);
}
