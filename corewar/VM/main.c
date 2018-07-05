/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchechai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/05 14:57:22 by vchechai          #+#    #+#             */
/*   Updated: 2018/07/05 14:57:28 by vchechai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "inc/vm.h"

unsigned char	*get_map(t_bot *bots, unsigned int amount)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	k;
	int 			step;
	unsigned char	*map;

	step = MEM_SIZE / amount;
	i = 0;
	j = 0;
	map = (unsigned char*)malloc(sizeof(unsigned char) * (MEM_SIZE + 1));
	map[MEM_SIZE] = '\0';
	while (i < MEM_SIZE)
		map[i++] = 0;
	while (j < amount)
	{
		k = 0;
		while (k < bots[j].size)
		{
			map[k + j * step] = bots[j].code[k];
			k++;
		}
		j++;
	}
	return (map);
}

unsigned int	count_bots(int argc, char **argv)
{
	int				i;
	unsigned int	count;

	i = 1;
	count = 0;
	while (i < argc)
	{
		if (ft_strstr(argv[i], ".cor"))
			count++;
		i++;
	}
	if (count > 4)
		return (0);
	return (count);
}

t_bot			*get_bots(int argc, char **argv, unsigned int size)
{
	t_bot			*bots;
	int				i;
	unsigned int	count;

	count = 0;
	i = 1;
	bots = (t_bot *)malloc(sizeof(t_bot) * size);
	if (!bots)
		ft_exit("Invalid number of players");
	while (i < argc)
	{
		if (ft_strstr(argv[i], ".cor"))
		{
			bots[count] = parse_bot(argv[i]);
			bots[count].id = count;
			count++;
		}
		i++;
	}
	return (bots);
}

int				main(int argc, char **argv)
{
	t_bot			*bots;
	unsigned int	bots_count;
	unsigned char	*map;

	bots_count = count_bots(argc, argv);
	ft_printf("bots amount %d\n", bots_count);
	bots = get_bots(argc, argv, bots_count);
	map = get_map(bots, bots_count);
	print_map(map);
	return (0);
}
