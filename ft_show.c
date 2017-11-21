/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfil <vfil@student.unit.ua>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 16:13:07 by vfil              #+#    #+#             */
/*   Updated: 2017/11/18 17:36:14 by vfil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_show(t_tetrim *tt, int count, int sq_size)
{
	char	**res;
	int		i;
	int		j;
	int		k;
	int		t;
	int		d;

	i = 0;
	res = (char**)malloc(sizeof(char*) * (sq_size + 1));
	while (i < sq_size)
	{
		j = 0;
		res[i] = (char*)malloc(sizeof(char) * (sq_size + 2));
		while (j < sq_size)
		{
			t = 0;
			res[i][j] = '.';
			while (t < count)
			{
				d = 0;
				while (d < 4)
				{
					if (tt[t].block[d].x == j && tt[t].block[d].y == i)
						res[i][j] = 'A' + t;
					d++;
				}
				t++;
			}
			j++;
		}
		res[i][j] = '\n';
		j++;
		res[i][j] = '\0';
		i++;
	}
	res[i] = 0;
	k = 0;
	while (k < sq_size)
	{
		ft_putstr(res[k]);
		k++;
	}
	ft_putchar('\n');
}
