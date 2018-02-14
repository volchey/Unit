/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchechai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/10 12:06:48 by vchechai          #+#    #+#             */
/*   Updated: 2018/02/10 12:06:50 by vchechai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <printf.h>
#include "fdf.h"

t_row	set_row(char *line, int size, t_coord st_xy, t_area area)
{
	int		i;
	int		j;
	int		val;
	t_row	row;
	int		k;

	j = -1;
	k = 0;
	row.coord = (t_coord*)malloc(sizeof(t_coord) * (size + 1));
	while (line[++j])
	{
		i = j;
		while (ft_isalnum(line[i]) || ft_isalpha(line[i]) || line[i] == ',')
			i++;
		if (i > j)
		{
			val = ft_atoi(line + j);
			(row.coord)[k].x = st_xy.x + k * area.gx + val * area.h;
			(row.coord)[k].y = st_xy.y + k * area.gy - val * area.h * 5;
			k++;
			j = i - 1;
		}
	}
	row.size = k;
	return (row);
}

t_row	parse_row(char *line, t_coord st_xy, t_area area, int *len)
{
	int		i;
	int		size;

	i = 0;
	size = 0;
	while (line[i])
	{
		if (line[i] >= '0' && line[i] <= '9')
		{
			size++;
			while (ft_isalnum(line[i]) || ft_isalpha(line[i]) || line[i] == ',')
				i++;
		}
		else
			i++;
	}
	if (*len != 0 && *len != size)
	{
		write(1, "Found wrong line length. Exiting.", 33);
		exit(-1);
	}
	else
		*len = size;
	return (set_row(line, size, st_xy, area));
}

int		file_size(char *name)
{
	char	*line;
	int		fd;
	int		size;

	size = 0;
	fd = open(name, O_RDONLY);
	while (get_next_line(fd, &line))
	{
		size++;
		free(line);
	}
	free(line);
	close(fd);
	return (size);
}

t_row	*parse_map(char *file, t_coord st_xy, t_area area)
{
	t_row	*map;
	char	*line;
	int		size;
	int		fd;
	int		len;

	len = 0;
	size = file_size(file);
	map = (t_row*)malloc(sizeof(t_row) * (size + 1));
	fd = open(file, O_RDONLY);
	size = 0;
	while (get_next_line(fd, &line))
	{
		map[size] = parse_row(line, st_xy, area, &len);
		st_xy.x -= area.vx;
		st_xy.y += area.vy;
		size++;
		free(line);
	}
	free(line);
	(map[size]).size = 0;
	return (map);
}
