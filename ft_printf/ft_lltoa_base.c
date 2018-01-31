/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lltoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchechai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/27 11:55:46 by vchechai          #+#    #+#             */
/*   Updated: 2018/01/27 11:55:48 by vchechai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char            *ft_base_str(unsigned long nb, int base, int len)
{
    char        chr[16] = "0123456789abcdef";
    char        *res;

    res = (char*)malloc(sizeof(char) * (len + 1));
    res[len--] = '\0';
    if (nb == 0)
        res[0] = '0';
    while (nb > 0)
    {
        res[len--] = chr[nb % base];
        nb /= base;
    }
    return (res);
}

char            *ft_lltoa_base(unsigned long nb, int base)
{
    int         len;
    unsigned long   x;

    len = 0;
    if (nb == 0)
        len++;
    x = nb;
    while (x > 0)
    {
        x /= base;
        len++;
    }
    return (ft_base_str(nb, base, len));
}
