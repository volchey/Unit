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

int	main(void)
{
	t_map	map;
	t_map	piece;
	t_xy	coord;
	int 	fd;
	int 	p;

	fd = 0;//open("test.filler", O_RDONLY);
	p = ft_getplayer(fd);
	while (1)
	{
		map = ft_parse_map(fd);
		piece = ft_parse_piece(fd, p);
		coord = ft_get_coord(map, piece);
		if (coord.player == -1)
			return (0);
		ft_putnbr_fd(coord.y, 1);
		ft_putchar_fd(' ', 1);
		ft_putnbr_fd(coord.x, 1);
		ft_putchar_fd('\n', 1);
	}
	close(fd);
	return (0);
}
