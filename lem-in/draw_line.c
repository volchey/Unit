/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchechai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/11 12:18:38 by vchechai          #+#    #+#             */
/*   Updated: 2018/02/11 12:18:40 by vchechai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"
#include <mlx.h>

void	draw_line_left(t_coord st_xy, t_coord end_xy, t_mlx c)
{
	int dx;
	int dy;
	int f;
	int d;

	f = 1;
	dx = end_xy.x - st_xy.x;
	dy = end_xy.y - st_xy.y;
	if (dy < 0)
	{
		f = -1;
		dy *= -1;
	}
	d = 2 * dy - dx;
	while (st_xy.x < end_xy.x)
	{
		mlx_pixel_put(c.mlx_ptr, c.win_ptr, st_xy.x, st_xy.y, c.color);
		if (d > 0)
		{
			st_xy.y += f;
			d -= 2 * dx;
		}
		d += 2 * dy;
		st_xy.x++;
	}
}

void	draw_line_right(t_coord st_xy, t_coord end_xy, t_mlx c)
{
	int dx;
	int dy;
	int f;
	int d;

	f = 1;
	dx = end_xy.x - st_xy.x;
	dy = end_xy.y - st_xy.y;
	if (dx < 0)
	{
		f = -1;
		dx *= -1;
	}
	d = 2 * dx - dy;
	while (st_xy.y < end_xy.y)
	{
		mlx_pixel_put(c.mlx_ptr, c.win_ptr, st_xy.x, st_xy.y, c.color);
		if (d > 0)
		{
			st_xy.x += f;
			d -= 2 * dy;
		}
		d += 2 * dx;
		st_xy.y++;
	}
}

void	draw_line(t_coord st_xy, t_coord end_xy, t_mlx c)
{
	int	dx;
	int	dy;

	dx = end_xy.x - st_xy.x;
	dx *= dx < 0 ? -1 : 1;
	dy = end_xy.y - st_xy.y;
	dy *= dy < 0 ? -1 : 1;
	if (dy < dx)
	{
		if (st_xy.x > end_xy.x)
			draw_line_left(end_xy, st_xy, c);
		else
			draw_line_left(st_xy, end_xy, c);
	}
	else
	{
		if (st_xy.y > end_xy.y)
			draw_line_right(end_xy, st_xy, c);
		else
			draw_line_right(st_xy, end_xy, c);
	}
}
