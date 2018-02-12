/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchechai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 17:53:18 by vchechai          #+#    #+#             */
/*   Updated: 2018/02/09 17:53:21 by vchechai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_map(t_row *map, void *mlx_ptr, void *win_ptr)
{
	int		w;
	int 	i;

	w = 0;
	while ((map[w]).size)
	{
		i = 1;
		while (i < map[w].size)
		{
			draw_line((map[w].coord)[i - 1], (map[w].coord)[i], mlx_ptr, win_ptr);
			i++;
		}
		w++;
	}
	i = 0;
	while (i < (map[0]).size)
	{
		w = 1;
		while ((map[w]).size)
		{
			draw_line((map[w - 1].coord)[i], (map[w].coord)[i], mlx_ptr, win_ptr);
			w++;
		}
		i++;
	}
}

void	change_param(int key, t_area *area)
{
	if (key == 69)
	{
		area->vy += 10;
		area->vx += 10;
		area->gx += 15;
		area->gy += 5;
		area->h += 1;
	}
	if (key == 78)
	{
		if (area->vy - 15 > 0)
			area->vy -= 10;
		if (area->vx - 10 > 0)
			area->vx -= 10;
		if (area->gx - 15 > 0)
			area->gx -= 15;
		if (area->gy - 5 > 0)
			area->gy -= 5;
		if (area->h - 1 > 0)
			area->h -= 1;
	}
	if (key == 115)
		area->h += 1;
	if (key == 119)
		area->h -= 1;
}

int	key_press(int key, t_mlx *mlx_var)
{
	if (key == 53)
		exit (0);
	else
	{
		if (key == 124)
			mlx_var->st_xy.x += 20;
		if (key == 123)
			mlx_var->st_xy.x -= 20;
		if (key == 125)
			mlx_var->st_xy.y += 20;
		if (key == 126)
			mlx_var->st_xy.y -= 20;
		if (key == 69 || key == 78 || key == 115 || key == 119)
			change_param(key, &(mlx_var->area));
	}
	mlx_clear_window(mlx_var->mlx_ptr, mlx_var->win_ptr);
	mlx_string_put(mlx_var->mlx_ptr, mlx_var->win_ptr, 100, 50, 0xffaaff,
				   "use arrows to move");
	mlx_string_put(mlx_var->mlx_ptr, mlx_var->win_ptr, 100, 70, 0xffaaff,
				   "use +- to scale");
	draw_map(parse_map(mlx_var->name, mlx_var->st_xy, mlx_var->area),
			 mlx_var->mlx_ptr, mlx_var->win_ptr);
	return (0);
}

int		main(int ac, char **av)
{
	t_row	*map;
	t_mlx	mlx_var;

	if (ac != 2)
		return (-1);
	mlx_var.mlx_ptr = mlx_init();
	mlx_var.win_ptr = mlx_new_window(mlx_var.mlx_ptr, 1600, 1200, "mlx 42");
	mlx_var.name = av[1];
	mlx_var.st_xy.x = 500;
	mlx_var.st_xy.y = 300;
	mlx_var.area.vx = 30;
	mlx_var.area.vy = 30;
	mlx_var.area.gx = 40;
	mlx_var.area.gy = 15;
	mlx_var.area.h = 1;
	mlx_string_put(mlx_var.mlx_ptr, mlx_var.win_ptr, 100, 50, 0xffaaff,
					"use arrows to move");
	mlx_string_put(mlx_var.mlx_ptr, mlx_var.win_ptr, 100, 70, 0xffaaff,
					"use +- to scale");
	mlx_key_hook(mlx_var.win_ptr, key_press, &mlx_var);
	map = parse_map(av[1], mlx_var.st_xy, mlx_var.area);
	draw_map(map, mlx_var.mlx_ptr, mlx_var.win_ptr);
	mlx_loop(mlx_var.mlx_ptr);
	return (0);
}
