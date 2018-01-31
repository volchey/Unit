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

static char	*ft_to_str(unsigned long int n, int len)
{
	char		*arr;
	long		ram;

	arr = ft_strnew(len + 1);
	if (arr == NULL)
		return (arr);
    if (n == 0)
        arr[0] = '0';
	arr[len--] = '\0';
	while (len > 0)
	{
		ram = n % 16;
		if (ram < 10)
			arr[len] = ram + '0';
		else
			arr[len] = ram + 87;
		n /= 16;
		len--;
	}	
	return (arr);
}

char		*ft_hex_itoa(unsigned long int n)
{
	long int	i;
	int			len;

	i = 1;
	len = 0;
    if (n == 0)
        len++;
	while (n / i > 0)
	{
		i *= 16;
		len++;
	}
	return (ft_to_str(n, len));
}

static char	*ft_to_uppstr(unsigned long int n, int len)
{
	char		*arr;
	int			ram;

	arr = ft_strnew(len + 1);
	if (arr == NULL)
		return (arr);
    if (n == 0)
        arr[0] = '0';
	arr[len--] = '\0';
	while (n > 0)
	{
		ram = n % 16;
		if (ram < 10)
			arr[len] = ram + '0';
		else
			arr[len] = ram + 55;
		n /= 16;
		len--;
	}	
	return (arr);
}

char		*ft_upphex_itoa(unsigned long int n)
{
	long int	i;
	int			len;

	i = 1;
	len = 0;
    if (n == 0)
        len++;
	while (n / i > 0)
	{
		i *= 16;
		len++;
	}
	return (ft_to_uppstr(n, len));
}