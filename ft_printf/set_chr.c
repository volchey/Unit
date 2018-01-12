/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_chr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchechai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 17:35:59 by vchechai          #+#    #+#             */
/*   Updated: 2018/01/12 17:36:49 by vchechai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	set_chr(char **str, char c, int *i)
{
	int 	size;
	char	*buf;

	size = ft_strlen(*str);
	buf = (char*)malloc(sizeof(char) * size + 1);
	buf = ft_strcpy(buf, *str);
	buf[size] = c;
	buf[size + 1] = '\0';
//	ft_strdel(&str);
	*str = ft_strcpy(*str, buf);
	ft_strdel(&buf);
	*i += 2;
}
