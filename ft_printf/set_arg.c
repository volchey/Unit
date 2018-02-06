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

void		get_arg(va_list ap, t_list **str, char c, t_format *format)
{
	if (c == 'd' || c == 'i')
		ft_itoa(va_arg(ap, int), str, format);
    else if (c == 'o')
        ft_unitoa_base(va_arg(ap, unsigned int), 8, str, format);
    else if (c == 'u')
        ft_unitoa_base(va_arg(ap, unsigned int), 10 , str, format);
    else if (c == 'x')
        ft_unitoa_base(va_arg(ap, unsigned int), 16, str, format);
	else if (c == 's')
		ft_set_str(va_arg(ap, char*), str, format);
	else if (c == 'c')
		ft_set_chr((char)va_arg(ap, int), str, format);
	else if (c == 'p')
		ft_get_address(va_arg(ap, unsigned long), str, format);
	else if (c == 'X')
		ft_unitoa_uppbase(va_arg(ap, unsigned int), 16, str, format);
	else if (c == 'C')
		ft_unichr(va_arg(ap, unsigned int), str);
	else if (c == 'S')
		ft_unistr((int*)va_arg(ap, unsigned int*), str, format);
	else if (c == '%')
		ft_set_chr('%', str, format);
	else
		ft_set_chr(c, str, format);
}

void	clear_struct(t_format *format)
{
	format->width = 0;
	format->minus = 0;
	format->plus = 0;
	format->space = 0;
	format->hesh = 0;
	format->zero = 0;
	format->precision = 0;
	format->variable = NULL;
}

int		ft_put_del_lst(t_list **head)
{
	int size;

	size = 0;
	while (*head)
	{
		write(1, (*head)->content, (*head)->content_size);
		size += (*head)->content_size;
		free((*head)->content);
		free(*head);
		(*head) = (*head)->next;
	}
	return (size);
}

int			set_arg(t_list **str, va_list ap, t_format *format)
{
    int		length;
	char	c;

	c = *(format->variable);
    length = 1;
	if (c == 'D')
		ft_itoa(va_arg(ap, long), str, format);
	else if (c == 'O')
		ft_unitoa_base(va_arg(ap, unsigned long), 8, str, format);
	else if (c == 'U')
		ft_unitoa_base(va_arg(ap, unsigned long), 10, str, format);
	else if (c == 'l' || c == 'h' || c == 'j' || c == 'z')
		get_farg(ap, format, str, &length);
	else
    	get_arg(ap, str, c, format);
    return (length);
}
