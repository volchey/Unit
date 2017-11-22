/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_coord.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchechai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 14:54:18 by vchechai          #+#    #+#             */
/*   Updated: 2017/11/21 15:47:13 by vfil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_tetrim	*ft_parse_coord(char **str, int count)
{
	t_tetrim	*arr;
	t_var		var;

	var.i = 0;
	if (!(arr = (t_tetrim*)malloc(sizeof(t_tetrim) * count)))
		return (0);
	while (str[var.i])
	{
		var.k = 0;
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
	return (arr);
}
