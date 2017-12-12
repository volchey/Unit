/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchechai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 18:45:24 by vchechai          #+#    #+#             */
/*   Updated: 2017/12/09 16:04:03 by vchechai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(int ac, char **av)
{
	int fd;
	int fd1;
	int	res;
	int	i;
	char *arr;

	res = 1;
	if (ac)
	{
		i = 0;
		fd = open(av[1], O_RDONLY);
		fd1 = open(av[2], O_RDONLY);
/*		while (i < 4)
		{
			res = get_next_line(fd1, &arr);
			ft_putstr(arr);
			ft_putchar('\n');
			res = get_next_line(fd, &arr);
			ft_putstr(arr);
			ft_putchar('\n');
			i++;
		}
		ft_putchar('\n');
		ft_putchar('\n');
		i = 0;
		while (i < 4)
		{
			res = get_next_line(fd, &arr);
			ft_putstr(arr);
			ft_putchar('\n');
			i++;
		}
		ft_putchar('\n');
		ft_putchar('\n');*/
		while (res && res != -1)
		{
			res = get_next_line(fd, &arr);
//			ft_putstr(arr);
			ft_putchar('\n');
		}
//		res = get_next_line(fd, &arr);
//		ft_putstr(arr);
//		ft_putchar('\n');
		system("leaks get_next_line");
		close(fd1);
		close(fd);
	}
	return (0);
}
