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

static char	*ft_to_str(long int bn, long int i, int len, int f)
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
		arr[j] = bn / i + '0';
		bn %= i;
		i /= 8;
		j++;
	}
	arr[j] = '\0';
	return (arr);
}

char		*ft_oct_itoa(int n)
{
	long int	bn;
	long int	i;
	int			len;
	int			f;

	bn = n;
	i = 1;
	len = 0;
	f = 0;
	if (bn < 0)
	{
		f = 1;
		bn *= -1;
		len++;
	}
	while (bn / i > 7)
	{
		i *= 8;
		len++;
	}
	return (ft_to_str(bn, i, len, f));
}