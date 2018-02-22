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
#include <stdio.h>

int	ft_distance(int x1, int y1, int x2, int y2)
{
	int res;
	int	dx;
	int dy;

	dx = (x2 - x1) < 0 ? (x1 - x2) : (x2 - x1);
	dy = (y2 - y1) < 0 ? (y1 - y2) : (y2 - y1);
	res = ft_sqrt(ft_power(dx, 2) + ft_power(dy, 2));
	return (res);
}

int	ft_get_min(t_xy i, t_xy *psbl_xy, int *res)
{
	int		j;
	int		x;
	int 	dist;
	int 	k;

	j = 0;
	k = 0;
	x = 100;
	while (j < psbl_xy[0].player)
	{
		dist = ft_distance(i.x, i.y, psbl_xy[j].x, psbl_xy[j].y);
		if (dist <= x)
		{
			k = j;
			x = dist;
		}
		j++;
	}
	*res = x;
	return (k);
}

int	ft_set_position(t_map map, t_xy *psbl_xy, int p)
{
	t_xy	i;
	int		min;
	t_xy	info;

	min = 100;
	i.y = -1;
	info.y = 0;
	while (++(i.y) < map.height)
	{
		i.x = -1;
		while (++(i.x) < map.map[0].width)
		{
			if (map.map[i.y].row[i.x].player != 0
					&& map.map[i.y].row[i.x].player != p)
			{
				info.x = ft_get_min(i, psbl_xy, &info.player);
				if (info.player <= min)
				{
					info.y = info.x;
					min = info.player;
				}
			}
		}
	}
	return (info.y);
}
