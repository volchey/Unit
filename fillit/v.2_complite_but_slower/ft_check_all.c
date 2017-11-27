/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_all.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfil <vfil@student.unit.ua>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 14:53:18 by vfil              #+#    #+#             */
/*   Updated: 2017/11/27 15:36:14 by vfil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**ft_check_all(char *str)
{
	int			count_tt;
	int			i;
	char		**tt_set;

	count_tt = ft_count_tetriminos(str);
	if (!(ft_check_end(str)) || !(count_tt) || !(ft_check_nl(str))
			|| count_tt > 26)
		return (0);
	if (!(tt_set = ft_parse_tt(str, count_tt)) || !(ft_check_nob(tt_set)))
		return (0);
	i = 0;
	while (tt_set[i])
	{
		if (!(ft_check_neighbor(tt_set[i])))
			return (0);
		i++;
	}
	return (tt_set);
}

int		ft_check_end(char *str)
{
	while (*str)
		str++;
	return ((*(str - 2) == '\n' && *(str - 1) == '\n') ? 0 : 1);
}

int		ft_check_nob(char **tt_set)
{
	int	is_ok;
	int i;
	int j;
	int	count;

	is_ok = 1;
	i = 0;
	while (tt_set[i])
	{
		count = 0;
		j = 0;
		while (tt_set[i][j])
		{
			if (tt_set[i][j] == '#')
				count++;
			j++;
		}
		if (count != 4)
			is_ok = 0;
		i++;
	}
	return (is_ok);
}

int		ft_difference(int i, int j)
{
	int	dif;

	dif = i - j;
	if (dif < 0)
		dif *= -1;
	if (dif == 5 || dif == 1)
		return (1);
	return (0);
}

int		ft_check_neighbor(char *str)
{
	t_var var;

	var.i = 0;
	var.d = 0;
	while (str[var.i] && ((var.j = 0) == 0))
	{
		if (str[var.i] == '#' && ((var.k = 0) == 0))
		{
			while (str[var.j])
			{
				if (str[var.j] == '#' && ft_difference(var.i, var.j))
					var.k = 1;
				var.j++;
				if (str[var.j] == '#' && var.k == 1 &&
						ft_difference(var.i, var.j))
					var.d = 1;
			}
			if (!var.k)
				return (0);
		}
		var.i++;
	}
	if (!var.d)
		return (0);
	return (1);
}
