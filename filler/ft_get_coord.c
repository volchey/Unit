/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_coord.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchechai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 21:00:45 by vchechai          #+#    #+#             */
/*   Updated: 2018/02/15 21:00:46 by vchechai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		ft_check_position(t_map map, t_map piece, int row, int i)
{
	t_xy	xy;
	int		n;
	int		p1;
	int		p2;

	n = 0;
	xy.y = 0;
	while (xy.y < piece.height)
	{
		xy.x = 0;
		while (xy.x < piece.map[0].width)
		{
			p1 = map.map[row + xy.y].row[i + xy.x].player;
			p2 = piece.map[xy.y].row[xy.x].player;
			if (p1 != 0 && p2 != 0 && p1 == p2)
				n++;
			if (p1 != 0 && p2 != 0 && p1 != p2)
				return (0);
			xy.x++;
		}
		xy.y++;
	}
	return (n == 1 ? 1 : 0);
}

int		ft_count_position(t_map map, t_map piece)
{
	int		row;
	int		i;
	int		size;

	size = 0;
	row = 0;
	while (row < (map.height - piece.height))
	{
		i = 0;
		while (i < (map.map[row].width - piece.map[0].width))
		{
			if (ft_check_position(map, piece, row, i))
				size++;
			i++;
		}
		row++;
	}
	return (size);
}

t_xy	*ft_posible_position(t_map map, t_map piece)
{
	t_xy	*psbl_xy;
	int		n;
	int		i;
	int		row;

	n = 0;
	row = 0;
	psbl_xy = (t_xy*)malloc(sizeof(t_xy) * (ft_count_position(map, piece)));
	while (row < (map.height - piece.height))
	{
		i = 0;
		while (i < (map.map[row].width - piece.map[0].width))
		{
			if (ft_check_position(map, piece, row, i))
			{
				psbl_xy[n].x = i;
				psbl_xy[n].y = row;
				n++;
			}
			i++;
		}
		row++;
	}
	psbl_xy->player = (n == 0) ? -1 : n;
	return (psbl_xy);
}

t_xy	ft_get_coord(t_map map, t_map piece)
{
	t_xy	*psbl_xy;
	int		i;

	i = 0;
	psbl_xy = ft_posible_position(map, piece);
//	while (i < psbl_xy->player)
//	{
//		ft_printf("x: %d y: %d\n", psbl_xy[i].x, psbl_xy[i].y);
//		i++;
//	}
	return (*psbl_xy);
}
