/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchechai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 16:36:03 by vchechai          #+#    #+#             */
/*   Updated: 2017/12/05 19:59:22 by vchechai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_new_line(int fd, char **str, char **line)
{
	int		ret;
	char	*c;
	char	arr[BUFF_SIZE + 1];

	*line = ft_strnew(0);
	c = 0;
	while ((ret = read(fd, arr, BUFF_SIZE)))
	{
		arr[ret] = '\0';
		if ((c = ft_strchr(arr, '\n')))
		{
			*line = ft_strjoin(*line, ft_strsub(arr, 0, (c - arr)));
			*str = ft_strdup(c + 1);
			return (ret);
		}
		*line = ft_strjoin(*line, arr);
	}
	return (ret);
}

int		check_content(int fd, char **str, char **line)
{
	char	*c;
	int		x;

	c = ft_strchr(*str, '\n');
	if (c)
	{
		*line = ft_strsub(*str, 0, (c - *str));
		*str = ft_strsub(*str, (c - *str) + 1, BUFF_SIZE);
	}
	else
	{
		c = *str;
		x = get_new_line(fd, str, line);
		if (x == 0 || x == -1)
			return (x);
		*line = ft_strjoin(c, *line);
	}
	return (1);
}

int					get_next_line(const int fd, char **line)
{
	static t_list	*buf;
	t_list			*list;
	int				x;

	list = buf;
	while (list && (int)list->content_size != fd)
		list = list->next;
	if (!list)
	{
		list = ft_lstnew(0, fd);
		ft_lstadd(&buf, list);
	}
	if (!list->content_size)
		list->content_size = fd;
	if (list->content == 0)
		x = get_new_line(list->content_size, (char**)&list->content, line);
	else
		x = check_content(list->content_size, (char**)&list->content, line);
	if (x == 0)
		return (0);
	if (x == -1)
		return (-1);
	return (1);
}
