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

int	main(int argc, char **argv)
{
	t_xy	coord;
	int 	p;
	char	*line;
	t_map	map;

	get_next_line(0, &line);
	p = ft_getplayer(line);
	while (get_next_line(0, &line) > 0)
	{
		map = ft_parse_map(line);
		get_next_line(0, &line);
		coord = ft_parse_piece(map, p, line);
		if (coord.player == -1)
		{
			ft_printf("%d %d\n", 0, 0);
			return (0);
		}
		ft_printf("%d %d\n", coord.y, coord.x);
		ft_strdel(&line);
	}
	return (0);
}
