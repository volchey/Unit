/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unitoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchechai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 18:18:51 by vchechai          #+#    #+#             */
/*   Updated: 2018/01/16 18:20:59 by vchechai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_to_str(unsigned int n, long int i, int len)
{
	long int	j;
	char		*arr;

	j = 0;
	arr = ft_strnew(len + 1);
	if (arr == NULL)
		return (arr);
	while (i > 0)
	{
		arr[j] = n / i + '0';
		n %= i;
		i /= 10;
		j++;
	}
	arr[j] = '\0';
	return (arr);
}

char		*ft_unitoa(unsigned int n)
{
	long int	i;
	int			len;

	i = 1;
	len = 0;
	while (n / i > 9)
	{
		i *= 10;
		len++;
	}
	return (ft_to_str(n, i, len));
}
