/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unistr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchechai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/20 13:21:27 by vchechai          #+#    #+#             */
/*   Updated: 2018/01/20 13:47:48 by vchechai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_unistr(int *ptr)
{
	int		i;
	size_t	size;
	char	*str;
	char	*buf;

	i = 0;
	size = (sizeof(ptr) / sizeof(int));
	str = ft_strnew(1);
	str[0] = '\0';
	while (i < (int)size + 2 && ptr[i])
	{
		buf = str;
		str = ft_strjoin(str, (char*)ft_unichar(ptr[i]));
		ft_strdel(&buf);
		i++;
	}
	return (str);
}
