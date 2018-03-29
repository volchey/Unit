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

#include "lem_in.h"
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

void	draw_squere(float x, float y, t_mlx mlx)
{
	int		i;
	t_coord s_xy;
	t_coord	e_xy;
	float 	size;

	i = 0;
	size = 40;
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

int 	is_in_ways(t_ant **ways, int room)
{
	int	i;
	int	j;
	int size;

	size = 0;
	while (ways[size])
		size++;
	i = 0;
	while (ways[i])
	{
		j = 0;
		while (j < ways[i][0].ant)
		{
			if (room == ways[i][j].room)
				return ((0xaaaaee / (size)) * (i + 1));
			j++;
		}
		i++;
	}
	return (0x000000);
}

void	draw_links(t_room *rooms, t_link *links, t_mlx mlx, t_ant **ways)
{
	int		i;
	int		color;
	t_coord	s_xy;
	t_coord	e_xy;

	i = 0;
	while (links[i].room1 != -1)
	{
		mlx.color = 0xFFFFFF;
		color = is_in_ways(ways, links[i].room1);
		if (color == is_in_ways(ways, links[i].room2))
			mlx.color = color;
		s_xy.x = rooms[links[i].room1].x * 20 + 20;
		s_xy.y = rooms[links[i].room1].y * 20 + 20;
		e_xy.x = rooms[links[i].room2].x * 20 + 20;
		e_xy.y = rooms[links[i].room2].y * 20 + 20;
		draw_line(s_xy, e_xy, mlx);
		i++;
	}
}

void	draw_farm(t_room *rooms, t_ant **ways, t_link *links)
{
	void	*mlx_ptr;
	void	*win_ptr;
	int 	i;
	t_mlx	mlx;

	i = 0;
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 1500, 1000, "lem-in in da house");
	mlx.win_ptr = win_ptr;
	mlx.mlx_ptr = mlx_ptr;
	while (rooms[i].status != '0')
	{
		mlx.color = is_in_ways(ways, i);
		draw_squere(rooms[i].x * 20, rooms[i].y * 20, mlx);
		if (rooms[i].status == 's' || rooms[i].status == 'e')
			mlx_string_put(mlx.mlx_ptr, mlx.win_ptr, \
			rooms[i].x * 20 + 3, rooms[i].y * 20 - 4, 0xFFFFFF, &rooms[i].status);
		else
			mlx_string_put(mlx.mlx_ptr, mlx.win_ptr, rooms[i].x * 20 + 3, \
			rooms[i].y * 20 - 4, 0xFFFFFF, ft_itoa(i));
		i++;
	}
	draw_links(rooms, links, mlx, ways);
	mlx_hook(win_ptr, 2, 5, escape, (void*)0);
	mlx_loop(mlx_ptr);
}
