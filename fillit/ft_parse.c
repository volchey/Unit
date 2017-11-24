/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfil <vfil@student.unit.ua>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 18:02:49 by vfil              #+#    #+#             */
/*   Updated: 2017/11/23 17:16:01 by vfil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char		**ft_parse_tt(char *s, int n_o_t)
{
	char	**tt_set;
	int		symb;
	int		tt;
	int		i;

	if (((!s || !n_o_t)) ||
			!(tt_set = (char**)malloc(sizeof(char*) * (n_o_t + 1))))
		return (NULL);
	i = 0;
	tt = 0;
	while (tt < n_o_t)
	{
		symb = 20;
		if (!(tt_set[tt] = ft_strsub(s, i, symb)))
			ft_arriter(tt_set - tt, &free);
		i += symb + 1;
		tt++;
	}
	tt_set[tt] = 0;
	return (tt_set);
}

t_tetrim	*ft_parse_coord(char **str, int count)
{
	t_tetrim	*arr;
	t_var		var;

	var.i = 0;
	if (!(arr = (t_tetrim*)malloc(sizeof(t_tetrim) * count)))
		return (0);
	while (str[var.i] && ((var.k = 0) == 0))
	{
		var.j = 0;
		var.d = 0;
		while (str[var.i][var.k])
		{
			if (str[var.i][var.k] == '\n')
				var.d++;
			if (str[var.i][var.k] == '#')
			{
				arr[var.i].block[var.j].x = var.k % 5;
				arr[var.i].block[var.j++].y = var.d;
			}
			var.k++;
		}
		var.i++;
	}
	ft_arriter(str, &free);
	return (arr);
}
