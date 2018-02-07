/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unitoa_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchechai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 15:26:03 by vchechai          #+#    #+#             */
/*   Updated: 2018/01/31 15:26:05 by vchechai         ###   ########.fr       */
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
	char				buf[17];
	int					len;
	unsigned long long	i;

	ft_strcpy(buf, "0123456789abcdef");
	len = num_size(n, base, format);
	i = ft_power(base, len - 1);
	if (format->hesh && n != 0)
	{
		len += (base == 16 && !format->precision) ? 2 : 0;
		len += (base == 8) ? 1 : 0;
	}
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
	if (format->hesh && n != 0)
	{
		ft_chrjoin(str, '0');
		if (base == 16)
			ft_chrjoin(str, 'x');
	}
	if (!(format->precision == -1 && n == 0))
		ft_to_str(n, base, format, str);
	if (format->precision == -1 && n == 0 && base == 8 && format->hesh)
		ft_to_str(n, base, format, str);
}

void		ft_unitoa_base(unsigned long long n, int base,
							t_list **str, t_format *format)
{
	long long	len;

	len = num_size(n, base, format);
	if (format->precision > len)
		len = format->precision;
	if (format->hesh && n != 0)
		len += (base == 16) ? 2 : 1;
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
