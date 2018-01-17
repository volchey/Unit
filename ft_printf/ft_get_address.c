/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_address.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchechai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 20:16:22 by vchechai          #+#    #+#             */
/*   Updated: 2018/01/15 20:20:36 by vchechai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static char	*ft_to_str(long int bn, int len)
{
	char		*arr;
	int			ram;

	len += 2;
	arr = ft_strnew(len + 1);
	if (arr == NULL)
		return (arr);
	arr[0] = '0';
	arr[1] = 'x';
	arr[len--] = '\0';
	while (bn > 0)
	{
		ram = bn % 16;
		if (ram < 10)
			arr[len] = ram + '0';
		else
			arr[len] = ram + 87;
		bn /= 16;
		len--;
	}	
	return (arr);
}

char		*ft_hex_itoa(long int n)
{
	long int	bn;
	long int	i;
	int			len;

	bn = n;
	i = 1;
	len = 0;
	ft_putnbr(bn);
	ft_putchar('\n');
	if (bn < 0)
		bn *= -1;
	while (bn / i > 0)
	{
		i *= 16;
		len++;
	}
	return (ft_to_str(bn, len));
}