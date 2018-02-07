/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_address.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchechai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 20:16:22 by vchechai          #+#    #+#             */
/*   Updated: 2018/01/15 20:20:36 by vchechai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	num_size(unsigned long long n, t_format *format)
{
	int					len;

	len = 0;
	if (n == 0 && format->precision != -1)
		len++;
	while (n > 0)
	{
		n /= 16;
		len++;
	}
	return (len);
}

static void	ft_to_str(unsigned long long n, t_format *format,
						t_list **str)
{
	char				buf[17];
	int					len;
	unsigned long long	i;

	ft_strcpy(buf, "0123456789abcdef");
	len = num_size(n, format);
	i = ft_power(16, len - 1);
	len += !format->precision ? 2 : 0;
	if (format->plus && !format->precision)
		len++;
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
		i /= 16;
	}
}

static void	ft_pre_str(unsigned long long n, t_format *format,
						t_list **str)
{
	ft_chrjoin(str, '0');
	ft_chrjoin(str, 'x');
	if (!(format->precision == -1 && n == 0))
		ft_to_str(n, format, str);
}

void		ft_get_address(unsigned long long n, t_list **str, t_format *format)
{
	long long	len;

	len = num_size(n, format) + 2;
	if (format->precision > len)
		len = format->precision;
	if (format->plus || (format->space && !format->plus && !format->minus))
		len++;
	if (format->width)
	{
		if (format->zero && !format->precision && !format->minus)
			len = format->width;
		if (format->minus)
			ft_pre_str(n, format, str);
		while (len < format->width)
		{
			ft_chrjoin(str, ' ');
			len++;
		}
		if (!format->minus)
			ft_pre_str(n, format, str);
	}
	else
		ft_pre_str(n, format, str);
}
