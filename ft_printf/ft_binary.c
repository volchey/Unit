/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_binary.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchechai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/20 13:15:40 by vchechai          #+#    #+#             */
/*   Updated: 2018/01/20 13:19:03 by vchechai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_binary(int value)
{
	char	*bin;
	int		x;
	int		num;
	int		i;

	x = 0;
	num = 0;
	i = 0;
	while (ft_power(2, x) < value)
		x++;
	bin = ft_strnew(x);
	while (x > 0)
	{
		x--;
		if ((num + ft_power(2, x)) <= value)
		{
			num += ft_power(2, x);
			bin[i++] = '1';
		}
		else
			bin[i++] = '0';
	}
	bin[i] = '\0';
	return (bin);
}
