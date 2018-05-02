/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchechai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 11:47:11 by vchechai          #+#    #+#             */
/*   Updated: 2018/02/15 11:47:19 by vchechai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include <mlx.h>
#include <locale.h>

void	ft_free_map(t_map *map)
{
	int i;

	i = 0;
	while (i < map->height)
	{
		free(map->map[i].row);
		i++;
	}
	free(map->map);
}

int	ft_getplayer(char *line)
{
	int		p;

	if (ft_strstr(line, "$$$ exec p") && ft_strstr(line, "vchechai.filler"))
		p = line[10] - '0';
	else
	{
		ft_printf("invalid input %S\n", L"😛");
		exit(-1);
	}
	return (p);
}

int	main(void)
{
	int		p;
	char	*line;
	void	*mlx_ptr;
	void	*win_ptr;

	setlocale(LC_ALL, "");
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 800, 900, "filler in da house");
	if (get_next_line(0, &line) <= 0)
	{
		ft_printf("invalid input %S\n", L"😛");
		exit(-1);
	}
	p = ft_getplayer(line);
	ft_start_mlx(mlx_ptr, win_ptr, p);
}
