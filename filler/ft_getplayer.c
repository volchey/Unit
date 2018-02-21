/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getplayer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchechai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 19:43:13 by vchechai          #+#    #+#             */
/*   Updated: 2018/02/15 19:43:15 by vchechai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int	ft_getplayer(int fd)
{
	char	*line;
	int 	p;

	line = 0;
	p = 0;
	while (get_next_line(fd, &line) > 0)
	{
		if (ft_strstr(line, "$$$ exec p") && ft_strstr(line, "vchechai.filler"))
		{
			p = line[10] - '0';
			break ;
		}
		ft_strdel(&line);
	}
	return (p);
}
