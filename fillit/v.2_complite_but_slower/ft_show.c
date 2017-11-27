/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfil <vfil@student.unit.ua>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 16:13:07 by vfil              #+#    #+#             */
/*   Updated: 2017/11/23 17:44:24 by vfil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_check_char(t_tetrim *tt, int y, int x, int count)
{
	int		i;
	int		j;

	i = 0;
	while (i < count)
	{
		j = 0;
		while (j < 4)
		{
			if (tt[i].block[j].x == x && tt[i].block[j].y == y)
				return (i);
			j++;
		}
		i++;
	}
	return (-19);
}

void	ft_putarr(char **res)
{
	while (*res)
	{
		ft_putstr(*res);
		res++;
	}
}

void	ft_show(t_tetrim *tt, int count, int sq_size)
{
	char	**res;
	t_var	var;

	var.i = 0;
	if (!(res = (char**)malloc(sizeof(char*) * (sq_size + 1))))
		return ;
	while (var.i < sq_size)
	{
		var.j = 0;
		if (!(res[var.i] = (char*)malloc(sizeof(char) * (sq_size + 2))))
		{
			ft_arriter(res, &free);
			exit(0);
		}
		while (var.j < sq_size)
		{
			res[var.i][var.j] = ('A' + ft_check_char(tt, var.i, var.j, count));
			var.j++;
		}
		res[var.i][var.j++] = '\n';
		res[var.i++][var.j] = '\0';
	}
	res[var.i] = 0;
	ft_putarr(res);
}
