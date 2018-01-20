/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex_itoa.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchechai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 12:27:12 by vchechai          #+#    #+#             */
/*   Updated: 2018/01/17 12:27:30 by vchechai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_to_str(long int bn, int len)
{
	char		*arr;
	int			ram;

	arr = ft_strnew(len + 1);
	if (arr == NULL)
		return (arr);
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
	if (bn < 0)
		bn *= -1;
	while (bn / i > 0)
	{
		i *= 16;
		len++;
	}
	return (ft_to_str(bn, len));
}

static char	*ft_to_uppstr(long int bn, int len)
{
	char		*arr;
	int			ram;

	arr = ft_strnew(len + 1);
	if (arr == NULL)
		return (arr);
	arr[len--] = '\0';
	while (bn > 0)
	{
		ram = bn % 16;
		if (ram < 10)
			arr[len] = ram + '0';
		else
			arr[len] = ram + 55;
		bn /= 16;
		len--;
	}	
	return (arr);
}

char		*ft_upphex_itoa(long int n)
{
	long int	bn;
	long int	i;
	int			len;

	bn = n;
	i = 1;
	len = 0;
	if (bn < 0)
		bn *= -1;
	while (bn / i > 0)
	{
		i *= 16;
		len++;
	}
	return (ft_to_uppstr(bn, len));
}