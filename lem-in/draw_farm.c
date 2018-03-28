/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchechai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/25 16:38:00 by vchechai          #+#    #+#             */
/*   Updated: 2018/03/25 16:38:05 by vchechai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"
#include "mlx.h"

void	draw_frame(float x, float y, float size, t_mlx mlx)
{
	t_coord	s_xy;
	t_coord e_xy;

	s_xy.x = x;
	s_xy.y = y;
	mlx.color = 0xFF5555;
	e_xy.x = x + size - size / 4;
	e_xy.y = y;
	draw_line(s_xy, e_xy, mlx);
	e_xy.x = x;
	e_xy.y = y + size - size / 4;
	draw_line(s_xy, e_xy, mlx);
	s_xy.x = x + size - size / 4;
	s_xy.y = y + size - size / 4;
	draw_line(s_xy, e_xy, mlx);
	e_xy.x = x + size - size / 4;
	e_xy.y = y;
	draw_line(s_xy, e_xy, mlx);
}

void	draw_squere(float x, float y, float size, t_mlx mlx)
{
	int		i;
	t_coord s_xy;
	t_coord	e_xy;

	i = 0;
	s_xy.x = x;
	e_xy.x = x + size - size / 4;
	while (i < size - size / 4)
	{
		s_xy.y = y;
		e_xy.y = y;
		draw_line(s_xy, e_xy, mlx);
		y++;
		i++;
	}
	draw_frame(x, y - (size - size / 4), size, mlx);
}

int		escape(int key)
{
	if (key == 53)
		exit(1);
	return (0);
}

void	draw_links(t_room *rooms, t_link *links)
{
	int i;

	i = 0;
	while (links[i].room1 != -1)
	{

	}
}

void	draw_farm(t_room *rooms, t_ant **ways, t_link *links)
{
	void	*mlx_ptr;
	void	*win_ptr;
	int 	i;
	t_mlx	mlx;

	i = 0;
	mlx.color = 0xFFFFFF;
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 1500, 1000, "lem-in in da house");
	mlx.win_ptr = win_ptr;
	mlx.mlx_ptr = mlx_ptr;
	while (rooms[i].status != '0')
	{
		draw_squere(rooms[i].x * 10, rooms[i].y * 10, 20, mlx);
		i++;
	}
//	draw_links(rooms, links);
	mlx_hook(win_ptr, 2, 5, escape, (void*)0);
	mlx_loop(mlx_ptr);
}
