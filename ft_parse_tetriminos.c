/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_tetriminos.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfil <vfil@student.unit.ua>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 13:50:26 by vfil              #+#    #+#             */
/*   Updated: 2017/11/18 17:35:16 by vfil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**ft_parse_tt(char *s, int n_o_t)
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

char	**ft_convert_tt(char **tt_set)
{
	char	c;
	int		i;
	int		j;

	c = 'A';
	i = 0;
	if (!tt_set && !*tt_set)
		return (NULL);
	while (tt_set[i])
	{
		j = 0;
		while (tt_set[i][j])
		{
			if (tt_set[i][j] == '#')
				tt_set[i][j] = c + i;
			j++;
		}
		i++;
	}
	return (tt_set);
}
