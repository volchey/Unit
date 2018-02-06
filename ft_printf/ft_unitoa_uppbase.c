/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unitoa_uppbase.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchechai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 19:51:44 by vchechai          #+#    #+#             */
/*   Updated: 2018/01/31 19:51:46 by vchechai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	num_size(unsigned long long n, int base, t_format *format)
{
	int					len;

	len = 0;
	if (n == 0 && format->precision != -1)
		len++;
	while (n > 0)
	{
		n /= base;
		len++;
	}
	return (len);
}

static void	ft_to_str(unsigned long long n, int base, t_format *format,
						 t_list **str)
{
	char				buf[17] = "0123456789ABCDEF";
	int					len;
	unsigned long long	i;

	len = num_size(n, base, format);
	i = ft_power(base, len - 1);
	if (format->plus && !format->precision)
		len++;
	if (format->hesh && n != 0)
		len += (base == 16) ? 2 : 0;
	while ((format->zero && len < format->width && !format->precision
			&& !format->minus) || len < format->precision)
	{
		ft_chrjoin(str, '0');
		len++;
	}
	while (i > 0)
	{
		ft_chrjoin(str, buf[n / i]);
		n %= i;
		i /= base;
	}
}

static void	ft_pre_str(unsigned long long n, int base, t_format *format,
						  t_list **str)
{
	if (format->plus)
		ft_chrjoin(str, '+');
	if (format->space && !format->plus && !format->minus)
		ft_chrjoin(str, ' ');
	if (format->hesh && n != 0)
	{
		ft_chrjoin(str, '0');
		if (base == 16)
			ft_chrjoin(str, 'X');
	}
	if (!(format->precision == -1 && n == 0))
		ft_to_str(n, base, format, str);
}

void		ft_unitoa_uppbase(unsigned long long n, int base,
						   t_list **str, t_format *format)
{
	long long	len;

	len = num_size(n, base, format);
	if (format->precision > len)
		len = format->precision;
	if (format->hesh && n != 0)
		len += (base == 16) ? 2 : 1;
	if (format->plus || (format->space && !format->plus && !format->minus))
		len++;
	if (format->width)
	{
		if (format->zero && !format->precision && !format->minus)
			len = format->width;
		if (format->minus)
			ft_pre_str(n, base, format, str);
		while (len < format->width)
		{
			ft_chrjoin(str, ' ');
			len++;
		}
		if (!format->minus)
			ft_pre_str(n, base, format, str);
	}
	else
		ft_pre_str(n, base, format, str);
}
