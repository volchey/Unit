/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex_unlltoa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchechai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 16:01:58 by vchechai          #+#    #+#             */
/*   Updated: 2018/01/29 16:02:00 by vchechai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_to_str(unsigned long long nb, int len)
{
    char		*arr;
    int			ram;

    arr = ft_strnew(len + 1);
    if (arr == NULL)
        return (arr);
    arr[len--] = '\0';
    while (nb > 0)
    {
        ram = nb % 16;
        if (ram < 10)
            arr[len] = ram + '0';
        else
            arr[len] = ram + 87;
        nb /= 16;
        len--;
    }
    return (arr);
}

char		*ft_hex_unlltoa(unsigned long long nb)
{
    long int	i;
    int			len;

    i = 1;
    len = 0;
    while (nb / i > 0)
    {
        i *= 16;
        len++;
    }
    return (ft_to_str(nb, len));
}

static char	*ft_to_str2(unsigned long long nb, int len)
{
    char		*arr;
    int			ram;

    arr = ft_strnew(len + 1);
    if (arr == NULL)
        return (arr);
    arr[len--] = '\0';
    while (nb > 0)
    {
        ram = nb % 16;
        if (ram < 10)
            arr[len] = ram + '0';
        else
            arr[len] = ram + 55;
        nb /= 16;
        len--;
    }
    return (arr);
}

char		*ft_upphex_unlltoa(unsigned long long nb)
{
    long int	i;
    int			len;

    i = 1;
    len = 0;
    while (nb / i > 0)
    {
        i *= 16;
        len++;
    }
    return (ft_to_str2(nb, len));
}
