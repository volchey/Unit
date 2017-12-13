/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchechai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 16:36:03 by vchechai          #+#    #+#             */
/*   Updated: 2017/12/13 19:00:27 by vchechai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int					get_new_line(int fd, char **str)
{
	int				ret;
	char			*arr;
	char			*buf;

	buf = ft_strnew(BUFF_SIZE + 1);
	while ((ret = read(fd, buf, BUFF_SIZE)) && ret != -1)
	{
		buf[ret] = '\0';
		arr = *str;
		*str = ft_strjoin(arr, buf);
		ft_strdel(&arr);
		if (ft_strchr(buf, '\n') || ret != BUFF_SIZE)
		{
			ft_strdel(&buf);
			return (ret);
		}
		ft_strdel(&buf);
		buf = ft_strnew(BUFF_SIZE + 1);
	}
	ft_strdel(&buf);
	return (ret);
}

int					check_static_str(char **str, char **line)
{
	char			*c;
	char			*buf;

	if ((c = ft_strchr(*str, '\n')))
	{
		*line = ft_strsub(*str, 0, (c - *str));
		buf = *str;
		*str = ft_strdup(c + 1);
		ft_strdel(&buf);
		return (1);
	}
	*line = ft_strdup(*str);
	ft_strdel(str);
	*str = ft_strnew(0);
	if (*line && **line)
		return (1);
	return (0);
}

int					get_next_line(const int fd, char **line)
{
	static t_list	*buf;
	t_list			*list;
	int				x;

	x = 0;
	if (fd < 0 || !line)
		return (-1);
	if (!buf)
		buf = ft_lstnew("", fd);
	list = buf;
	while (list && (int)list->content_size != fd)
		list = list->next;
	if (!list)
	{
		list = ft_lstnew("", fd);
		ft_lstadd(&buf, list);
	}
//	if (!list->content_size)
//		list->content_size = fd;
	if (!list->content || (!(ft_strchr((char*)list->content, '\n'))))
		x = get_new_line(list->content_size, (char**)&list->content);
	if (list->content && x >= 0)
		x = check_static_str((char**)&list->content, line);
	return (x > 0 ? 1 : x);
}
