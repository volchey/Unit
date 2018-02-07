/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_farg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchechai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 12:03:10 by vchechai          #+#    #+#             */
/*   Updated: 2018/02/07 12:03:12 by vchechai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		get_uppc3(va_list ap, char c1, t_format *format, t_list **str)
{
	char	c2;

	c2 = (format->variable)[2];
	if (c1 == 'h' && c2 == 'D')
		ft_itoa((unsigned short int)va_arg(ap, unsigned int), str, format);
	else if (c1 == 'h' && c2 == 'U')
		ft_unitoa_base((unsigned short)va_arg(ap, unsigned), 10, str, format);
	else if (c1 == 'h' && c2 == 'O')
		ft_unitoa_base((unsigned short)va_arg(ap, unsigned), 8, str, format);
	else if (c1 == 'h' && c2 == 'C')
		ft_unichr(va_arg(ap, unsigned int), str);
	else if (c1 == 'h' && c2 == 'S')
		ft_unistr(va_arg(ap, int*), str, format);
	else if (c1 == 'l' && c2 == 'O')
		ft_unitoa_base((unsigned short)va_arg(ap, int), 8, str, format);
	else if (c1 == 'l' && (c2 == 'U' || c2 == 'D'))
		ft_unitoa_base((unsigned short)va_arg(ap, int), 10, str, format);
}

void		get_c3(va_list ap, char c1, t_format *format, t_list **str)
{
	char	c2;

	c2 = (format->variable)[2];
	if (c1 == 'h' && (c2 == 'd' || c2 == 'i'))
		ft_itoa((signed char)va_arg(ap, int), str, format);
	else if (c1 == 'h' && c2 == 'u')
		ft_unitoa_base((unsigned char)va_arg(ap, int), 10, str, format);
	else if (c1 == 'h' && c2 == 'o')
		ft_unitoa_base((unsigned char)va_arg(ap, int), 8, str, format);
	else if (c1 == 'h' && c2 == 'x')
		ft_unitoa_base((unsigned char)va_arg(ap, int), 16, str, format);
	else if (c1 == 'h' && c2 == 'X')
		ft_unitoa_uppbase((unsigned char)va_arg(ap, int), 16, str, format);
	else if (c1 == 'l' && (c2 == 'd' || c2 == 'i'))
		ft_itoa(va_arg(ap, long long), str, format);
	else if (c1 == 'l' && c2 == 'u')
		ft_unitoa_base(va_arg(ap, unsigned long long), 10, str, format);
	else if (c1 == 'l' && c2 == 'o')
		ft_unitoa_base(va_arg(ap, unsigned long long), 8, str, format);
	else if (c1 == 'l' && c2 == 'x')
		ft_unitoa_base(va_arg(ap, unsigned long long), 16, str, format);
	else if (c1 == 'l' && c2 == 'X')
		ft_unitoa_uppbase(va_arg(ap, unsigned long long), 16, str, format);
}

void		get_c2(va_list ap, char c1, t_format *f, t_list **str)
{
	char	c2;

	c2 = (f->variable)[1];
	if (c1 == 'h' && (c2 == 'd' || c2 == 'i'))
		ft_itoa((short int)va_arg(ap, int), str, f);
	else if (c1 == 'h' && (c2 == 'u' || c2 == 'D'))
		ft_unitoa_base((unsigned short)va_arg(ap, unsigned), 10, str, f);
	else if (c1 == 'h' && c2 == 'U')
		ft_unitoa_base(va_arg(ap, unsigned long), 10, str, f);
	else if (c1 == 'h' && (c2 == 'o' || c2 == 'O'))
		ft_unitoa_base((unsigned short)va_arg(ap, unsigned), 8, str, f);
	else if (c1 == 'h' && c2 == 'x')
		ft_unitoa_base((unsigned short)va_arg(ap, unsigned), 16, str, f);
	else if (c1 == 'h' && c2 == 'X')
		ft_unitoa_uppbase((unsigned short)va_arg(ap, unsigned), 16, str, f);
	else if (c1 == 'l' && c2 == 'x')
		ft_unitoa_base(va_arg(ap, unsigned long int), 16, str, f);
	else if (c1 == 'l' && c2 == 'X')
		ft_unitoa_uppbase(va_arg(ap, unsigned long int), 16, str, f);
	else if (c1 == 'l' && c2 == 'c')
		ft_unichr(va_arg(ap, unsigned int), str);
	else if (c1 == 'l' && c2 == 's')
		ft_unistr(va_arg(ap, int*), str, f);
	else if (c1 == 'l' && c2 == 'p')
		ft_get_address(va_arg(ap, unsigned long), str, f);
}

void		get_c1(va_list ap, char c1, t_format *format, t_list **str)
{
	char	c2;

	c2 = (format->variable)[1];
	if (c1 == 'z' && (c2 == 'd' || c2 == 'i' || c2 == 'D'))
		ft_itoa(va_arg(ap, size_t), str, format);
	else if (c1 == 'z' && (c2 == 'u' || c2 == 'U'))
		ft_unitoa_base(va_arg(ap, size_t), 10, str, format);
	else if (c1 == 'z' && (c2 == 'o' || c2 == 'O'))
		ft_unitoa_base(va_arg(ap, size_t), 8, str, format);
	else if (c1 == 'z' && c2 == 'x')
		ft_unitoa_base(va_arg(ap, size_t), 16, str, format);
	else if (c1 == 'z' && c2 == 'X')
		ft_unitoa_uppbase(va_arg(ap, size_t), 16, str, format);
	else if (c1 == 'j' && (c2 == 'd' || c2 == 'i' || c2 == 'D'))
		ft_itoa(va_arg(ap, intmax_t), str, format);
	else if (c1 == 'j' && (c2 == 'u' || c2 == 'U'))
		ft_unitoa_base(va_arg(ap, uintmax_t), 10, str, format);
	else if (c1 == 'j' && (c2 == 'o' || c2 == 'O'))
		ft_unitoa_base(va_arg(ap, uintmax_t), 8, str, format);
	else if (c1 == 'j' && c2 == 'x')
		ft_unitoa_base(va_arg(ap, uintmax_t), 16, str, format);
	else if (c1 == 'j' && c2 == 'X')
		ft_unitoa_uppbase(va_arg(ap, uintmax_t), 16, str, format);
}

void		get_farg(va_list ap, t_format *f, t_list **str, int *len)
{
	char	c2;

	c2 = (f->variable)[1];
	if ((c2 == 'l' || c2 == 'h') && ((f->variable)[0] == c2))
	{
		*len += 2;
		if (ft_isupper((f->variable)[2]) && (f->variable)[2] != 'X')
			get_uppc3(ap, c2, f, str);
		else
			get_c3(ap, c2, f, str);
	}
	else
	{
		(*len)++;
		if ((f->variable)[0] == 'l' && (c2 == 'd' || c2 == 'i' || c2 == 'D'))
			ft_itoa(va_arg(ap, long int), str, f);
		else if ((f->variable)[0] == 'l' && (c2 == 'u' || c2 == 'U'))
			ft_unitoa_base(va_arg(ap, unsigned long int), 10, str, f);
		else if ((f->variable)[0] == 'l' && (c2 == 'o' || c2 == 'O'))
			ft_unitoa_base(va_arg(ap, unsigned long int), 8, str, f);
		else if ((f->variable)[0] == 'z' || (f->variable)[0] == 'j')
			get_c1(ap, (f->variable)[0], f, str);
		else
			get_c2(ap, (f->variable)[0], f, str);
	}
}
