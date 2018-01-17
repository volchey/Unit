/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchechai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 17:01:23 by vchechai          #+#    #+#             */
/*   Updated: 2018/01/11 17:51:35 by vchechai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		get_str(const char *s, char **str, va_list ap)
{
	int		i;

	i = 0;
	while (s[i])
	{
		if(s[i] == '%')
		{
//			get_flag(s, &i);
//			get_width(s, &i);
//			get_precision(s, &i);
			set_arg(s, str, ap, &i);
		}
        if (s[i])
    		ft_chrjoin(str, s[i]);
		if (s[i])
			i++;
	}
}

int		ft_printf(const char *restrict format, ...)
{
	va_list ap;
	char	*str;
	int		size;

	str = ft_strnew(0);
    *str = '\0';
	va_start(ap, format);
	get_str(format, &str, ap);
	va_end(ap);
	ft_putstr(str);
	size = ft_strlen(str);
    ft_strdel(&str);
	return (size);
}
