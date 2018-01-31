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

char		*get_arg2(va_list ap, char c)
{
 	char	*arg;

 	arg = NULL;
	if (c == 'X')
		arg = ft_upphex_itoa(va_arg(ap, unsigned int));
	else if (c == 'C')
		arg = (char*)ft_unichar(va_arg(ap, unsigned int));
	else if (c == 'S')
		arg = ft_unistr(va_arg(ap, int*));
	else if (c == '%')
		arg = ft_chr_to_str('%');
 	return (arg);
}

void		get_arg(va_list ap, t_format *format, t_list **str)
{
//	char		*arg;
	char	c;

	c = *(format->variable);
//	arg = NULL;
//     if (c == 'l' || c == 'h' || c == 'j' || c == 'z')
//        arg = get_farg(ap, format, length);
	if (c == 'd' || c == 'i')
		ft_itoa(va_arg(ap, int), str);
    else if (c == 'o')
        ft_unitoa_base(va_arg(ap, unsigned int), 8, str);
    else if (c == 'u')
        ft_unitoa_base(va_arg(ap, unsigned int), 10 , str);
    else if (c == 'x')
        ft_unitoa_base(va_arg(ap, unsigned int), 16, str);
	else if (c == 's')
		ft_set_str(va_arg(ap, char*), str);
	else if (c == 'c')
		ft_chrjoin(str, va_arg(ap, int));
	else if (c == 'p')
		ft_get_address(va_arg(ap, long int));
//	else
//		 get_arg2(ap, c);
}

void	clear_struct(t_format *format)
{
	format->width = 0;
	format->flag = 'o';
	format->precision = 0;
	format->variable = NULL;
}

int		set_arg(t_list **str, va_list ap, t_format *format)
{
    int         length;
    int         i;

    i = 0;
    length = 1;
    get_arg(ap, format, str);
    return (length);
}
