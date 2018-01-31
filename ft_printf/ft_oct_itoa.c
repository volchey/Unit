/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_oct_itoa.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchechai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 11:58:11 by vchechai          #+#    #+#             */
/*   Updated: 2018/01/17 11:58:14 by vchechai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_to_str(unsigned long bn, long long i, int len)
{
	long long	j;
	char		*arr;

	j = 0;
	arr = ft_strnew(len + 1);
	if (arr == NULL)
		return (arr);
	while (i > 0)
	{
		arr[j] = bn / i + '0';
		bn %= i;
		i /= 8;
		j++;
	}
	arr[j] = '\0';
	return (arr);
}

char		*ft_oct_itoa(unsigned long n)
{
	unsigned long	i;
	int			len;

	i = 1;
	len = 0;
	while (n / i > 7)
	{
		i *= 8;
		len++;
	}
	return (ft_to_str(n, i, len));
}

static char	*ft_to_str2(unsigned long long bn, unsigned long int i, int len)
{
	unsigned long int	j;
	char		*arr;

	j = 0;
	arr = ft_strnew(len + 1);
	if (arr == NULL)
		return (arr);
	while (i > 0)
	{
		arr[j] = bn / i + '0';
		bn %= i;
		i /= 8;
		j++;
	}
	arr[j] = '\0';
	return (arr);
}

char		*ft_oct_unlltoa(unsigned long long n)
{
	unsigned long int i;
	int len;

	i = 1;
	len = 0;
	while (n / i > 7) {
		i *= 8;
		len++;
	}
	return (ft_to_str2(n, i, len));
}
