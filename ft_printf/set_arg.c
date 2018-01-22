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

char		*get_farg(va_list ap, t_format *format)
{
	char	*arg;
	char	c1;
	char	c2;
	char	c3;

	c1 = (format->variable)[0];
	c2 = (format->variable)[1];
	c3 = (format->variable)[2];
	arg = NULL;
	if (c1 == 'l' && c2 == 'l' && c3 == 'd')
		arg = ft_lltoa(va_arg(ap, long));
	return (arg);
}

char		*get_arg2(va_list ap, t_format *format, char c)
{
 	char	*arg;

 	arg = NULL;
	if (c == 'X')
		arg = ft_upphex_itoa(va_arg(ap, unsigned long int));
	else if (c == 'C')
		arg = (char*)ft_unichar(va_arg(ap, unsigned int));
	else if (c == 'S')
		arg = ft_unistr(va_arg(ap, int*));
	else if (c == 'l' || c == 'h' || c == 'j' || c == 'z')
		arg = get_farg(ap, format);
 	return (arg);
}

char			*get_arg(va_list ap, t_format *format)
{
	char		*arg;
	char		c;

	c = *(format->variable);
	arg = NULL;
	if (c == 'd' || c == 'i')
		arg = ft_itoa(va_arg(ap, int));
	else if (c == 's')
		arg = ft_strdup(va_arg(ap, char*));
	else if (c == 'c')
		arg = ft_chr_to_str(va_arg(ap, int));
	else if (c == 'p')
		arg = ft_get_address(va_arg(ap, long int));
	else if (c == 'u')
		arg = ft_unitoa(va_arg(ap, unsigned int));
	else if (c == 'o')
		arg = ft_oct_itoa(va_arg(ap, int));
	else if (c == 'x')
		arg = ft_hex_itoa(va_arg(ap, unsigned long int));
	else
		arg = get_arg2(ap, format, c);
	return (arg);
}

void	clear_struct(t_format *format)
{
	format->width = 0;
	format->flag = 'o';
	format->precision = 0;
	format->variable = NULL;
}

int		set_arg(char **str, va_list ap, t_format *format)
{
	char		*arg;
    char    	*buf;

    arg = get_arg(ap, format);
    buf = *str;
	*str = ft_strjoin(*str, arg);
    ft_strdel(&buf);
    ft_strdel(&arg);
    return (1);
}
