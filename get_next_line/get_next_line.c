/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchechai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 16:36:03 by vchechai          #+#    #+#             */
/*   Updated: 2017/12/12 18:35:01 by vchechai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int					check_line(char *buf, char **str, char **line)
{
	char			*c;
	char			*tmp;

	if ((c = ft_strchr(buf, '\n')))
	{
		*str = *line;
		tmp = ft_strsub(buf, 0, (c - buf));
		*line = ft_strjoin(*str, tmp);
		ft_strdel(str);
		ft_strdel(&tmp);
		*str = ft_strdup(c + 1);
		return (1);
	}
	return (0);
}

int					get_new_line(int fd, char **str, char **line)
{
	int				ret;
	char			buf[BUFF_SIZE + 1];

	*line = ft_strnew(0);
	while ((ret = read(fd, buf, BUFF_SIZE)) && ret != -1)
	{
		buf[ret] = '\0';
		if (check_line(buf, str, line))
			return (ret);
		*str = *line;
		*line = ft_strjoin(*str, buf);
		ft_strdel(str);
		if (ret < BUFF_SIZE)
			return (1);
	}
	return (ret);
}

int					check_static_str(int fd, char **str, char **line)
{
	char			*buf1;
	char			*c;
	int				f;

	buf1 = *str;
	if ((c = ft_strchr(*str, '\n')))
	{
		*line = ft_strsub(*str, 0, (c - *str));
		ft_strdel(&buf1);
		*str = ft_strdup(c + 1);
	}
	else
	{
		f = get_new_line(fd, str, line);
		c = *line;
		*line = ft_strjoin(buf1, c);
		ft_strdel(&c);
		ft_strdel(&buf1);
		if (f == 0 && *line && **line)
		{
			*str = 0;
			return (1);
		}
		return (f);
	}
	ft_strdel(&buf1);
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
		list = ft_lstnew(0, 0);
		ft_lstadd(&buf, list);
	}
	if (!list->content_size)
		list->content_size = fd;
	if (list->content == 0)
		x = get_new_line(list->content_size, (char**)&list->content, line);
	else
		x = check_static_str(list->content_size, (char**)&list->content, line);
	if (x > 0)
		return (1);
	return (x);
}
