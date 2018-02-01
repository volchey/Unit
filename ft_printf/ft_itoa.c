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

int		num_size(long long n, t_format *format)
{
	int len;

	len = 0;
	if (format->flag == '+' || format->flag == ' ')
		len++;
	if (n < 0)
		len++;
	while (n > 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static void		ft_to_str(long long n, long long i, int f, t_list **str)
{
	if (f)
		ft_chrjoin(str, '-');
	while (i > 0)
	{
		ft_chrjoin(str, (n / i + '0'));
		n %= i;
		i /= 10;
	}
}

void		set_width(long long n, t_format *format, int f, t_list **str)
{
	int 	len;
	char 	c;

	c = ' ';
	len = num_size(n, format);
	if (format->width)
	{
		if (format->flag == '0')
			c = '0';
		if (format->flag == '-')
			ft_to_str(n, ft_power(len, 10), f, str);
		while (len < format->width)
		{
			ft_chrjoin(str, c);
			len++;
		}
		if (format->flag != '0')
			ft_to_str(n, ft_power(len, 10), f, str);
	}
	else
		ft_to_str(n, ft_power(len, 10), f, str);
}

void			ft_itoa(long long n, t_list **str, t_format *format)
{
	long long	i;
	int			f;

	i = 1;
	f = 0;
	if (n < 0)
	{
		f = 1;
		n *= -1;
	}
	while (n / i > 9)
		i *= 10;
	set_width(n, format, f, str);
}

