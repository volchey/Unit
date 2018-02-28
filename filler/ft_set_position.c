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

int		ft_to_enemy(t_row i, t_xy psbl_xy, t_map piece)
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
				dist = ft_distance(i.row[0].x, i.row[0].y,
						piece.map[xy.y].row[xy.x].x + psbl_xy.x,
						piece.map[xy.y].row[xy.x].y + psbl_xy.y);
				if (dist < min)
					min = dist;
			}
			xy.x++;
		}
		xy.y++;
	}
	return (min);
}

int		ft_get_min(t_row i, t_xy *psbl_xy, int *res, t_map piece)
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

void	ft_get_position(t_row i, t_xy *psbl_xy, t_xy *info, t_map piece)
{
	int min;

	info->x = ft_get_min(i, psbl_xy, &min, piece);
	if (i.row[0].player == 2 || (i.row[0].player == 1 && i.width == 100))
	{
		if (info->player >= min)
		{
			info->y = info->x;
			info->player = min;
		}
	}
	else if (i.row[0].player == 1 || (i.row[0].player == 2 && i.width == 100))
	{
		if (info->player > min)
		{
			info->y = info->x;
			info->player = min;
		}
	}
}

int		ft_set_position(t_map map, t_xy *psbl_xy, int p, t_map piece)
{
	t_row	i;
	t_xy	info;

	i.row = (t_xy*)malloc(sizeof(t_xy) * 1);
	i.row[0].y = 0;
	info.y = 0;
	i.row[0].player = p;
	info.player = 10000;
	i.width = map.height;
	while (i.row[0].y < map.height)
	{
		i.row[0].x = 0;
		while (i.row[0].x < map.map[0].width)
		{
			if (map.map[i.row[0].y].row[i.row[0].x].player != 0
					&& map.map[i.row[0].y].row[i.row[0].x].player != p)
				ft_get_position(i, psbl_xy, &info, piece);
			i.row[0].x++;
		}
		i.row[0].y++;
	}
	return (info.y);
}
