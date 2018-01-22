/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lltoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchechai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 19:25:25 by vchechai          #+#    #+#             */
/*   Updated: 2018/01/22 19:25:29 by vchechai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_to_str(long long n, long int i, int len, int f)
{
	long int	j;
	char		*arr;

	j = 0;
	arr = ft_strnew(len + 1);
	if (arr == NULL)
		return (arr);
	if (f)
		arr[j++] = '-';
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

char		*ft_lltoa(long long n)
{
	long int	i;
	long		len;
	int			f;

	i = 1;
	len = 0;
	f = 0;
	if (n < 0)
	{
		f = 1;
		n *= -1;
		len++;
	}
	while (n / i > 9)
	{
		i *= 10;
		len++;
	}
	return (ft_to_str(n, i, len, f));
}
