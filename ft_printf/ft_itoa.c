/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchechai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 15:41:47 by vchechai          #+#    #+#             */
/*   Updated: 2017/11/06 16:01:28 by vchechai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			num_size(long long n)
{
	int		len;

	len = 0;
	if (n == 0)
		len++;
	if (n < 0)
		n *= -1;
	while (n > 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static void		ft_to_str(long long n, long long i, t_format *format,
							 t_list **str)
{
	int 		len;

	len = num_size(n);
	if (format->plus && n >= 0 && !format->precision)
		len++;
	if (n < 0)
	{
		n *= -1;
		if (format->zero && !format->precision)
		len++;
	}
	while ((format->zero && len < format->width && !format->precision
		   && !format->minus) || len < format->precision)
	{
		ft_chrjoin(str, '0');
		len++;
	}
	while (i > 0)
	{
		ft_chrjoin(str, (n / i + '0'));
		n %= i;
		i /= 10;
	}
}

static void		ft_pre_str(long long n, t_format *format, t_list **str)
{
	int 		len;
	long long	i;

	len = num_size(n);
	i = ft_power(10, len -1);
	if (format->plus && n >= 0)
		ft_chrjoin(str, '+');
	if (format->space && !format->plus && !format->minus && n >= 0)
		ft_chrjoin(str, ' ');
	if (n < 0)
		ft_chrjoin(str, '-');
	ft_to_str(n, i, format, str);
}

void			ft_itoa(long long n, t_list **str, t_format *format)
{
	long long	len;

	len = num_size(n);
	if (format->precision > len)
		len = format->precision;
	if (n < 0)
		len++;
	if ((format->plus && n >= 0) || (format->space && !format->plus
									 && !format->minus && n >= 0))
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

