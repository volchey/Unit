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

#include "lem_in.h"

int			get_min_waylen(t_ant **ways)
{
	int i;
	int min;

	min = ways[0][0].ant;
	i = 0;
	while (ways[i])
	{
		if (ways[i][0].ant < min)
			min = ways[i][0].ant;
		i++;
	}
	return (min);
}

int			no_ants_in_ways(t_ant **ways)
{
	int	i;
	int j;

	i = 0;
	while (ways[i])
	{
		j = 1;
		while (j < ways[i][0].ant)
		{
			if (ways[i][j].ant != 0)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void		put_new_ant(t_ant **way, t_coord total, int *count, t_room *rooms)
{
	int size;

	size = (*way)[0].ant;
	if (*count < size - (size - total.y) - 2 && size != total.y)
		;
	else
	{
		(*way)[1].ant = total.x - *count + 1;
		ft_printf("L%d-%s ", (*way)[1].ant,
	rooms[(*way)[1].room].name);
		(*count)--;
	}
}

static void	move_ants(t_ant **way, t_coord total, int *count, t_room *rooms)
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
				put_new_ant(way, total, count, rooms);
		}
		else if ((*way)[size].ant == 0 && (*way)[size - 1].ant != 0)
		{
			(*way)[size].ant = (*way)[size - 1].ant;
			(*way)[size - 1].ant = 0;
			ft_printf("L%d-%s ", (*way)[size].ant,
	rooms[(*way)[size].room].name);
		}
		size--;
	}
}

void		lets_go(t_ant **ways, int count, t_room *rooms)
{
	int		i;
	t_coord j;
	int		amount;

	amount = 0;
	while (ways[amount])
		amount++;
	j.x = count;
	j.y = get_min_waylen(ways);
	while (1)
	{
		i = 0;
		while (ways[i])
		{
			move_ants(&ways[i], j, &count, rooms);
			i++;
		}
		if (no_ants_in_ways(ways))
			break ;
		ft_printf("\n");
	}
}
