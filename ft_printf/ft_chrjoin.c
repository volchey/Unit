/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chrjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchechai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 16:36:32 by vchechai          #+#    #+#             */
/*   Updated: 2018/01/15 16:37:03 by vchechai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void 		ft_chrjoin(char **str, char c)
{
	int 	size;
	char	*buf;

	size = ft_strlen(*str);
	buf = (char*)malloc(sizeof(char) * (size + 1));
	buf = ft_strcpy(buf, *str);
	buf[size] = c;
	buf[size + 1] = '\0';
	ft_strdel(str);
	*str = buf;
}
