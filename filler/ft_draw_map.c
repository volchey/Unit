/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchechai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/24 20:54:35 by vchechai          #+#    #+#             */
/*   Updated: 2018/02/24 20:54:37 by vchechai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include <mlx.h>

void	ft_put_pixel(void *img_ptr, int x, int y, int p)
{
	int		bts_p_pxl;
	int		size_line;
	int		endian;
	int		*img;
	int		color;

	if (p == 2)
		color = 0xff69fa;
	else
		color = 0x69ff65;
	img = (int*)mlx_get_data_addr(img_ptr, &bts_p_pxl, &size_line, &endian);
	img[x + y * size_line / 4] = color;
}

void	ft_draw_square(t_xy xy, int width, int p, void *img_ptr)
{
	int i;
	int	j;
	int del;

	i = 0;
	del = 20;
	if (width < 20)
		del = 45;
	else if (width > 50)
		del = 8;
	xy.x *= del;
	if (width == 40)
		xy.y *= 30;
	else
		xy.y *= del;
	while (i < del / 2)
	{
		j = 0;
		while (j < del / 2)
		{
			ft_put_pixel(img_ptr, xy.x + j, xy.y + i, p);
			j++;
		}
		i++;
	}
}

void	ft_draw_map(t_map map, void *img_ptr)
{
	t_xy	xy;

	xy.y = 0;
	while (xy.y < map.height)
	{
		xy.x = 0;
		while (xy.x < map.map[0].width)
		{
			if (map.map[xy.y].row[xy.x].player != 0)
				ft_draw_square(xy, map.map[0].width,
						map.map[xy.y].row[xy.x].player, img_ptr);
			xy.x++;
		}
		xy.y++;
	}
}

int		ft_read(int key, t_mlx *mlx)
{
	t_xy	coord;
	char	*line;
	t_map	map;

	if (key == 53)
		exit(1);
	mlx_destroy_image(mlx->mlx_ptr, mlx->img_ptr);
	mlx->img_ptr = mlx_new_image(mlx->mlx_ptr, 800, 800);
	get_next_line(0, &line);
	map = ft_parse_map(line);
	ft_strdel(&line);
	ft_draw_map(map, mlx->img_ptr);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img_ptr, 0, 0);
	coord = ft_parse_piece(map, mlx->p);
	ft_free_map(&map);
	if (coord.player == -1)
	{
		ft_printf("%d %d\n", 0, 0);
		exit(1);
	}
	ft_printf("%d %d\n", coord.y, coord.x);
	return (0);
}

void	ft_start_mlx(void *mlx_ptr, void *win_ptr, int p)
{
	t_mlx	mlx;

	mlx.mlx_ptr = mlx_ptr;
	mlx.win_ptr = win_ptr;
	mlx.p = p;
	mlx.img_ptr = mlx_new_image(mlx_ptr, 800, 1200);
	if (p == 2)
	{
		mlx_string_put(mlx_ptr, win_ptr, 300, 850, 0xffffff, "vchechai = ");
		mlx_string_put(mlx_ptr, win_ptr, 410, 850, 0xff69fa, "pink");
	}
	else
	{
		mlx_string_put(mlx_ptr, win_ptr, 300, 850, 0xffffff, "vchechai = ");
		mlx_string_put(mlx_ptr, win_ptr, 410, 850, 0x69ff65, "green");
	}
	mlx_hook(win_ptr, 2, 5, ft_read, &mlx);
	mlx_loop(mlx_ptr);
}
