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

#include "../libft.h"

int				set_width(const char *s, t_format *format, va_list ap)
{
	int			i;
	int			x;
	char		*sub;

	i = 0;
	if (*s == '*' && !format->width)
	{
		x = va_arg(ap, int);
		format->width = x < 0 ? (x * -1) : x;
		format->minus = (x < 0 || format->minus) ? 1 : 0;
		return (1);
	}
	while (ft_isdigit(s[i]))
		i++;
	sub = ft_strsub(s, 0, i);
	format->width = ft_atoi(sub);
	ft_strdel(&sub);
	return (i);
}

int				set_precision(const char *s, t_format *format, va_list ap)
{
	int			i;
	int			x;
	char		*sub;

	i = 0;
	s++;
	if (*s == '*')
	{
		x = va_arg(ap, int);
		x = x == 0 ? -1 : x;
		format->precision = (x < 0 && x != -1) ? 0 : x;
		return (1);
	}
	if (!ft_isdigit(s[i]) || s[i] == '0')
	{
		format->precision = -1;
		return (0);
	}
	while (ft_isdigit(s[i]))
		i++;
	sub = ft_strsub(s, 0, i);
	format->precision = ft_atoi(sub);
	ft_strdel(&sub);
	return (i);
}

void			set_struct(const char **s, t_format *format, va_list ap)
{
	if ((ft_isdigit(**s) && **s != '0') || (**s == '*'))
	{
		*s += set_width(*s, format, ap);
		set_struct(s, format, ap);
	}
	else if (**s == '#' || **s == '-' || **s == '+' || **s == ' ' || **s == '0')
	{
		if (**s == '-')
			format->minus = 1;
		if (**s == '+')
			format->plus = 1;
		if (**s == ' ')
			format->space = 1;
		if (**s == '0')
			format->zero = 1;
		if (**s == '#')
			format->hesh = 1;
		*s += 1;
		set_struct(s, format, ap);
	}
	else if (**s == '.')
	{
		*s += set_precision(*s, format, ap) + 1;
		set_struct(s, format, ap);
	}
}

void			get_str(const char *s, t_list **str, va_list ap)
{
	t_format	*format;

	format = malloc(sizeof(t_format));
	while (*s)
	{
		if (*s == '%')
		{
			s++;
			if (*s)
			{
				clear_struct(format);
				set_struct(&s, format, ap);
				format->variable = s;
				s += set_arg(str, ap, format);
			}
		}
		if (str && *s && (*s != '%'))
			ft_chrjoin(str, *s);
		if (*s && *s != '%')
			s++;
	}
	free(format);
}

int				ft_printf(const char *restrict format, ...)
{
	va_list		ap;
	t_list		*str;
	t_list		*head;
	int			size;

	str = ft_lstnew("", BUFF_SIZE_PF);
	str->content_size = 0;
	head = str;
	va_start(ap, format);
	get_str(format, &str, ap);
	va_end(ap);
	size = ft_put_del_lst(&head);
	return (size);
}
