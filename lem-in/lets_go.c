/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lets_go.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchechai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/24 19:25:47 by vchechai          #+#    #+#             */
/*   Updated: 2018/03/24 19:25:55 by vchechai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

static void	move_ants(t_ant **way, int total, int *count, t_room *rooms)
{
	int size;

	size = 0;
	while ((*way)[size].ant != -1)
		size++;
	if ((*way)[size - 1].ant != 0)
		(*way)[size - 1].ant = 0;
	while (size > 0)
	{
		if (size == 1)
		{
			if (size <= *count)
			{
				(*way)[1].ant = total - *count + 1;
				ft_printf("L%d-%s ", (*way)[size].ant,
						  rooms[(*way)[size].room].name);
				(*count)--;
			}
		}
		else if ((*way)[size].ant == 0 && (*way)[size - 1].ant != 0)
		{
			(*way)[size].ant = (*way)[size - 1].ant;
			(*way)[size - 1].ant = 0;
			ft_printf("L%d-%s ", (*way)[size].ant, rooms[(*way)[size].room].name);
		}
		size--;
	}
}

void	lets_go(t_ant **ways, int count, t_room *rooms)
{
	int i;
	int j;
	int max;

	i = 0;
	max = 0;
	while (ways[i])
	{
		j = 0;
		while (ways[i][j].ant != -1)
			j++;
		if (j > max)
			max = j;
		i++;
	}
	max += i;
	j = count;
	while (max)
	{
		i = 0;
		while (ways[i])
		{
			move_ants(&ways[i], j, &count, rooms);
			i++;
		}
		ft_printf("\n");
		max--;
	}
}
