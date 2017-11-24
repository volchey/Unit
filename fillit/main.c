/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfil <vfil@student.unit.ua>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 10:55:11 by vfil              #+#    #+#             */
/*   Updated: 2017/11/24 15:27:35 by vchechai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int ac, char **av)
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
		exit(0);
	}
	if ((tetriminos = ft_read_file(av[1])) &&
			!(tt_set = ft_check_all(tetriminos)))
	{
		ft_putstr("error\n");
		exit(0);
	}
	count_tt = ft_count_tetriminos(tetriminos);
	ft_strdel(&tetriminos);
	tt = ft_parse_coord(tt_set, count_tt);
	sq_size = ft_sqrt_mod(count_tt);
	ft_start(tt, count_tt, &sq_size);
	ft_show(tt, count_tt, sq_size);
	return (0);
}

char	*ft_read_file(char *name)
{
	char	c;
	char	*str;
	int		fd;
	int		ret;
	int		i;

	fd = open(name, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr("error\n");
		exit(0);
	}
	i = 0;
	while ((ret = read(fd, &c, 1)) != '\0')
		i++;
	close(fd);
	fd = open(name, O_RDONLY);
	str = ft_strnew(i);
	i = 0;
	while ((ret = read(fd, &c, 1)) != '\0')
		str[i++] = c;
	str[i] = '\0';
	return (str);
}

void	ft_start(t_tetrim *tt, int count_tt, int *sq_size)
{
	int		i;
	t_coord	max;

	i = 0;
	while (i < count_tt)
	{
		ft_shift_x2start(&tt[i]);
		ft_shift_y2start(&tt[i]);
		max = ft_find_max_xy(&tt[i], sq_size);
		i++;
	}
	ft_fill(tt, sq_size, count_tt);
}

int		ft_sqrt_mod(int count)
{
	int	res;

	res = 2;
	while (res * res < count * 4)
		res++;
	return (res);
}
