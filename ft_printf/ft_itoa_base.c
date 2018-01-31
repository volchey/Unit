/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchechai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 11:26:06 by vchechai          #+#    #+#             */
/*   Updated: 2018/01/29 11:26:08 by vchechai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char            *ft_base_str(long nb, int base, int len, int f)
{
    char        chr[16] = "0123456789abcdef";
    char        *res;

    res = (char*)malloc(sizeof(char) * (len + 1));
    res[len--] = '\0';
    if (f)
        res[0] = '-';
    while (nb > 0)
    {
        res[len--] = chr[nb % base];
        nb /= base;
    }
    return (res);
}

char            *ft_itoa_base(int i, int base)
{
    int         len;
    long        nb;
    long        x;
    int         f;

    nb = i;
    len = 0;
    f = 0;
    if (nb < 0 && base == 10)
    {
        len++;
        f++;
    }
    if (nb < 0)
        nb *= -1;
    x = nb;
    while (x > 0)
    {
        x /= base;
        len++;
    }
    return (ft_base_str(nb, base, len, f));
}
