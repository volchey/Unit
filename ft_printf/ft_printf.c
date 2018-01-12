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

void 		ft_chrjoin(char **str, char c)
{
	int 	size;
	char	*buf;

	size = ft_strlen(*str);
	buf = (char*)malloc(sizeof(char) * size + 1);
	buf = ft_strcpy(buf, *str);
	buf[size] = c;
	buf[size + 1] = '\0';
//	ft_strdel(&str);
	*str = ft_strcpy(*str, buf);
	ft_strdel(&buf);
}

void		get_str(const char *s, char **str, va_list ap)
{
	int		i;

	i = 0;
	while (s[i])
	{
		if(s[i] == '%' && s[i + 1] == 'd')
			set_integer(str, va_arg(ap, int), &i);
		if(s[i] == '%' && s[i + 1] == 'c')
			set_chr(str, va_arg(ap, int), &i);
		ft_chrjoin(str, s[i]);
		if (s[i])
			i++;
	}
}

int		ft_printf(const char *restrict format, ...)
{
	va_list ap;
	char	*str;

	str = ft_strnew(0);
	va_start(ap, format);
	get_str(format, &str, ap);
	va_end(ap);
	ft_putstr(str);
	return (1);
}
