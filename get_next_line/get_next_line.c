/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchechai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 16:36:03 by vchechai          #+#    #+#             */
/*   Updated: 2017/12/07 10:46:37 by vchechai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int				get_new_line(int fd, char **str, char **line)
{
	int			ret;
	char		*c;
	char		*buf;
	char		arr[BUFF_SIZE + 1];

	*line = ft_strnew(0);
	c = 0;
	while ((ret = read(fd, arr, BUFF_SIZE)) && ret != -1)
	{
		arr[ret] = '\0';
		if ((c = ft_strchr(arr, '\n')))
		{
			buf = ft_strjoin(*line, ft_strsub(arr, 0, (c - arr)));
			free(*line);
			*line = buf;
//			ft_strdel(&buf);
			*str = ft_strdup(c + 1);
			return (ret);
		}
		*str = 0;
		*line = ft_strjoin(*line, arr);
		if (ret != BUFF_SIZE)
			return (1);
	}
	return (ret);
}

int				check_content(int fd, char **str, char **line)
{
	char		*c;
	int			x;

	c = ft_strchr(*str, '\n');
	if (c)
	{
		*line = ft_strsub(*str, 0, (c - *str));
		*str = ft_strdup(c + 1);
	}
	else
	{
		c = *str;
		x = get_new_line(fd, str, line);
		if (x == -1)
			return (x);
		*line = ft_strjoin(c, *line);
		if (x == 0 && **line && *line)
		{
			*str = 0;
			return (1);
		}
		return (x);
	}
	return (1);
}

int					get_next_line(const int fd, char **line)
{
	static t_list	*buf;
	t_list			*list;
	int				x;

	if (fd < 0 || !line)
		return (-1);
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
