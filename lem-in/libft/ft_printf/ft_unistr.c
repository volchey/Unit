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

#include "../libft.h"

static int	ft_num_size(int num)
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

static int	ft_get_len(int *ptr, t_format *f)
{
	int i;
	int size;
	int len;

	if (!ptr)
		return (0);
	i = -1;
	len = 0;
	while (ptr[++i])
	{
		size = ft_num_size(ptr[i]);
		if ((size < 8) && (!f->precision || len + 1 <= f->precision))
			len += 1;
		else if (size < 12 && (!f->precision || len + 2 <= f->precision))
			len += 2;
		else if (size < 17 && (!f->precision || len + 3 <= f->precision))
			len += 3;
		else if (!f->precision || len + 4 <= f->precision)
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
	if (f->precision != -1)
	{
		while (s1 && s1[i])
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
			if (!f->precision || len <= f->precision)
				ft_unichr(s1[i], str);
			i++;
		}
	}
}

void		ft_unistr(int *s1, t_list **str, t_format *f)
{
	int		len;
	char	c;

	len = ft_get_len(s1, f);
	if (!s1)
		ft_set_str(0, str, f);
	len = (f->precision == -1) ? 0 : len;
	if (f->width > len && s1)
	{
		c = f->zero ? '0' : ' ';
		if (f->minus)
			put_str(s1, str, f);
		while (len < f->width)
		{
			ft_chrjoin(str, c);
			len++;
		}
		if (!f->minus)
			put_str(s1, str, f);
	}
	else if (s1)
		put_str(s1, str, f);
}
