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

int			set_width(const char *s, t_format *format)
{
	int		i;
	char	*sub;

	i = 0;
	while (ft_isdigit(s[i]))
		i++;
	sub = ft_strsub(s, 0, i);
	format->width = ft_atoi(sub);
	ft_strdel(&sub);
	return (i);
}

int			set_precision(const char *s, t_format *format)
{
	int		i;
	char	*sub;

	i = 0;
	s++;
	while (ft_isdigit(s[i]))
		i++;
	sub = ft_strsub(s, 0, i);
	format->precision = ft_atoi(sub);
	ft_strdel(&sub);
	return (i);
}

void		set_stuct(const char **s, t_format *format)
{
	int			i;

	i = 0;
	if (ft_isdigit(**s))
	{
		*s += set_width(*s, format);
		set_stuct(s, format);
	}
	else if (**s == '#' || **s == '-' || **s == '+' || **s == ' ' || **s == '0')
	{
		format->flag = **s;
		*s += 1;
		set_stuct(s, format);
	}
	else if (**s == '.')
	{
		*s += set_precision(*s, format);
		set_stuct(s, format);
	}
	else 
		format->variable = (char*)*s;
}

void			get_str(const char *s, char **str, va_list ap)
{
	int			i;
	t_format	*format;

	format = malloc(sizeof(t_format));
	i = 0;
	while (*s)
	{
		if(*s == '%')
		{
			s++;
			clear_struct(format);
			set_stuct(&s, format);
			s += set_arg(str, ap, format);
		}
        if (*s && *s != '%')
    		ft_chrjoin(str, *s);
		if (*s && *s != '%')
			s++;
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
