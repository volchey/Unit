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

char		*get_arg(const char *s, va_list ap, int i)
{
	char	*arg;

	if (s[i] == 'd' || s[i] == 'i')
		arg = ft_itoa(va_arg(ap, int));
	if (s[i] == 's')
		arg = ft_strdup(va_arg(ap, char*));
	if (s[i] == 'c')
		arg = ft_chr_to_str(va_arg(ap, int));
	if (s[i] == 'p')
		arg = ft_hex_itoa(va_arg(ap, long int));
	if (s[i] == 'u')
		arg = ft_unitoa(va_arg(ap, unsigned int));
	return (arg);
}

void		set_arg(const char *s, char **str, va_list ap, int *i)
{
	char	*arg;
    char    *buf;

	(*i)++;
    arg = get_arg(s, ap, *i);
	(*i)++;
    buf = *str;
	*str = ft_strjoin(*str, arg);
    ft_strdel(&buf);
    ft_strdel(&arg);
}
