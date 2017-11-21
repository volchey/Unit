/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_tetriminos.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfil <vfil@student.unit.ua>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 11:07:33 by vfil              #+#    #+#             */
/*   Updated: 2017/11/18 17:34:38 by vfil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_count_tetriminos(char *str)
{
	int	i;
	int	count;
	int	line;
	int	j;

	j = 0;
	count = 0;
	line = 0;
	while (str[j])
	{
		i = j;
		while ((str[j] == '.' || str[j] == '#') && str[j])
			j++;
		if ((j - i) % 4 != 0 || (str[j] != '\n' && str[j - 1] != '\n'))
			return (0);
		else
			line++;
		if (str[j] == '\n' && ((str[j - 1] == '\n' && line % 5 == 0)
				|| (str[j + 1] == '\0' && (line + 1) % 5 == 0)))
			count++;
		if (line % 5 == 0 && (str[j] != '\n' || str[j - 1] != '\n'))
			return (0);
		j++;
	}
	//test
//	ft_putstr("We have ");
//	ft_putnbr(count);
//	ft_putstr(" tetriminos\n");
	return (count);
}
