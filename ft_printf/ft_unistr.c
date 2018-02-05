/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unistr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchechai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/20 13:21:27 by vchechai          #+#    #+#             */
/*   Updated: 2018/01/20 13:47:48 by vchechai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int 	ft_num_size(int num)
{
	int i;

	i = 0;
	while (num)
	{
		num /= 2;
		i++;
	}
	return (i);
}

int 	ft_arrlen(int *ptr)
{
	int i;
	int size;
	int len;

	i = -1;
	len = 0;
	while (ptr[++i])
	{
		size = ft_num_size(ptr[i]);
		if (size < 8)
			len += 1;
		else if (size < 12)
			len += 2;
		else if (size < 17)
			len += 3;
		else
			len += 4;
	}
	return (len);
}

static void	put_str(int *s1, t_list **str, t_format *f)
{
	int	i;
	int size;
	int len;

	i = 0;
	len = 0;
	if (f->space && !f->minus)
		ft_chrjoin(str, ' ');
	while (s1[i])
	{
		size = ft_num_size(s1[i]);
		if (size < 8)
			len += 1;
		else if (size < 12)
			len += 2;
		else if (size < 17)
			len += 3;
		else
			len += 4;
		ft_unichr(s1[i], str);
		i++;
		if (len == f->precision)
			break ;
	}
}

void	ft_unistr(int *s1, t_list **str, t_format *f)
{
	int		len;
	int 	arr[7] = {'(', 'n', 'u', 'l', 'l', ')'};

	if (!s1)
		s1 = arr;
	len = ft_arrlen(s1);
	if(f->precision && f->precision != -1 && len > f->precision)
		len = f->precision;
	if(f->width > len)
	{
		if(f->minus)
			put_str(s1, str, f);
		while(len < f->width)
		{
			ft_chrjoin(str, ' ');
			len++;
		}
		if(!f->minus)
			put_str(s1, str, f);
	} else
		put_str(s1, str, f);
}
