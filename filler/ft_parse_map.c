/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchechai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 16:28:07 by vchechai          #+#    #+#             */
/*   Updated: 2018/02/15 16:28:09 by vchechai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static t_row	ft_get_row(int y, int width, char *line)
{
	int		i;
	t_row	row;

	line += 4;
	i = 0;
	row.row = (t_xy*)malloc(sizeof(t_xy) * (width));
	while (i < width)
	{
		(row.row)[i].player = 0;
		if (line[i] == 'x' || line[i] == 'X')
			(row.row)[i].player = 2;
		else if (line[i] == 'o' || line[i] == 'O')
			(row.row)[i].player = 1;
		(row.row)[i].x = i;
		(row.row)[i].y = y;
		i++;
	}
	row.width = width;
	return (row);
}

t_map			ft_parse_map(int fd)
{
	char	*line;
	t_map	map;
	int 	i;
	int 	width;

	while (get_next_line(fd, &line) > 0 && !ft_strstr(line, "Plateau"))
		ft_strdel(&line);
	map.height = ft_atoi(line + 8);
	width = ft_atoi(line + 10);
	ft_strdel(&line);
	get_next_line(fd, &line);
	ft_strdel(&line);
	i = 0;
	map.map = (t_row*)malloc(sizeof(t_row) * (map.height));
	while (i < (map.height))
	{
		get_next_line(fd, &line);
		(map.map)[i] = ft_get_row(i, width, line);
		ft_strdel(&line);
		i++;
	}
	ft_strdel(&line);
	return (map);
}

static t_row	ft_get_prow(int y, int width, char *line, int p)
{
	int		i;
	t_row	row;

	i = 0;
	row.row = (t_xy*)malloc(sizeof(t_xy) * (width));
	while (i < width)
	{
		(row.row)[i].player = 0;
		if (line[i] == '*')
			(row.row)[i].player = p;
		(row.row)[i].x = i;
		(row.row)[i].y = y;
		i++;
	}
	row.width = width;
	return (row);
}

t_map			ft_parse_piece(int fd, int p)
{
	char	*line;
	t_map	piece;
	int 	i;
	int 	width;

	i = 6;
	get_next_line(fd, &line);
	piece.height = ft_atoi(line + i);
	while (ft_isalnum(line[i]))
		i++;
	width = ft_atoi(line + i);
	ft_strdel(&line);
	i = 0;
	piece.map = (t_row*)malloc(sizeof(t_row) * (piece.height));
	while (i < (piece.height))
	{
		get_next_line(fd, &line);
		(piece.map)[i] = ft_get_prow(i, width, line, p);
		ft_strdel(&line);
		i++;
	}
	ft_strdel(&line);
	return (piece);
}
