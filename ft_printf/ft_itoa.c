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

static int	num_size(long long n, t_format *format)
{
	int					len;
	unsigned long long	un;

	len = 0;
	if (n == 0 && format->precision != -1)
		len++;
	if (n < 0)
		n *= -1;
	un = n;
	while (un > 0)
	{
		un /= 10;
		len++;
	}
	return (len);
}

static void	ft_to_str(long long n, long long i, t_format *f,
						t_list **str)
{
	int					len;
	unsigned long long	un;

	len = num_size(n, f);
	len += (f->plus && n >= 0 && !f->precision) ? 1 : 0;
	len += f->space && !f->plus && !f->minus && n == 0 ? 1 : 0;
	if (n < 0)
	{
		n *= -1;
		if (f->zero && !f->precision)
			len++;
	}
	un = n;
	while ((f->zero && len < f->width && !f->precision
			&& !f->minus) || len < f->precision)
	{
		ft_chrjoin(str, '0');
		len++;
	}
	while (i > 0)
	{
		ft_chrjoin(str, (un / i + '0'));
		un %= i;
		i /= 10;
	}
}

static void	ft_pre_str(long long n, t_format *format, t_list **str)
{
	int			len;
	long long	i;

	len = num_size(n, format);
	i = ft_power(10, len - 1);
	if (format->plus && n >= 0)
		ft_chrjoin(str, '+');
	if (format->space && !format->plus && !format->minus && n >= 0)
		ft_chrjoin(str, ' ');
	if (n < 0)
		ft_chrjoin(str, '-');
	if (!(format->precision == -1 && n == 0))
		ft_to_str(n, i, format, str);
}

void		ft_itoa(long long n, t_list **str, t_format *format)
{
	long long	len;

	len = num_size(n, format);
	if (format->precision > len)
		len = format->precision;
	len += (n < 0) ? 1 : 0;
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
