/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unichar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchechai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 15:49:28 by vchechai          #+#    #+#             */
/*   Updated: 2017/11/06 15:51:35 by vchechai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void			set_2_bytes(unsigned int value, t_list **str)
{
	unsigned int	mask1;

	mask1 = 49280;
	ft_chrjoin(str, (((value >> 6) << 27) >> 27) | (mask1 >> 8));
	ft_chrjoin(str, ((value << 26) >> 26) | ((mask1 << 24) >> 24));
}

static void			set_3_bytes(unsigned int value, t_list **str)
{
	unsigned int	mask2;

	mask2 = 14712960;
	ft_chrjoin(str, (((value >> 12) << 28) >> 28) | (mask2 >> 16));
	ft_chrjoin(str, (((value >> 6) << 26) >> 26) | ((mask2 << 16) >> 24));
	ft_chrjoin(str, ((value << 26) >> 26) | ((mask2 << 24) >> 24));
}

static void			set_4_bytes(unsigned int value, t_list **str)
{
	unsigned int	mask3;

	mask3 = 4034953344;
	ft_chrjoin(str, (((value >> 18) << 29) >> 29) | (mask3 >> 24));
	ft_chrjoin(str, (((value >> 12) << 26) >> 26 | ((mask3 << 8) >> 24)));
	ft_chrjoin(str, ((value >> 6) << 26) >> 26 | ((mask3 << 16) >> 24));
	ft_chrjoin(str, ((value << 26) >> 26) | ((mask3 << 24) >> 24));
}

void				ft_unichr(unsigned int value, t_list **str)
{
	int				size;
	unsigned int	i;

	size = 0;
	i = value;
	while (i > 0)
	{
		i /= 2;
		size++;
	}
	if (size < 8)
		ft_chrjoin(str,value);
	else if (size < 12)
		set_2_bytes(value, str);
	else if (size < 17)
		set_3_bytes(value, str);
	else
		set_4_bytes(value, str);
}
