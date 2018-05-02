/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_position.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchechai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 15:45:40 by vchechai          #+#    #+#             */
/*   Updated: 2018/02/22 15:49:56 by vchechai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		ft_distance(int x1, int y1, int x2, int y2)
{
	int res;
	int	dx;
	int dy;

	dx = (x2 - x1) < 0 ? (x1 - x2) : (x2 - x1);
	dy = (y2 - y1) < 0 ? (y1 - y2) : (y2 - y1);
	res = ft_sqrt(ft_power(dx, 2) + ft_power(dy, 2));
	return (res);
}

int		ft_to_enemy(t_xy i, t_xy psbl_xy, t_map piece)
{
	t_xy	xy;
	int		dist;
	int		min;

	xy.y = 0;
	min = 10000;
	while (xy.y < piece.height)
	{
		xy.x = 0;
		while (xy.x < piece.map[0].width)
		{
			if (piece.map[xy.y].row[xy.x].player != 0)
			{
				dist = ft_distance(i.x, i.y,
						piece.map[xy.y].row[xy.x].x + psbl_xy.x,
						piece.map[xy.y].row[xy.x].y + psbl_xy.y);
				if (dist <= min)
					min = dist;
			}
			xy.x++;
		}
		xy.y++;
	}
	return (min);
}

int		ft_get_min(t_xy i, t_xy *psbl_xy, int *res, t_map piece)
{
	int		j;
	int		x;
	int		dist;
	int		k;

	j = 0;
	k = 0;
	x = 10000;
	while (j < psbl_xy[0].player)
	{
		dist = ft_to_enemy(i, psbl_xy[j], piece);
		if (dist < x)
		{
			k = j;
			x = dist;
		}
		j++;
	}
	*res = x;
	return (k);
}

int		ft_get_position(t_row i, t_xy *psbl_xy, t_map piece, t_map map)
{
	int k;
	int max;
	int	dist;
	int j;
	int index;

	k = 0;
	max = 0;
	index = 0;
	while (k < 4)
	{
		j = ft_get_min(i.row[k], psbl_xy, &dist, piece);
		if ((dist < 5 && map.height == 24) || (dist < 15 && map.height > 90))
			return (ft_move(map, psbl_xy, 2, piece));
		if (dist > max)
		{
			max = dist;
			index = j;
		}
		k++;
	}
	return (index);
}

int		ft_set_position(t_map map, t_xy *psbl_xy, int p, t_map piece)
{
	t_row	xy;
	int		i;

	i = 0;
	if (!p)
		exit(0);
	xy.width = 4;
	xy.row = (t_xy*)malloc(sizeof(t_xy) * xy.width);
	xy.row[0].x = map.map->width / 2 + map.map->width / 4;
	xy.row[0].y = 0;
	xy.row[1].x = map.map->width / 3;
	xy.row[1].y = map.height;
	xy.row[2].x = 0;
	xy.row[2].y = map.height / 2 + map.height / 4;
	xy.row[3].x = map.map->width;
	xy.row[3].y = map.height / 3;
	return (ft_get_position(xy, psbl_xy, piece, map));
}
