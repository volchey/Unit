/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_integer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchechai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 16:14:44 by vchechai          #+#    #+#             */
/*   Updated: 2018/01/12 16:21:01 by vchechai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	set_integer(char **str, int nb, int *i)
{
	char	*num;
	char	*buf;

	num = ft_itoa(nb);
	buf = *str;
	*str = ft_strjoin(buf, num);
	ft_strdel(&buf);
	ft_strdel(&num);
	*i += 2;
}
