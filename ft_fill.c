/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchechai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 12:12:32 by vchechai          #+#    #+#             */
/*   Updated: 2017/11/20 10:38:00 by vchechai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			ft_verify(t_tetrim *tt, int i, int sq_size, int count_tt)
{
	t_var	var;

	var.k = 1;
	if (i == 0)
		var.k = ft_shift_tt(&tt[i], sq_size);
	if (!var.k)
	{
		ft_start(tt, count_tt, sq_size + 1);
		return (1);
	}
	var.j = i - 1;
	while (var.j >= 0)
	{
		var.d = 0;
		while (var.d < 4)
		{
			var.i = 0;
			while (var.i < 4)
				if (tt[i].block[var.d].x == tt[var.j].block[var.i].x && 
						tt[i].block[var.d++].y == tt[var.j].block[var.i++].y)
					return (0);
		}
		var.j--;
	}
	return (1);
}

void		ft_fill(t_tetrim *tt, int count, int sq_size)
{
	t_var	var;

	var.i = 1;
	while (var.i < count)
	{
		var.k = 1;
		while (!(ft_verify(tt, var.i, sq_size, count)) && var.k)
			var.k = ft_shift_tt(&tt[var.i], sq_size);
		while (!var.k && var.i >= 0)
		{
			var.i--;
			var.k = ft_shift_tt(&tt[var.i], sq_size);
			while (!(ft_verify(tt, var.i, sq_size, count)) && var.k)
				var.k = ft_shift_tt(&tt[var.i], sq_size);
		}
		var.i++;
	}
}
