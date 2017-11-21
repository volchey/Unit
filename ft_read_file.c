/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfil <vfil@student.unit.ua>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 11:08:46 by vfil              #+#    #+#             */
/*   Updated: 2017/11/16 18:29:56 by vchechai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#define BUF_SIZE 1000

char	*ft_read_file(char *name)
{
	char	buf[BUF_SIZE];
	char	*str;
	int		fd;
	int		ret;

	fd = open(name, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr("open failed\n");
		return (0);
	}
	ret = read(fd, buf, BUF_SIZE);
	buf[ret] = '\0';
	str = ft_strnew(ret);
	ft_strcpy(str, buf);
	return (str);
}
