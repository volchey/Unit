/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_arg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchechai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 15:18:39 by vchechai          #+#    #+#             */
/*   Updated: 2018/01/13 15:18:41 by vchechai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*get_arg(const char *s, va_list ap)
{
	char	*arg;

	arg = NULL;
	if (*s == 'd' || *s == 'i')
		arg = ft_itoa(va_arg(ap, int));
	else if (*s == 's')
		arg = ft_strdup(va_arg(ap, char*));
	else if (*s == 'c')
		arg = ft_chr_to_str(va_arg(ap, int));
	else if (*s == 'p')
		arg = ft_get_address(va_arg(ap, long int));
	else if (*s == 'u')
		arg = ft_unitoa(va_arg(ap, unsigned int));
	else if (*s == 'o')
		arg = ft_oct_itoa(va_arg(ap, int));
	else if (*s == 'x')
		arg = ft_hex_itoa(va_arg(ap, unsigned long int));
	else if (*s == 'X')
		arg = ft_upphex_itoa(va_arg(ap, unsigned long int));
	else if (*s == 'C')
		arg = (char*)ft_unichar(va_arg(ap, unsigned int));
	else if (*s == 'S')
		arg = ft_unistr(va_arg(ap, int*));
//	else
//		arg = get_arg2(s, ap);
	return (arg);
}

int		set_arg(const char *s, char **str, va_list ap)
{
	char	*arg;
    char    *buf;

    s++;
    arg = get_arg(s, ap);
	s++;
    buf = *str;
	*str = ft_strjoin(*str, arg);
    ft_strdel(&buf);
    ft_strdel(&arg);
    return (2);
}
