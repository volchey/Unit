/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_GetFlagArg.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchechai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 15:36:22 by vchechai          #+#    #+#             */
/*   Updated: 2018/01/29 15:36:26 by vchechai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char        *get_fllhharg(va_list ap, char c1, char c2, char c3)
{
    char    *arg;

    arg = NULL;
    if (c1 == 'h' && c2 == 'h')
    {
        if (c3 == 'o')
            arg = ft_oct_itoa((unsigned char)va_arg(ap, int));
        if (c3 == 'u')
            arg = ft_unitoa((unsigned char)va_arg(ap, int));
        if (c3 == 'x')
            arg = ft_hex_itoa((unsigned char)va_arg(ap, int));
        if (c3 == 'X')
            arg = ft_upphex_itoa((unsigned char)va_arg(ap, int));
    }
    if (c1 == 'l' && c2 == 'l')
    {
        if (c3 == 'o')
            arg = ft_oct_unlltoa(va_arg(ap, unsigned long long));
        if (c3 == 'u')
            arg = ft_unlltoa(va_arg(ap, unsigned long long));
        if (c3 == 'x')
            arg = ft_hex_unlltoa(va_arg(ap, unsigned long long));
        if (c3 == 'X')
            arg = ft_upphex_unlltoa(va_arg(ap, unsigned long long));
    }
    return (arg);
}

char        *get_flharg(va_list ap, char c1, char c2)
{
    char    *arg;

    arg = NULL;
    if (c1 == 'h')
    {
        if (c2 == 'o')
            arg = ft_oct_itoa((unsigned short int)va_arg(ap, int));
        if (c2 == 'u')
            arg = ft_unitoa((unsigned short int)va_arg(ap, int));
        if (c2 == 'x')
            arg = ft_hex_itoa((unsigned short int)va_arg(ap, int));
        if (c2 == 'X')
            arg = ft_upphex_itoa((unsigned short int)va_arg(ap, int));
    }
    if (c1 == 'l')
    {
        if (c2 == 'o')
            arg = ft_oct_itoa((unsigned long int)va_arg(ap, long long));
        if (c2 == 'u')
            arg = ft_unitoa((unsigned long int)va_arg(ap, long long));
        if (c2 == 'x')
            arg = ft_hex_itoa((unsigned long int)va_arg(ap, long long));
        if (c2 == 'X')
            arg = ft_upphex_itoa((unsigned long int)va_arg(ap, long long));
    }
    return (arg);
}

char        *get_farg2(va_list ap, char c1, char c2, char c3)
{
    char    *arg;
    int     i;
    char    str[4] = "uoxX";

    i = 0;
    arg = NULL;
    while (str[i] && str[i] != c2 && str[i] != c3)
        i++;
    if (str[i] == c2)
        arg = get_flharg(ap, c1, c2);
    else if (str[i] == c3)
        arg = get_fllhharg(ap, c1, c2, c3);
    else if (c1 == 'j' && (c2 == 'd' || c2 == 'i'))
        arg = ft_lltoa(va_arg(ap, intmax_t));
    else if (c1 == 'z' && (c2 == 'd' || c2 == 'i'))
        arg = ft_lltoa(va_arg(ap, size_t));
    return (arg);
}

char		*get_farg(va_list ap, t_format *format, int *length)
{
    char	*arg;
    char	c1;
    char	c2;
    char	c3;

    c1 = (format->variable)[0];
    c2 = (format->variable)[1];
    c3 = (format->variable)[2];
    arg = NULL;
    if (c2 == 'l' || c2 == 'h')
        *length = 3;
    else
        *length = 2;
    if (c1 == 'l' && c2 == 'l' && (c3 == 'd' || c3 == 'i'))
        arg = ft_lltoa(va_arg(ap, long long));
    else if (c1 == 'l' && (c2 == 'd' || c2 == 'i'))
        arg = ft_lltoa(va_arg(ap, long));
//    else if (c1 == 'h' && (c2 == 'd' || c2 == 'i'))
//        arg = ft_itoa((short int)va_arg(ap, int));
//    else if (c1 == 'h' && c2 == 'h' && (c3 == 'd' || c3 == 'i'))
//        arg = ft_itoa((signed char)va_arg(ap, int));
    else
        arg = get_farg2(ap, c1, c2, c3);
    if (!arg && ft_isalpha(c2))
        arg = ft_chr_to_str(c2);
    return (arg);
}
