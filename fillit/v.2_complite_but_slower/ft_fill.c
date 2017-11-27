/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchechai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 12:12:32 by vchechai          #+#    #+#             */
/*   Updated: 2017/11/24 17:36:26 by vfil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			ft_verify(t_tetrim *tt, int i)
{
	t_var	var;

	var.j = i - 1;
	while (var.j >= 0)
	{
		var.d = 0;
		while (var.d < 4)
		{
			var.i = 0;
			while (var.i < 4)
			{
				if (tt[i].block[var.d].x == tt[var.j].block[var.i].x &&
						tt[i].block[var.d].y == tt[var.j].block[var.i].y)
					return (0);
				var.i++;
			}
			var.d++;
		}
		var.j--;
	}
	return (1);
}

void		ft_fill(t_tetrim *tt, int *sq_size, int count_tt)
{
	t_var	var;

	var.i = 0;
	while (var.i < count_tt)
	{
		var.k = 1;
		var.j = ft_verify(tt, var.i);
		if (var.j)
			var.i++;
		if (!var.j && var.i > 0)
			var.k = ft_shift_tt(&tt[var.i], sq_size);
		while (!var.k && var.i > 0)
		{
			var.i--;
			var.k = ft_shift_tt(&tt[var.i], sq_size);
		}
		if (!var.k && var.i == 0)
		{
			*sq_size += 1;
			ft_start(tt, count_tt, sq_size);
		}
	}
}
