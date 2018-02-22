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
#include <stdio.h>

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

t_xy			ft_parse_piece(t_map map, int p, char *buf)
{
	char	*line;
	t_map	piece;
	int 	i;
	int 	width;

	piece.height = ft_atoi(buf + 6);
	width = ft_atoi(buf + 8);
	i = 0;
	piece.map = (t_row*)malloc(sizeof(t_row) * (piece.height));
	while (i < (piece.height))
	{
		get_next_line(0, &line);
		(piece.map)[i] = ft_get_prow(i, width, line, p);
		ft_strdel(&line);
		i++;
	}
	return (ft_get_coord(map, piece, p));
}

t_map			ft_parse_map(char *buf)
{
	char	*line;
	t_map	map;
	int 	i;
	int 	width;

	map.height = ft_atoi(buf + 8);
	width = ft_atoi(buf + 10);
	get_next_line(0, &line);
	ft_strdel(&line);
	i = 0;
	map.map = (t_row*)malloc(sizeof(t_row) * (map.height));
	while (i < (map.height))
	{
		get_next_line(0, &line);
		(map.map)[i] = ft_get_row(i, width, line);
		ft_strdel(&line);
		i++;
	}
	return (map);
}
