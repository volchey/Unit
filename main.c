/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfil <vfil@student.unit.ua>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 10:55:11 by vfil              #+#    #+#             */
/*   Updated: 2017/11/22 14:01:57 by vfil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		ft_start(t_tetrim *tt, int count_tt, int *sq_size)
{
	int		i;

	i = 0;
	while (i < count_tt)
	{
		ft_shift_x2start(&tt[i]);
		ft_shift_y2start(&tt[i]);
		i++;
	}
	ft_fill(tt, count_tt, sq_size);
}

int			main(int ac, char **av)
{
	char		*tetriminos;
	char		**tt_set;
	t_tetrim	*tt;
	int			count_tt;
	int			sq_size;

	tt_set = NULL;
	if (ac != 2)
	{
		ft_putstr("usage: ./fillit target_file\n");
		return (1);
	}
	if ((tetriminos = ft_read_file(av[1])) &&
			!(tt_set = ft_check_all(tetriminos)))
	{
		ft_putstr("error\n");
		return (1);
	}
	count_tt = ft_count_tetriminos(tetriminos);
	tt = ft_parse_coord(tt_set, count_tt);
	sq_size = ft_sqrt_mod(count_tt);
	ft_start(tt, count_tt, &sq_size);
	ft_show(tt, count_tt, sq_size);
	return (0);
}
