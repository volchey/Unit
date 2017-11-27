/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_shift_tt.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfil <vfil@student.unit.ua>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 12:39:24 by vfil              #+#    #+#             */
/*   Updated: 2017/11/23 14:45:17 by vfil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_coord		ft_find_min_xy(t_tetrim *tt)
{
	int			i;
	t_coord		min;

	i = 0;
	min.x = tt->block[i].x;
	min.y = tt->block[i].y;
	while (i < 4)
	{
		if (tt->block[i].x < min.x)
			min.x = tt->block[i].x;
		if (tt->block[i].y < min.y)
			min.y = tt->block[i].y;
		i++;
	}
	return (min);
}

t_coord		ft_find_max_xy(t_tetrim *tt, int *sq_size)
{
	int			i;
	t_coord		max;

	i = 0;
	max.x = tt->block[i].x;
	max.y = tt->block[i].y;
	while (i < 4)
	{
		if (tt->block[i].x > max.x)
			max.x = tt->block[i].x;
		if (tt->block[i].y > max.y)
			max.y = tt->block[i].y;
		i++;
	}
	while (max.x > *sq_size - 1 || max.y > *sq_size - 1)
		*sq_size += 1;
	return (max);
}

void		ft_shift_x2start(t_tetrim *tt)
{
	int			i;
	t_coord		min;

	min = ft_find_min_xy(tt);
	while (min.x > 0)
	{
		i = 0;
		while (i < 4)
		{
			tt->block[i].x--;
			i++;
		}
		min.x--;
	}
}

void		ft_shift_y2start(t_tetrim *tt)
{
	int			i;
	t_coord		min;

	min = ft_find_min_xy(tt);
	while (min.y > 0)
	{
		i = 0;
		while (i < 4)
		{
			tt->block[i].y--;
			i++;
		}
		min.y--;
	}
}

int			ft_shift_tt(t_tetrim *tt, int *sq_size)
{
	int		i;
	t_coord	max;
	t_coord	min;

	i = 0;
	min = ft_find_min_xy(tt);
	max = ft_find_max_xy(tt, sq_size);
	while (i < 4)
	{
		if (max.x == *sq_size - 1 && max.y < *sq_size - 1)
			tt->block[i].y++;
		else if (max.x < *sq_size - 1)
			tt->block[i].x++;
		i++;
	}
	if (max.x == *sq_size - 1)
		ft_shift_x2start(tt);
	if (max.y == *sq_size - 1 && (max.x == *sq_size - 1))
	{
		ft_shift_y2start(tt);
		return (0);
	}
	return (1);
}
